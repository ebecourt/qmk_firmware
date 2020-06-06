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

#include "winghead.h"

#ifdef LED_MATRIX_ENABLE
    #include "is31fl3733-simple.h"

/*
{ KC_ESC,  KC_F2,   KC_F4,  KC_F6, KC_F8,   KC_F10,    KC_F12,  KC_NO,     KC_BRK,  KC_PGDN },
{ KC_GRV,  KC_2,    KC_4,   KC_6,  KC_8,    KC_O,      KC_EQL,  KC_NO,     KC_PSLS, KC_PMNS },
{ KC_TAB,  KC_W,    KC_R,   KC_Y,  KC_I,    KC_P,      KC_RBRC, KC_BSLASH, KC_P8,   KC_PPLS },
{ KC_CAPS, KC_S,    KC_F,   KC_H,  KC_K,    KC_SCOLON, KC_NUHS, KC_NO,     KC_P5,   KC_NO   },
{ KC_LSFT, KC_Z,    KC_C,   KC_B,  KC_M,    KC_DOT,    KC_RSFT, KC_NO,     KC_P2,   KC_PENT },
{ KC_LCTL, KC_LALT, KC_NO,  KC_NO, KC_RALT, KC_RCTL,   KC_LEFT, KC_RGHT,   KC_PDOT, KC_NO   },
{ KC_LGUI, KC_NO,   KC_SPC, KC_NO, KC_RGUI, KC_NO,     KC_DOWN, KC_P0,     KC_NO,   KC_NO   },
{ KC_NUBS, KC_X,    KC_V,   KC_N,  KC_COMM, KC_SLSH,   KC_UP,   KC_P1,     KC_P3,   KC_NO   },
{ KC_A,    KC_D,    KC_G,   KC_J,  KC_L,    KC_QUOT,   KC_ENT,  KC_P4,     KC_P6,   KC_NO   },
{ KC_Q,    KC_E,    KC_T,   KC_U,  KC_0,    KC_LBRC,   KC_NO,   KC_P7,     KC_P9,   KC_NO   },
{ KC_1,    KC_3,    KC_5,   KC_7,  KC_9,    KC_MINS,   KC_BSPC, KC_NLCK,   KC_PAST, KC_NO   },
{ KC_F1,   KC_F3,   KC_F5,  KC_F7, KC_F9,   KC_F11,    KC_DEL,  KC_HOME,   KC_PGUP, KC_NO   }
*/

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

