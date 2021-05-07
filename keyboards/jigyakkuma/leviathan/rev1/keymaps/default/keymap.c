/* Copyright 2020 jigyakkuma
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
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN1,
    _FN2
};

// Defines the keycodes used by our macros in process_record_user
// enum custom_keycodes {
// };

// Defines the keycodes used by our macros in process_record_user
enum encoder_number {
    _1ST_ENC = 0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
   [_BASE] = LAYOUT(
   KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
   KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_LBRC,
   KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
   KC_LGUI, TT(_FN1),         TT(_FN2),KC_LSPO, KC_SPC,      KC_ENT,  KC_RSPC, KC_BSPC,          KC_RGUI, TT(_FN1),
                                                _______
   ),

   [_FN1] = LAYOUT(
   _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
   _______, _______, _______, _______, _______, KC_ZKHK,     KC_TILD, _______, _______, _______, KC_BSLS, KC_RBRC,
   _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
   _______, _______,          _______, _______, _______,     _______, _______, _______,          _______, _______,
                                                _______
   ),

   [_FN2] = LAYOUT(
   KC_F11 , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
   KC_F12 , _______, _______, _______, _______, _______,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
   _______, _______, _______, _______, _______, _______,     _______, KC_HOME, KC_END,  _______, _______, _______,
   _______, _______,          _______, _______, _______,     _______, KC_PGDN, KC_PGUP,          _______, _______,
                                                _______
   )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    switch(get_highest_layer(layer_state)) {
        case _BASE:
            tap_code(KC_MUTE);
            break;
        case _FN1:
            clockwise ? tap_code(KC_PPLS) : tap_code(KC_MINS);
            break;
        case _FN2:
            clockwise ? tap_code(KC__VOLUP) : tap_code(KC__VOLDOWN);
            break;
    }
}

