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

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xDEAD
#define PRODUCT_ID      0x9600
#define DEVICE_VER      0x0001
#define MANUFACTURER    Rico
#define PRODUCT         Simply96
#define DESCRIPTION     A simple TK keyboard

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 19

/* Simly96 PCB default pin-out */
#define MATRIX_ROW_PINS { F0, F1, F2, F3, F4, F5 }
#define MATRIX_COL_PINS { C2, C3, C4, C5, C6, C7, A7, A6, A5, A4, A3, A2, A1, A0, C1, C0, D7, D6, D5 }
#define UNUSED_PINS { B0, B1, B2, B3, B4, B5, B6, B7, D0, D1, E0, E1, E3, E4, E5, E6, E7, F6, F7 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

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
