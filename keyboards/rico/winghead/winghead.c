/*
Copyright 2019 Eric Becourt <eric.becourt@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#if MONO_BACKLIGHT_ENABLED

#include "wt_mono_backlight.h"
#include "is31fl3733-simple.h"
#include <print.h>

const is31_led g_is31_leds[LED_DRIVER_LED_COUNT] = {
/* Refer to IS31 manual for these locations
 *  driver
 *  |   LED address
 *  |   | */
    // 9
    {0, G_2},  // KC_GESC
    {0, G_3},  // KC_F2
    {0, G_1},  // KC_F4
    {0, G_4},  // KC_F6
    {0, G_5},  // KC_F8
    {0, G_7},  // KC_F10
    {0, G_8},  // KC_F12
    {0, G_9},  // KC_BRK
    {0, G_10}, // KC_PGDN
    // 9
    {0, L_2},  // KC_GRV
    {0, L_3},  // KC_2
    {0, L_1},  // KC_4
    {0, L_4},  // KC_6
    {0, L_5},  // KC_8
    {0, L_7},  // KC_O
    {0, L_8},  // KC_EQL
    {0, L_9},  // KC_PSLS
    {0, L_10}, // KC_PMNS
    // 10
    {0, F_2},  // KC_TAB
    {0, F_3},  // KC_W
    {0, F_1},  // KC_R
    {0, F_4},  // KC_Y
    {0, F_5},  // KC_I
    {0, F_7},  // KC_P
    {0, F_8},  // KC_RBRC
    {0, F_6},  // KC_BSLASH
    {0, F_9},  // KC_P8
    {0, F_10}, // KC_PPLS
    // 8
    {0, D_2},  // KC_CAPS
    {0, D_3},  // KC_S
    {0, D_1},  // KC_F
    {0, D_4},  // KC_H
    {0, D_5},  // KC_K
    {0, D_7},  // KC_SCOLON
    {0, D_8},  // KC_NUHS
    {0, D_9},  // KC_NO KC_P5
    // 9
    {0, C_2},  // KC_LSFT
    {0, C_3},  // KC_Z
    {0, C_1},  // KC_C
    {0, C_4},  // KC_B
    {0, C_5},  // KC_M
    {0, C_7},  // KC_DOT
    {0, C_8},  // KC_RSFT
    {0, C_9},  // KC_P2
    {0, C_10}, // KC_PENT
    // 7
    {0, B_2},  // KC_LCTL
    {0, B_3},  // KC_LALT
    {0, B_5},  // KC_RALT
    {0, B_7},  // KC_RCTL
    {0, B_8},  // KC_LEFT
    {0, B_6},  // KC_RGHT
    {0, B_9},  // KC_PDOT
    // 5
    {0, A_2},  // KC_LGUI
    {0, A_1},  // KC_SPC
    {0, A_5},  // KC_RGUI
    {0, A_8},  // KC_DOWN
    {0, A_6},  // KC_P0
    // 9
    {0, E_2},  // KC_NUBS
    {0, E_3},  // KC_X
    {0, E_1},  // KC_V
    {0, E_4},  // KC_N
    {0, E_5},  // KC_COMM
    {0, E_7},  // KC_SLSH
    {0, E_8},  // KC_UP
    {0, E_6},  // KC_P1
    {0, E_9},  // KC_P3
    // 9
    {0, K_2},  // KC_A
    {0, K_3},  // KC_D
    {0, K_1},  // KC_G
    {0, K_4},  // KC_J
    {0, K_5},  // KC_L
    {0, K_7},  // KC_QUOT
    {0, K_8},  // KC_ENT
    {0, K_6},  // KC_P4
    {0, K_9},  // KC_P6
    // 8
    {0, J_2},  // KC_Q
    {0, J_3},  // KC_E
    {0, J_1},  // KC_T
    {0, J_4},  // KC_U
    {0, J_5},  // KC_0
    {0, J_7},  // KC_LBRC
    {0, J_6},  // KC_P7
    {0, J_9},  // KC_P9
    // 9
    {0, H_2},  // KC_1
    {0, H_3},  // KC_3
    {0, H_1},  // KC_5
    {0, H_4},  // KC_7
    {0, H_5},  // KC_9
    {0, H_7},  // KC_MINS
    {0, H_8},  // KC_BSPC
    {0, H_6},  // KC_NLCK
    {0, H_9},  // KC_PAST
    // 9
    {0, I_2},  // KC_F1
    {0, I_3},  // KC_F3
    {0, I_1},  // KC_F5
    {0, I_4},  // KC_F7
    {0, I_5},  // KC_F9
    {0, I_7},  // KC_F11
    {0, I_8},  // KC_DEL
    {0, I_6},  // KC_HOME
    {0, I_9}  // KC_PGUP
};
#endif // MONO_BACKLIGHT_ENABLED

