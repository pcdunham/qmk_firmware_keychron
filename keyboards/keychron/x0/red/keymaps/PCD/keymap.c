/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

#define CUSTOM_KEY_WAIT_TIME 5


enum layers {
    WIN_BASE,
    WIN_FN,
    WIN_L2,
    WIN_L3,
};

enum custom_keycodes {
    CTRL_MS_BTN1 = SAFE_RANGE,
    CTRL_MS_BTN2,
    CTRL_MS_BTN3,
    SHIFT_MS_BTN1,
    SHIFT_MS_BTN2,
    SHIFT_MS_BTN3,
    ALT_MS_BTN1,
    ALT_MS_BTN2,
    ALT_MS_BTN3,
    SHIFT_ALT_MS_BTN1
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [WIN_BASE] = LAYOUT(
        KC_ESC,   CTRL_MS_BTN3,    KC_DEL,    KC_F3,    KC_F4,    KC_F5,
        KC_GRV,   SHIFT_MS_BTN1,   SHIFT_MS_BTN3,     SHIFT_MS_BTN2,     KC_X,     KC_5,     KC_6,
        KC_TAB,   KC_MS_BTN1,     KC_MS_BTN3,     KC_MS_BTN2,     KC_R,     KC_T,
        KC_CAPS,  CTRL_MS_BTN1,     ALT_MS_BTN1,     KC_A,     KC_S,     KC_G,
        OSM(MOD_LSFT),  KC_Z,     KC_X,     KC_C,     KC_V,
        OSM(MOD_LCTL),            OSM(MOD_LALT),  MO(WIN_FN), MO(WIN_FN),  KC_SPC),

    [WIN_FN] = LAYOUT(
        _______,            KC_BRID,  KC_BRIU,  LGUI(KC_TAB),  LGUI(KC_E),  _______,
        _______,  _______,  _______,  _______,       _______,     _______,  _______,
        LM_TOGG,  LM_PREV,  LM_BRIU,  LM_NEXT,       _______,     _______,
        _______,  LM_SPDD,  LM_BRID,  LM_SPDU,       _______,     _______,
        _______,            _______,  _______,       _______,     NK_TOGG,
        _______,            _______,  _______,       _______,          _______),

    [WIN_L2] = LAYOUT(
        _______,            _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,       _______),
    [WIN_L3] = LAYOUT(
        _______,            _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,       _______),
};

// clang-format on



bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // ChatGPT generated code below
    switch (keycode) {
        case CTRL_MS_BTN1:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                wait_ms(CUSTOM_KEY_WAIT_TIME);  // Delay to ensure modifier is active
                register_code(KC_MS_BTN1);
            } else {
                unregister_code(KC_MS_BTN1);
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                unregister_code(KC_LCTL);
            }
            return false;

        case CTRL_MS_BTN2:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                register_code(KC_MS_BTN2);

            } else {
                unregister_code(KC_MS_BTN2);
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                unregister_code(KC_LCTL);
            }
            return false;

        case CTRL_MS_BTN3:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                register_code(KC_MS_BTN3);

            } else {
                unregister_code(KC_MS_BTN3);
                unregister_code(KC_LCTL);
            }
            return false;

        case SHIFT_MS_BTN1:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                register_code(KC_MS_BTN1);

            } else {
                unregister_code(KC_MS_BTN1);
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                unregister_code(KC_LSFT);
            }
            return false;

        case SHIFT_MS_BTN2:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                register_code(KC_MS_BTN2);

            } else {
                unregister_code(KC_MS_BTN2);
                unregister_code(KC_LSFT);
            }
            return false;

        case SHIFT_MS_BTN3:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                register_code(KC_MS_BTN3);

            } else {
                unregister_code(KC_MS_BTN3);
                unregister_code(KC_LSFT);
            }
            return false;

        case ALT_MS_BTN1:
            if (record->event.pressed) {
                register_code(KC_LALT);
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                register_code(KC_MS_BTN1);

            } else {
                unregister_code(KC_MS_BTN1);
                unregister_code(KC_LALT);
            }
            return false;

        case ALT_MS_BTN2:
            if (record->event.pressed) {
                register_code(KC_LALT);
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                register_code(KC_MS_BTN2);

            } else {
                unregister_code(KC_MS_BTN2);
                unregister_code(KC_LALT);
            }
            return false;

        case ALT_MS_BTN3:
            if (record->event.pressed) {
                register_code(KC_LALT);
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                register_code(KC_MS_BTN3);
            } else {
                unregister_code(KC_MS_BTN3);
                unregister_code(KC_LALT);
            }
            return false;

        case SHIFT_ALT_MS_BTN1:
            if (record->event.pressed) {
                // Register Shift and Alt modifiers first
                register_code(KC_LSFT);
                register_code(KC_LALT);
                // Wait a few milliseconds to ensure modifiers are active
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                // Now register Mouse Button 1
                register_code(KC_MS_BTN1);
            } else {
                // On release, unregister Mouse Button 1 and both modifiers
                unregister_code(KC_MS_BTN1);
                unregister_code(KC_LSFT);
                unregister_code(KC_LALT);
            }
            return false;

        default:
            return true; // Process all other keycodes normally.
    }

    return true;


}
