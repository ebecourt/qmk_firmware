#include "simply96.h"

// Scroll Lock LED is tied to D2
// Caps Lock LED is tied to D3
// Num Lock LED is tied to D4

void matrix_init_kb(void) {
  led_init_ports();
};

void led_init_ports(void) {
  setPinOutput(D2);
  setPinOutput(D3);
  setPinOutput(D4);
}

void led_set_kb(uint8_t usb_led) {
  led_set_user(usb_led);
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  return process_record_user(keycode, record);
}

/*
void led_set_kb(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
    // Turn Scroll Lock LED on
    writePinLow(D2);
  } else {
    // Turn Scroll Lock LED off
    writePinHigh(D2);
  }
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    // Turn Caps Lock LED on
    writePinLow(D3);
  } else {
    // Turn Caps Lock LED off
    writePinHigh(D3);
  }

  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    // Turn Num Lock LED on
    writePinLow(D4);
  } else {
    // Turn Num Lock LED off
    writePinHigh(D4);
  }
}
*/
