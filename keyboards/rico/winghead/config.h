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

#ifndef CONFIG_H
#define CONFIG_H

/* USB Device descriptor parameter */
#define VENDOR_ID       0xDEAD
#define PRODUCT_ID      0x1800
#define DEVICE_VER      0x0001
#define MANUFACTURER    Rico
#define PRODUCT         Winghead
#define DESCRIPTION     Homemade 1800 layout

/* key matrix size */
#define MATRIX_ROWS 12
#define MATRIX_COLS 10

/* Winghead PCB default pin-out */
#define MATRIX_ROW_PINS { F5, F4, F1, F0, E6, B0, B1, B2, B3, B7, D2, D3 }
#define MATRIX_COL_PINS { D5, D4, D6, D7, B4, B5, B6, C6, C7, F6 }
#define UNUSED_PINS { F7 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define LED_DRIVER_COUNT    1
#define LED_DRIVER_LED_COUNT 101
//#define LED_DRIVER_ADDR_1 0b1010000
#define LED_DRIVER_ADDR_1 0x50
#define BACKLIGHT_LEVELS 6


// enable the mono backlight
#define MONO_BACKLIGHT_ENABLED 1

// disable backlight when USB suspended (PC sleep/hibernate/shutdown)
#define MONO_BACKLIGHT_DISABLE_WHEN_USB_SUSPENDED 0

// disable backlight after timeout in minutes, 0 = no timeout
#define MONO_BACKLIGHT_DISABLE_AFTER_TIMEOUT 0

// the default brightness
#define MONO_BACKLIGHT_BRIGHTNESS 255

// the default effect
#define MONO_BACKLIGHT_EFFECT 1

// the default effect speed (0-3)
#define MONO_BACKLIGHT_EFFECT_SPEED 0

// Backlight config starts after VIA's EEPROM usage,
// dynamic keymaps start after this.
#define VIA_EEPROM_CUSTOM_CONFIG_SIZE 7

// VIA lighting is handled by the keyboard-level code
#define VIA_CUSTOM_LIGHTING_ENABLE

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#endif
