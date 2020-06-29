/*
Copyright 2016 Daniel Svensson <dsvensson@gmail.com>

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

#include QMK_KEYBOARD_H

#define KM_QWERTY_MAC    0
#define KM_QWERTY_WIN    1
#define KM_MISC_N_MEDIA  2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Layer 0: Standard ISO layer */
  [KM_QWERTY_MAC] = LAYOUT( \
    KC_ESC,                   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,     KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12,     KC_PSCR, KC_SLCK, KC_PAUS, \
    KC_GRV,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,        KC_8,      KC_9,     KC_0,    KC_MINS, KC_EQL,  KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP, \
    KC_TAB,          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,        KC_I,      KC_O,     KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN, \
    LCTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,        KC_K,      KC_L,     KC_SCLN, KC_QUOT,          KC_ENT,                                \
    KC_LSPO,         KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,        KC_M,      KC_COMM,  KC_DOT,  KC_SLSH,          KC_RSPC,             KC_UP,            \
    KC_LCTL,         KC_LALT, KC_LGUI,                            KC_SPC,                                    KC_RGUI, TT(2),   KC_MENU, KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT  \
  ),

  /* Layer 1: Function layer */
  [KM_QWERTY_WIN] = LAYOUT( \
    _______,                  _______, _______, _______, _______, _______, _______,     _______,   _______,  _______, _______, _______, _______,    _______, _______, _______, \
    _______,         _______, _______, _______, _______, _______, _______, _______,     _______,   _______,  _______, _______, _______, _______,    _______, _______, _______, \
    _______,         _______, _______, _______, _______, _______, _______, _______,     _______,   _______,  _______, _______, _______, _______,    _______, _______, _______, \
    _______,         _______, _______, _______, _______, _______, _______, _______,     _______,   _______,  _______, _______,          _______,                               \
    _______,         _______, _______, _______, _______, _______, _______, _______,     _______,   _______,  _______, _______,          _______,             _______,          \
    _______,         KC_LGUI, KC_LALT,                            _______,                                   KC_RALT, _______, _______, _______,    _______, _______, _______ \
  ),

  /* Layer 2: */
  [KM_MISC_N_MEDIA] = LAYOUT( \
    _______,                  _______, _______, _______, _______, _______, _______,     _______,   _______,  _______, _______, _______, _______,    _______, _______, RESET,   \
    _______,         _______, _______, _______, _______, _______, _______, _______,     _______,   _______,  _______, _______, _______, _______,    _______, _______, _______, \
    _______,         _______, _______, _______, _______, _______, _______, _______,     _______,   _______,  _______, _______, _______, _______,    _______, _______, _______, \
    LCTL_T(KC_CAPS), _______, _______, _______, _______, _______, _______, _______,     _______,   _______,  _______, _______,          KC_PENT,                               \
    _______,         _______, _______, _______, _______, _______, _______, KC__VOLDOWN, KC__VOLUP, KC__MUTE, _______, _______,          _______,             _______,          \
    _______,         _______, _______,                            _______,                                   TG(1),   _______, _______, _______,    _______, _______, _______  \
  )
};

void led_set_user(uint8_t usb_led) {
  if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
    ph_caps_led_on();
  } else {
    ph_caps_led_off();
  }

  if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
    ph_sclk_led_on();
  } else {
    ph_sclk_led_off();
  }
}
