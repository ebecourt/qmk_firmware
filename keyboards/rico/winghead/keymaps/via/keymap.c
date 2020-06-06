#include QMK_KEYBOARD_H

#include "winghead.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = {
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
  },
  [1] = {
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
  },
  [2] = {
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
  }
};


