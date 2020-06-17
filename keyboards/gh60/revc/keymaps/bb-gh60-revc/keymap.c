#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_all( /* 0: qwerty */
        KC_GRAVE,         KC_1,      KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,
        KC_TAB,           KC_Q,      KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        LCTL_T(KC_ESC),   KC_A,      KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_ENT,
        KC_LSPO,          KC_NO,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, KC_NO,
        KC_LCTL,          KC_LGUI,   KC_LALT,                   KC_SPC,                                      KC_RALT, TT(1),   KC_APP,  KC_RCTL
    ),

    [1] = LAYOUT_all( /* 1: fn */
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,       KC_F8,     KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_DEL, KC_DEL,
        _______, _______, KC_UP,   _______, _______, _______, _______, _______,     KC_INS,    _______,  KC_PSCR, KC_SLCK, KC_PAUS, _______,
        KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_LEFT, KC_DOWN,     KC_UP,     KC_RGHT,  KC_HOME, KC_PGUP, KC_PENT, KC_PENT,
        _______, _______, _______, _______, _______, _______, _______, KC__VOLDOWN, KC__VOLUP, KC__MUTE, KC_END,  KC_PGDN, _______, _______,
        _______, _______, _______,                   _______,                                     _______, _______, _______, _______
    ),

};

void matrix_scan_user(void) {

//Layer LED indicators
    uint32_t layer = layer_state;

    if (layer & (1<<1)) {
        gh60_wasd_leds_on();
        gh60_fn_led_on();
    } else {
        gh60_wasd_leds_off();
        gh60_fn_led_off();
    }

    if (layer & (1<<2)) {
        gh60_poker_leds_on();
        gh60_esc_led_on();
    } else {
        gh60_poker_leds_off();
        gh60_esc_led_off();
    }

};