#include "via.h"

#ifndef VIA_ENABLE
#include "tmk_core/common/eeprom.h"
#include "version.h" // for QMK_BUILDDATE used in EEPROM magic
#endif

// Called from via_init() if VIA_ENABLE
// Called from matrix_init_kb() if not VIA_ENABLE

void via_init_kb(void)
{
    // If the EEPROM has the magic, the data is good.
    // OK to load from EEPROM
    if (via_eeprom_is_valid()) {
#if MONO_BACKLIGHT_ENABLED
        backlight_config_load();
#endif // MONO_BACKLIGHT_ENABLED
    } else	{
#if MONO_BACKLIGHT_ENABLED
        // If the EEPROM has not been saved before, or is out of date,
        // save the default values to the EEPROM. Default values
        // come from construction of the backlight_config instance.
        backlight_config_save();
#endif // MONO_BACKLIGHT_ENABLED

        // DO NOT set EEPROM valid here, let caller do this
    }

#if MONO_BACKLIGHT_ENABLED
    // Initialize LED drivers for backlight.
    backlight_init_drivers();

    backlight_timer_init();
    backlight_timer_enable();
#endif //MONO_BACKLIGHT_ENABLED
}

void matrix_init_kb(void)
{
    // If VIA is disabled, we still need to load backlight settings.
    // Call via_init_kb() the same way as via_init(), with setting
    // EEPROM valid afterwards.
#ifndef VIA_ENABLE
    via_init_kb();
    via_eeprom_set_valid(true);
#endif // VIA_ENABLE

    matrix_init_user();
}

extern uint32_t g_tick;

extern bool g_ret_IS31FL3733_init;
extern bool g_ret_IS31FL3733_update_led_control_registers;

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

void matrix_scan_kb(void)
{
#if MONO_BACKLIGHT_ENABLED
    // This only updates the LED driver buffers if something has changed.
    backlight_update_pwm_buffers();
#endif // MONO_BACKLIGHT_ENABLED
    matrix_scan_user();

    if (g_tick == 40)
    {
        if (g_ret_IS31FL3733_init)
            print("IS31FL3733_init ok\n");
        else
        {
            print("IS31FL3733_init error\n");
            if (!g_initUnlock0)
                print("    g_initUnlock0 error\n");
            if (!g_initSelectPG0)
                print("    g_initSelectPG0 error\n");
            if (!g_initTurnOffLeds)
                print("    g_initTurnOffLeds error\n");
            if (!g_initUnlock1)
                print("    g_initUnlock1 error\n");
            if (!g_initSelectPG1)
                print("    g_initSelectPG1 error\n");
            if (!g_initTurnOnLeds)
                print("    g_initTurnOnLeds error\n");
            if (!g_initUnlock2)
                print("    g_initUnlock2 error\n");
            if (!g_initSelectPG3)
                print("    g_initSelectPG3 error\n");
            if (!g_initSetGlogalCurrent)
                print("    g_initSetGlogalCurrent error\n");
            if (!g_initDisableSoftwareShutDown)
                print("    g_initDisableSoftwareShutDown error\n");
        }

        if (g_ret_IS31FL3733_update_led_control_registers)
            print("IS31FL3733_update_led_control_registers ok\n");
        else
            print("IS31FL3733_update_led_control_registers error\n");
    }
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record)
{
#if MONO_BACKLIGHT_ENABLED
    process_record_backlight(keycode, record);
#endif // MONO_BACKLIGHT_ENABLED

    return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led)
{
#if MONO_BACKLIGHT_ENABLED
    backlight_set_indicator_state(usb_led);
#endif // MONO_BACKLIGHT_ENABLED
    led_set_user(usb_led);
}

