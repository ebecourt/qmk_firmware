#include QMK_KEYBOARD_H

#include "simply96.h"

#define BASE    0
#define ALT     2
#define NUMLOCK 1

#if 0
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Layer 0, default layer */
  [BASE] = {
    {KC_ESC,  KC_NO,   KC_F1,   KC_F2,             KC_F3,   KC_F4,   KC_NO,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_BRK,  TG(NUMLOCK) },
    {KC_GRV,  KC_1,    KC_2,    KC_3,              KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NO,   KC_BSPC, KC_INS,  KC_HOME, KC_PGUP, KC_NO       },
    {KC_TAB,  KC_NO,   KC_Q,    KC_W,              KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_ENT,  KC_DEL,  KC_END,  KC_PGDN, KC_NO       },
    {KC_CAPS, KC_NO,   KC_A,    KC_S,              KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    FR_M,    KC_QUOT, KC_NUHS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO       },
    {KC_NO,   KC_LSFT, KC_Z,    KC_X,              KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,   KC_RSFT, KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO       },
    {KC_LCTL, KC_LGUI, KC_NO,   LM(ALT, MOD_LALT), KC_NO,   KC_NO,   KC_SPC,  KC_NO,   KC_NO,   KC_NO,   KC_RALT, KC_RGUI, KC_NO,   KC_APP,  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO       }
  },

  /* Layer 1, layer when alt maintained*/
  [ALT] = {
    {_______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX     },
    {_______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_PMNS     },
    {_______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS     },
    {_______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_NO       },
    {_______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT     },
    {_______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_P0,   KC_PDOT, KC_NO       }
  },

  /* Layer 2, layer when numlock pressed*/
  [NUMLOCK] = {
    {_______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TG(BASE)    },
    {_______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_PMNS     },
    {_______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS     },
    {_______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_NO       },
    {_______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT     },
    {_______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_P0,   KC_PDOT, KC_NO       }
  }
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Layer 0, default layer */
  [BASE] = {
    {KC_ESC,  KC_NO,      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_NO,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,     KC_F10,  KC_F11,  KC_F12,    KC_PSCR, KC_BRK,  KC_SLCK, TG(NUMLOCK) },
    {KC_GRV,  KC_1,       KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,   KC_EQL,  KC_NO,   KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, KC_NO       },
    {KC_TAB,  KC_NO,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_LBRC, KC_RBRC, KC_BSLASH, KC_DEL,  KC_END,  KC_PGDN, KC_NO       },
    {LT(NUMLOCK,KC_CAPS), KC_NO,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCOLON, KC_QUOT, KC_ENT,  KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO       },
    {KC_NO,               KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   KC_NO,   KC_RSFT, KC_NO,     KC_NO,   KC_UP,   KC_NO,   KC_NO       },
    {KC_LCTL,             KC_LGUI, KC_NO,   KC_LALT, KC_NO,   KC_NO,   KC_SPC,  KC_NO,   KC_NO,   KC_NO,   KC_RALT, KC_RGUI,   KC_NO,   KC_APP,  KC_RCTL,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO                }
  },
  /* Layer 2, layer when numlock pressed*/
  [NUMLOCK] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,   _______, _______, _______, TG(NUMLOCK) },
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,   XXXXXXX, KC_PSLS, KC_PAST, KC_PMNS     },
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS     },
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,   KC_P4,   KC_P5,   KC_P6,   _______     },
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,   KC_P1,   KC_P2,   KC_P3,   KC_PENT     },
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,   KC_P0,   KC_P0,   KC_PDOT, _______     }
  }
};

bool g_numlockEnabled = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {

    case TG(NUMLOCK):
      if (record->event.pressed) {
        g_numlockEnabled = !g_numlockEnabled;
        if (g_numlockEnabled) {
          writePinHigh(D2);
        } else {
          writePinLow(D2);
        }
      }
      return true;

    case LT(NUMLOCK,KC_CAPS):
      if (record->event.pressed) {
        if (!g_numlockEnabled) {
          writePinHigh(D2);
        }
      } else {
        if (!g_numlockEnabled) {
          writePinLow(D2);
        }
      }
      return true;

    default:
      return true;
  }
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
    // Turn Scroll Lock LED on
    writePinHigh(D3);
  } else {
    // Turn Scroll Lock LED off
    writePinLow(D3);
  }
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    // Turn Caps Lock LED on
    writePinHigh(D4);
  } else {
    // Turn Caps Lock LED off
    writePinLow(D4);
  }
}
