/* Copyright 2017 Jason Williams
 * Copyright 2018 Jack Humbert
 * Copyright 2018 Yiancar
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "is31fl3733-simple.h"
#include "i2c_master.h"
#include "wait.h"

// This is a 7-bit address, that gets left-shifted and bit 0
// set to 0 for write, 1 for read (as per I2C protocol)
// The address will vary depending on your wiring:
// 00 <-> GND
// 01 <-> SCL
// 10 <-> SDA
// 11 <-> VCC
// ADDR1 represents A1:A0 of the 7-bit address.
// ADDR2 represents A3:A2 of the 7-bit address.
// The result is: 0b101(ADDR2)(ADDR1)
#define ISSI_ADDR_DEFAULT 0x50

#define ISSI_COMMANDREGISTER 0xFD
#define ISSI_COMMANDREGISTER_WRITELOCK 0xFE
#define ISSI_INTERRUPTMASKREGISTER 0xF0
#define ISSI_INTERRUPTSTATUSREGISTER 0xF1

#define ISSI_PAGE_LEDCONTROL 0x00  // PG0
#define ISSI_PAGE_PWM 0x01         // PG1
#define ISSI_PAGE_AUTOBREATH 0x02  // PG2
#define ISSI_PAGE_FUNCTION 0x03    // PG3

#define ISSI_REG_CONFIGURATION 0x00  // PG3
#define ISSI_REG_GLOBALCURRENT 0x01  // PG3
#define ISSI_REG_RESET 0x11          // PG3
#define ISSI_REG_SWPULLUP 0x0F       // PG3
#define ISSI_REG_CSPULLUP 0x10       // PG3

#ifndef ISSI_TIMEOUT
#    define ISSI_TIMEOUT 100
#endif

#ifndef ISSI_PERSISTENCE
#    define ISSI_PERSISTENCE 0
#endif

// Transfer buffer for TWITransmitData()
uint8_t g_twi_transfer_buffer[20];

// These buffers match the IS31FL3733 PWM registers.
// The control buffers match the PG0 LED On/Off registers.
// Storing them like this is optimal for I2C transfers to the registers.
// We could optimize this and take out the unused registers from these
// buffers and the transfers in IS31FL3733_write_pwm_buffer() but it's
// probably not worth the extra complexity.
uint8_t g_pwm_buffer[LED_DRIVER_COUNT][192];
bool    g_pwm_buffer_update_required[LED_DRIVER_COUNT] = {false};

uint8_t g_led_control_registers[LED_DRIVER_COUNT][24]             = {{0}};
bool    g_led_control_registers_update_required[LED_DRIVER_COUNT] = {false};

bool IS31FL3733_write_register(uint8_t addr, uint8_t reg, uint8_t data) {
    // If the transaction fails function returns false.
    g_twi_transfer_buffer[0] = reg;
    g_twi_transfer_buffer[1] = data;

#if ISSI_PERSISTENCE > 0
    for (uint8_t i = 0; i < ISSI_PERSISTENCE; i++) {
        if (i2c_transmit(addr << 1, g_twi_transfer_buffer, 2, ISSI_TIMEOUT) != 0) {
            return false;
        }
    }
#else
    if (i2c_transmit(addr << 1, g_twi_transfer_buffer, 2, ISSI_TIMEOUT) != 0) {
        return false;
    }
#endif
    return true;
}

bool IS31FL3733_write_pwm_buffer(uint8_t addr, uint8_t *pwm_buffer) {
    // Assumes PG1 is already selected.
    // If any of the transactions fails function returns false.
    // Transmit PWM registers in 12 transfers of 16 bytes.
    // g_twi_transfer_buffer[] is 20 bytes

    // Iterate over the pwm_buffer contents at 16 byte intervals.
    for (int i = 0; i < 192; i += 16) {
        g_twi_transfer_buffer[0] = i;
        // Copy the data from i to i+15.
        // Device will auto-increment register for data after the first byte
        // Thus this sets registers 0x00-0x0F, 0x10-0x1F, etc. in one transfer.
        for (int j = 0; j < 16; j++) {
            g_twi_transfer_buffer[1 + j] = pwm_buffer[i + j];
        }

#if ISSI_PERSISTENCE > 0
        for (uint8_t i = 0; i < ISSI_PERSISTENCE; i++) {
            if (i2c_transmit(addr << 1, g_twi_transfer_buffer, 17, ISSI_TIMEOUT) != 0) {
                return false;
            }
        }
#else
        if (i2c_transmit(addr << 1, g_twi_transfer_buffer, 17, ISSI_TIMEOUT) != 0) {
            return false;
        }
#endif
    }
    return true;
}

extern bool g_initUnlock0;
extern bool g_initSelectPG0;
extern bool g_initTurnOffLeds;
extern bool g_initUnlock1;
extern bool g_initSelectPG1;
extern bool g_initTurnOnLeds;
extern bool g_initUnlock2;
extern bool g_initSelectPG3;
extern bool g_initSetGlogalCurrent;
extern bool g_initDisableSoftwareShutDown;

bool IS31FL3733_init(uint8_t addr, uint8_t sync) {
    // In order to avoid the LEDs being driven with garbage data
    // in the LED driver's PWM registers, shutdown is enabled last.
    // Set up the mode and other settings, clear the PWM registers,
    // then disable software shutdown.
    // Sync is passed so set it according to the datasheet.

    // Unlock the command register.
    if (IS31FL3733_write_register(addr, ISSI_COMMANDREGISTER_WRITELOCK, 0xC5) == false)
    {
        g_initUnlock0 = false;
        return false;
    }
    g_initUnlock0 = true;

    // Select PG0
    if (IS31FL3733_write_register(addr, ISSI_COMMANDREGISTER, ISSI_PAGE_LEDCONTROL) == false)
    {
        g_initSelectPG0 = false;
        return false;
    }
    g_initSelectPG0 = true;

    // Turn off all LEDs.
    for (int i = 0x00; i <= 0x17; i++) {
        if (IS31FL3733_write_register(addr, i, 0x00) == false)
        {
            g_initTurnOffLeds = false;
            return false;
        }
    }
    g_initTurnOffLeds = true;

    // Unlock the command register.
    if (IS31FL3733_write_register(addr, ISSI_COMMANDREGISTER_WRITELOCK, 0xC5) == false)
    {
        g_initUnlock1 = false;
        return false;
    }
    g_initUnlock1 = true;

    // Select PG1
    if (IS31FL3733_write_register(addr, ISSI_COMMANDREGISTER, ISSI_PAGE_PWM) == false)
    {
        g_initSelectPG1 = false;
        return false;
    }
    g_initSelectPG1 = true;

    // Set PWM on all LEDs to 0
    // No need to setup Breath registers to PWM as that is the default.
    for (int i = 0x00; i <= 0xBF; i++) {
        if (IS31FL3733_write_register(addr, i, 0x00) == false)
        {
            g_initTurnOnLeds = false;
            return false;
        }
    }
    g_initTurnOnLeds = true;

    // Unlock the command register.
    if (IS31FL3733_write_register(addr, ISSI_COMMANDREGISTER_WRITELOCK, 0xC5) == false)
    {
        g_initUnlock2 = false;
        return false;
    }
    g_initUnlock2 = true;

    // Select PG3
    if (IS31FL3733_write_register(addr, ISSI_COMMANDREGISTER, ISSI_PAGE_FUNCTION) == false)
    {
        g_initSelectPG3 = false;
        return false;
    }
    g_initSelectPG3 = true;

    // Set global current to maximum.
    if (IS31FL3733_write_register(addr, ISSI_REG_GLOBALCURRENT, 0xFF) == false)
    {
        g_initSetGlogalCurrent = false;
        return false;
    }
    g_initSetGlogalCurrent = true;

    // Disable software shutdown.
    if (IS31FL3733_write_register(addr, ISSI_REG_CONFIGURATION, (sync << 6) | 0x01) == false)
    {
        g_initDisableSoftwareShutDown = false;
        return false;
    }
    g_initDisableSoftwareShutDown = true;

    // Wait 10ms to ensure the device has woken up.
    wait_ms(10);

    return true;
}

void IS31FL3733_set_value(int index, uint8_t value) {
    if (index >= 0 && index < LED_DRIVER_LED_COUNT) {
        is31_led led = g_is31_leds[index];

        g_pwm_buffer[led.driver][led.v]          = value;
        g_pwm_buffer_update_required[led.driver] = true;
    }
}

void IS31FL3733_set_value_all(uint8_t value) {
    for (int i = 0; i < LED_DRIVER_LED_COUNT; i++) {
        IS31FL3733_set_value(i, value);
    }
}

void IS31FL3733_set_led_control_register(uint8_t index, bool value) {
    is31_led led = g_is31_leds[index];

    uint8_t control_register = led.v / 8;
    uint8_t bit_value        = led.v % 8;

    if (value) {
        g_led_control_registers[led.driver][control_register] |= (1 << bit_value);
    } else {
        g_led_control_registers[led.driver][control_register] &= ~(1 << bit_value);
    }

    g_led_control_registers_update_required[led.driver] = true;
}

bool IS31FL3733_update_pwm_buffers(uint8_t addr, uint8_t index) {
    if (g_pwm_buffer_update_required[index]) {
        // Firstly we need to unlock the command register and select PG1.
        if (IS31FL3733_write_register(addr, ISSI_COMMANDREGISTER_WRITELOCK, 0xC5) == false)
            return false;
        if (IS31FL3733_write_register(addr, ISSI_COMMANDREGISTER, ISSI_PAGE_PWM) == false)
            return false;

        // If any of the transactions fail we risk writing dirty PG0,
        // refresh page 0 just in case.
        if (!IS31FL3733_write_pwm_buffer(addr, g_pwm_buffer[index])) {
            g_led_control_registers_update_required[index] = true;
        }
    }
    g_pwm_buffer_update_required[index] = false;

    return true;
}

bool IS31FL3733_update_led_control_registers(uint8_t addr, uint8_t index) {
    if (g_led_control_registers_update_required[index]) {
        // Firstly we need to unlock the command register and select PG0
        if (IS31FL3733_write_register(addr, ISSI_COMMANDREGISTER_WRITELOCK, 0xC5) == false)
            return false;
        if (IS31FL3733_write_register(addr, ISSI_COMMANDREGISTER, ISSI_PAGE_LEDCONTROL) == false)
            return false;
        for (int i = 0; i < 24; i++) {
            if (IS31FL3733_write_register(addr, i, g_led_control_registers[index][i]) == false)
                return false;
        }
    }
    g_led_control_registers_update_required[index] = false;

    return true;
}