void suspend_power_down_kb(void)
{
#if MONO_BACKLIGHT_ENABLED
    backlight_set_suspend_state(true);
#endif // MONO_BACKLIGHT_ENABLED
}

void suspend_wakeup_init_kb(void)
{
#if MONO_BACKLIGHT_ENABLED
    backlight_set_suspend_state(false);
#endif // MONO_BACKLIGHT_ENABLED
}

// Moving this to the bottom of this source file is a workaround
// for an intermittent compiler error for Atmel compiler.
#ifdef VIA_ENABLE
void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
    uint8_t *command_id = &(data[0]);
    uint8_t *command_data = &(data[1]);
    switch ( *command_id )
    {
#if MONO_BACKLIGHT_ENABLED
        case id_lighting_set_value:
        {
            backlight_config_set_value(command_data);
            break;
        }
        case id_lighting_get_value:
        {
            backlight_config_get_value(command_data);
            break;
        }
        case id_lighting_save:
        {
            backlight_config_save();
            break;
        }
#endif // MONO_BACKLIGHT_ENABLED
        default:
        {
            // Unhandled message.
            *command_id = id_unhandled;
            *command_data = *command_data; // force use of variable
            break;
        }
    }
    // DO NOT call raw_hid_send(data,length) here, let caller do this
}
#endif // VIA_ENABLE

//
// In the case of VIA being disabled, we still need to check if
// keyboard level EEPROM memory is valid before loading.
// Thus these are copies of the same functions in VIA, since
// the backlight settings reuse VIA's EEPROM magic/version,
// and the ones in via.c won't be compiled in.
//
// Yes, this is sub-optimal, and is only here for completeness
// (i.e. catering to the 1% of people that want wilba.tech LED bling
// AND want persistent settings BUT DON'T want to use dynamic keymaps/VIA).
//
#ifndef VIA_ENABLE

bool via_eeprom_is_valid(void)
{
    char *p = QMK_BUILDDATE; // e.g. "2019-11-05-11:29:54"
    uint8_t magic0 = ( ( p[2] & 0x0F ) << 4 ) | ( p[3]  & 0x0F );
    uint8_t magic1 = ( ( p[5] & 0x0F ) << 4 ) | ( p[6]  & 0x0F );
    uint8_t magic2 = ( ( p[8] & 0x0F ) << 4 ) | ( p[9]  & 0x0F );

    return (eeprom_read_byte( (void*)VIA_EEPROM_MAGIC_ADDR+0 ) == magic0 &&
            eeprom_read_byte( (void*)VIA_EEPROM_MAGIC_ADDR+1 ) == magic1 &&
            eeprom_read_byte( (void*)VIA_EEPROM_MAGIC_ADDR+2 ) == magic2 );
}

void via_eeprom_set_valid(bool valid)
{
    char *p = QMK_BUILDDATE; // e.g. "2019-11-05-11:29:54"
    uint8_t magic0 = ( ( p[2] & 0x0F ) << 4 ) | ( p[3]  & 0x0F );
    uint8_t magic1 = ( ( p[5] & 0x0F ) << 4 ) | ( p[6]  & 0x0F );
    uint8_t magic2 = ( ( p[8] & 0x0F ) << 4 ) | ( p[9]  & 0x0F );

    eeprom_update_byte( (void*)VIA_EEPROM_MAGIC_ADDR+0, valid ? magic0 : 0xFF);
    eeprom_update_byte( (void*)VIA_EEPROM_MAGIC_ADDR+1, valid ? magic1 : 0xFF);
    eeprom_update_byte( (void*)VIA_EEPROM_MAGIC_ADDR+2, valid ? magic2 : 0xFF);
}

void via_eeprom_reset(void)
{
    // Set the VIA specific EEPROM state as invalid.
    via_eeprom_set_valid(false);
    // Set the TMK/QMK EEPROM state as invalid.
    eeconfig_disable();
}

#endif // VIA_ENABLE