#if 0
const led_matrix g_leds[LED_DRIVER_LED_COUNT] = {

    /*{row | col << 4}
      |            LED_ROW_COL(row, col)
      |             |            modifier
      |             |            | */
    {{0|(1<<4)},   {0, 0}, 1},           // k00  KC_GESC
    {{0|(2<<4)},   {14.45, 0}, 0},       // k01 KC_1
    {{0|(3<<4)},   {28.9, 0}, 0},        // k02 KC_2
    {{0|(4<<4)},   {43.35, 0}, 0},       // k03 KC_3
    {{0|(5<<4)},   {57.8, 0}, 0},        // k04 KC_4
    {{0|(6<<4)},   {72.25, 0}, 0},       // k05 KC_5
    {{0|(7<<4)},   {86.7, 0}, 0},        // k06 KC_6
    {{0|(8<<4)},   {101.2, 0}, 0},       // k07 KC_7
    {{0|(9<<4)},   {115.6, 0}, 0},       // k50 KC_8
    {{0|(10<<4)},  {130, 0}, 0},         // k51 KC_9
    {{0|(11<<4)},  {144.5, 0}, 0},       // k52 KC_0
    {{0|(12<<4)},  {159, 0}, 0},         // k53 KC_MINS
    {{0|(13<<4)},  {173.4, 0}, 0},       // k54 KC_EQL
    {{0|(14<<4)},  {195.1, 0}, 1},       // k55 KC_BSPC
    {{0|(15<<4)},  {224, 0}, 1},         // k57 KC_PGUP

    {{1|(0<<4)},   {3.6125, 16}, 1},     // k10 KC_TAB
    {{1|(1<<4)},   {21.675, 16}, 0},     // k11 KC_Q
    {{1|(2<<4)},   {36.125, 16}, 0},     // k12 KC_W
    {{1|(3<<4)},   {50.575, 16}, 0},     // k13 KC_E
    {{1|(4<<4)},   {65.025, 16}, 0},     // k14 KC_R
    {{1|(5<<4)},   {79.475, 16}, 0},     // k15 KC_T
    {{1|(6<<4)},   {93.925, 16}, 0},     // k16 KC_Y
    {{1|(7<<4)},   {108.375, 16}, 0},    // k17 KC_U
    {{1|(8<<4)},   {122.825, 16}, 0},    // k60 KC_I
    {{1|(9<<4)},   {137.275, 16}, 0},    // k61 KC_O
    {{1|(10<<4)},  {151.725, 16}, 0},    // k62 KC_P
    {{1|(11<<4)},  {166.175, 16}, 0},    // k63 KC_LBRC
    {{1|(12<<4)},  {180.625, 16}, 0},    // k64 KC_RBRC
    {{1|(13<<4)},  {198.6875, 16}, 1},   // k65 KC_BSLS
    {{1|(14<<4)},  {224, 16}, 1},        // k67 KC_PGDN

    {{2|(0<<4)},   {5.41875, 32}, 1},    // k20 KC_CAPS
    {{2|(1<<4)},   {25.2875, 32}, 0},    // k21 KC_A
    {{2|(2<<4)},   {39.7375, 32}, 0},    // k22 KC_S
    {{2|(3<<4)},   {54.1875, 32}, 0},    // k23 KC_D
    {{2|(4<<4)},   {68.6375, 32}, 0},    // k24 KC_F
    {{2|(5<<4)},   {83.0875, 32}, 0},    // k25 KC_G
    {{2|(6<<4)},   {97.5375, 32}, 0},    // k26 KC_H
    {{2|(7<<4)},   {111.9875, 32}, 0},   // k27 KC_J
    {{2|(8<<4)},   {126.4375, 32}, 0},   // k70 KC_K
    {{2|(9<<4)},   {140.8875, 32}, 0},   // k71 KC_L
    {{2|(10<<4)},  {155.3375, 32}, 0},   // k72 KC_SCLN
    {{2|(11<<4)},  {169.7875, 32}, 0},   // k73 KC_QUOT
    {{2|(12<<4)},  {184.2375, 32}, 1},   // k75 KC_ENT

    {{3|(0<<4)},   {16.25625, 48}, 1},   // k30 KC_LSFT
    {{3|(1<<4)},   {32.5125, 48}, 0},    // k32 KC_Z
    {{3|(2<<4)},   {46.9625, 48}, 0},    // k33 KC_X
    {{3|(3<<4)},   {61.4125, 48}, 0},    // k34 KC_C
    {{3|(4<<4)},   {75.8625, 48}, 0},    // k35 KC_V
    {{3|(5<<4)},   {90.3125, 48}, 0},    // k36 KC_B
    {{3|(6<<4)},   {104.7625, 48}, 0},   // k37 KC_N
    {{3|(7<<4)},   {119.2125, 48}, 0},   // k80 KC_M
    {{3|(8<<4)},   {133.6625, 48}, 0},   // k81 KC_COMM
    {{3|(9<<4)},   {148.1125, 48}, 0},   // k82 KC_DOT
    {{3|(10<<4)},  {162.5625, 48}, 0},   // k83 KC_SLSH
    {{3|(11<<4)},  {187.85, 48}, 1},     // k85 KC_RSFT
    {{3|(12<<4)},  {209.525, 48}, 1},    // k86 KC_UP

    {{4|(0<<4)},   {9.03125, 64}, 1},    // k40 KC_LCTL
    {{4|(1<<4)},   {27.09375, 64}, 1},   // k41 KC_LGUI
    {{4|(2<<4)},   {45.15625, 64}, 1},   // k42 KC_LALT
    {{4|(3<<4)},   {59.45, 64}, 1},      // Unassociated between LALT and SPACE_2.75
    {{4|(4<<4)},   {73.9, 64}, 1},       // k45 KC_SPC SPACE_2.75
    {{4|(5<<4)},   {88.35, 64}, 1},      // k45 KC_SPC SPACE_6.25
    {{4|(6<<4)},   {102.8, 64}, 1},      // k46 KC_SPC SPACE_2.25
    {{4|(7<<4)},   {117.40625, 64}, 1},  // Unassociated between SPACE_2.25 and SPACE_2.75
    {{4|(8<<4)},   {135.46875, 64}, 1},  // k90 KC_RGUI
    {{4|(9<<4)},   {153.53125, 64}, 1},  // k92 KC_RALT
    {{4|(10<<4)},  {167.98125, 64}, 1},  // k93 MO(_FL)
    {{4|(11<<4)},  {186.04375, 64}, 1},  // k94 KC_RCTL
    {{4|(12<<4)},  {195.075, 64}, 1},    // k95 KC_LEFT
    {{4|(13<<4)},  {209.525, 64}, 1},    // k96 KC_DOWN
    {{4|(14<<4)},  {224, 64}, 1}         // k97 KC_RGHT
};
#endif

#endif

