/* Copyright 2021 jigyakkuma
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
    _L1,
    _L2,
    _L3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_GESC, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,      KC_Y   , KC_U   , KC_I   , KC_O   ,  KC_P   , KC_MINS, KC_EQL ,
        KC_TAB , KC_A   ,  KC_S   , KC_D   , KC_F   , KC_G   ,      KC_H   , KC_J   , KC_K   , KC_L   ,   KC_SCLN,        KC_BSLS,
        KC_RCTL, KC_Z   ,   KC_X   , KC_C   , KC_V   , KC_B   ,    KC_BSPC, KC_N   , KC_M   , KC_COMM,  KC_DOT , KC_SLSH, KC_QUOT,
        KC_LGUI, TT(_L1),            TT(_L2), KC_LSPO, KC_SPC ,    KC_ENT , KC_RSPC, KC_RGUI,                    KC_LBRC, TT(_L1)
    ),
    [_L1] = LAYOUT(
        _______, _______, KC_1   , KC_2   , KC_3   , _______,      _______, _______, _______, _______,  _______, _______, _______,
        _______, _______,  KC_4   , KC_5   , KC_6   , KC_ZKHK,      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT,   _______,        _______,
        _______, _______,   KC_7   , KC_8   , KC_9   , KC_0   ,    _______, _______, _______, _______,  _______, _______, _______,
        _______, _______,            MO(_L3), _______, _______,    _______,  _______, _______,                   KC_RBRC, _______
    ),
    [_L2] = LAYOUT(
        KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,      KC_F6  , KC_F7  , KC_F8  , KC_F9  ,  KC_F10 , _______, _______,
        KC_F11 , _______,  _______, _______, _______, _______,      _______, _______, _______, _______,   _______,        _______,
        _______, _______,   _______, _______, _______, _______,    _______, KC_HOME, KC_END , _______,  _______, _______, _______,
        _______, MO(_L3),            _______, _______, _______,    _______,  _______, _______,                   _______, _______
    ),
    [_L3] = LAYOUT(
        _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______,  _______, _______, _______,
        _______, _______,  _______, _______, _______, _______,      _______, KC_VOLU, KC_MNXT, _______,   _______,        _______,
        _______, _______,   _______, _______, _______, _______,    _______, KC_VOLD, KC_MPRV, _______,  _______, _______, _______,
        _______, _______,            _______, _______, _______,    KC_MUTE , KC_MPLY, KC_MSTP,                   _______, _______
    )
};

const rgblight_segment_t PROGMEM rgb_base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_AZURE}
);

const rgblight_segment_t PROGMEM rgb_l1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_MAGENTA}
);

const rgblight_segment_t PROGMEM rgb_l2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_GREEN}
);

const rgblight_segment_t PROGMEM rgb_l3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_ORANGE}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_base_layer,
    rgb_l1_layer,
    rgb_l2_layer,
    rgb_l3_layer
);

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
    rgblight_set_layer_state(1, layer_state_cmp(state, _L1));
    rgblight_set_layer_state(2, layer_state_cmp(state, _L2));
    rgblight_set_layer_state(3, layer_state_cmp(state, _L3));
    return state;
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
}

