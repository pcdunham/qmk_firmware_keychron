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


#define CUSTOM_KEY_WAIT_TIME 3

bool ctrl_toggled = false;
bool SHFT_toggled = false;
bool alt_toggled = false;


enum layers {
    WIN_BASE,
    BLENDER,
    PLASTICITY,
    WIN_FN,
};

enum custom_keycodes {
    CTRL_BTN1 = SAFE_RANGE,
    CTRL_BTN2,
    CTRL_BTN3,
    SHFT_BTN1,
    SHFT_BTN2,
    SHFT_BTN3,
    ALT_BTN1,
    ALT_BTN2,
    ALT_BTN3,
    SA_BTN1,
    CS_BTN1,
    CA_BTN1,
    CSA_BTN1,
    TOG_LSFT,
    TOG_LCTL,
    TOG_LALT,
    RESET_MODS,

};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [WIN_BASE] = LAYOUT(
        KC_ESC,                            CTRL_BTN3,      CS_BTN1,   KC_F3,      KC_F4,     KC_F5,
        KC_GRV,         SHFT_BTN1,         SHFT_BTN3,      SA_BTN1,   KC_X,       KC_Y,      KC_DEL,
        KC_TAB,         QK_MOUSE_BUTTON_1,QK_MOUSE_BUTTON_3,QK_MOUSE_BUTTON_2,    KC_R,      KC_T,
        KC_CAPS,        CTRL_BTN1,         ALT_BTN1,       CA_BTN1,   KC_S,       KC_G,
        OSM(MOD_LSFT),  C(KC_Z),           C(KC_X),        C(KC_C),   C(KC_V),
        OSM(MOD_LCTL),                     OSM(MOD_LALT),  KC_LGUI,   OSL(WIN_FN),KC_SPC),

    [BLENDER] = LAYOUT(
        KC_ESC,                            CTRL_BTN3,      CS_BTN1,   KC_F3,      KC_F4,     KC_F5,
        KC_GRV,         SHFT_BTN1,         SHFT_BTN3,      SA_BTN1,   KC_X,       KC_Y,      KC_Z,
        KC_TAB,         QK_MOUSE_BUTTON_1,QK_MOUSE_BUTTON_3,QK_MOUSE_BUTTON_2,    CSA_BTN1,  KC_T,
        KC_CAPS,        CTRL_BTN1,         ALT_BTN1,       ALT_BTN3,  CA_BTN1,    KC_G,
        OSM(MOD_LSFT),  C(KC_Z),           C(KC_X),        C(KC_C),   C(KC_V),
        OSM(MOD_LCTL),                     OSM(MOD_LALT),  KC_LGUI,   OSL(WIN_FN),KC_SPC),

    [PLASTICITY] = LAYOUT(
        KC_ESC,                            CTRL_BTN3,      CS_BTN1,   KC_F3,      KC_F4,     KC_F5,
        KC_GRV,         SHFT_BTN1,         SHFT_BTN3,      SA_BTN1,   KC_X,       KC_Y,      KC_DEL,
        KC_TAB,         QK_MOUSE_BUTTON_1,QK_MOUSE_BUTTON_3,QK_MOUSE_BUTTON_2,    CSA_BTN1,  KC_T,
        KC_CAPS,        CTRL_BTN1,         ALT_BTN1,       CA_BTN1,   KC_S,       KC_G,
        OSM(MOD_LSFT),  C(KC_Z),           C(KC_X),        C(KC_C),   C(KC_V),
        OSM(MOD_LCTL),                     OSM(MOD_LALT),  KC_LGUI,   OSL(WIN_FN),KC_SPC),

    [WIN_FN] = LAYOUT(
        _______,                           KC_BRID,        KC_BRIU,       LGUI(KC_TAB),LGUI(KC_E),  _______,
        _______,        TO(WIN_BASE),      TO(BLENDER),    TO(PLASTICITY),_______,     _______,     _______,
        LM_TOGG,        LM_PREV,           LM_BRIU,        LM_NEXT,       _______,     _______,
        _______,        LM_SPDD,           LM_BRID,        LM_SPDU,       _______,     _______,
        _______,        _______,           _______,        _______,       NK_TOGG,
        RESET_MODS,     _______,           _______,        _______,       _______),


};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {


    switch (keycode) {
        case CTRL_BTN1:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                wait_ms(CUSTOM_KEY_WAIT_TIME);  // Delay to ensure modifier is active
                register_code(QK_MOUSE_BUTTON_1);
            } else {
                unregister_code(QK_MOUSE_BUTTON_1);
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                unregister_code(KC_LCTL);
            }
            return false;

        case CTRL_BTN2:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                register_code(QK_MOUSE_BUTTON_2);

            } else {
                unregister_code(QK_MOUSE_BUTTON_2);
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                unregister_code(KC_LCTL);
            }
            return false;

        case CTRL_BTN3:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                register_code(QK_MOUSE_BUTTON_3);

            } else {
                unregister_code(QK_MOUSE_BUTTON_3);
                unregister_code(KC_LCTL);
            }
            return false;

        case SHFT_BTN1:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                register_code(QK_MOUSE_BUTTON_1);

            } else {
                unregister_code(QK_MOUSE_BUTTON_1);
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                unregister_code(KC_LSFT);
            }
            return false;

        case SHFT_BTN2:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                register_code(QK_MOUSE_BUTTON_2);

            } else {
                unregister_code(QK_MOUSE_BUTTON_2);
                unregister_code(KC_LSFT);
            }
            return false;

        case SHFT_BTN3:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                register_code(QK_MOUSE_BUTTON_3);

            } else {
                unregister_code(QK_MOUSE_BUTTON_3);
                unregister_code(KC_LSFT);
            }
            return false;

        case ALT_BTN1:
            if (record->event.pressed) {
                register_code(KC_LALT);
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                register_code(QK_MOUSE_BUTTON_1);

            } else {
                unregister_code(QK_MOUSE_BUTTON_1);
                unregister_code(KC_LALT);
            }
            return false;

        case ALT_BTN2:
            if (record->event.pressed) {
                register_code(KC_LALT);
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                register_code(QK_MOUSE_BUTTON_2);

            } else {
                unregister_code(QK_MOUSE_BUTTON_2);
                unregister_code(KC_LALT);
            }
            return false;

        case ALT_BTN3:
            if (record->event.pressed) {
                register_code(KC_LALT);
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                register_code(QK_MOUSE_BUTTON_3);
            } else {
                unregister_code(QK_MOUSE_BUTTON_3);
                unregister_code(KC_LALT);
            }
            return false;

        case SA_BTN1:
            if (record->event.pressed) {
                // Register SHFT and Alt modifiers first
                register_code(KC_LSFT);
                register_code(KC_LALT);
                // Wait a few milliseconds to ensure modifiers are active
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                // Now register Mouse Button 1
                register_code(QK_MOUSE_BUTTON_1);
            } else {
                // On release, unregister Mouse Button 1 and both modifiers
                unregister_code(QK_MOUSE_BUTTON_1);
                unregister_code(KC_LSFT);
                unregister_code(KC_LALT);
            }
            return false;

        case CS_BTN1:
            if (record->event.pressed) {
                // Register SHFT and Alt modifiers first
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                // Wait a few milliseconds to ensure modifiers are active
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                // Now register Mouse Button 1
                register_code(QK_MOUSE_BUTTON_1);
            } else {
                // On release, unregister Mouse Button 1 and both modifiers
                unregister_code(QK_MOUSE_BUTTON_1);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            return false;

        case CA_BTN1:
            if (record->event.pressed) {
                // Register SHFT and Alt modifiers first
                register_code(KC_LCTL);
                register_code(KC_LALT);
                // Wait a few milliseconds to ensure modifiers are active
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                // Now register Mouse Button 1
                register_code(QK_MOUSE_BUTTON_1);
            } else {
                // On release, unregister Mouse Button 1 and both modifiers
                unregister_code(QK_MOUSE_BUTTON_1);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
            }
            return false;

        case CSA_BTN1:
            if (record->event.pressed) {
                // Register SHFT and Alt modifiers first
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_LSFT);
                // Wait a few milliseconds to ensure modifiers are active
                wait_ms(CUSTOM_KEY_WAIT_TIME);
                // Now register Mouse Button 1
                register_code(QK_MOUSE_BUTTON_1);
            } else {
                // On release, unregister Mouse Button 1 and modifiers
                unregister_code(QK_MOUSE_BUTTON_1);
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            return false;

        case TOG_LCTL:
            if (record->event.pressed) {
                if (record->tap.count && !record->tap.interrupted) {
                    ctrl_toggled = !ctrl_toggled;
                    if (ctrl_toggled) {
                        register_code(KC_LCTL);
                    } else {
                        unregister_code(KC_LCTL);
                    }
                } else {
                    register_code(KC_LCTL);
                }
            } else {
                if (!record->tap.count || record->tap.interrupted) {
                    if (!ctrl_toggled) unregister_code(KC_LCTL);
                }
            }
            return false;

        case TOG_LSFT:
            if (record->event.pressed) {
                if (record->tap.count && !record->tap.interrupted) {
                    SHFT_toggled = !SHFT_toggled;
                    if (SHFT_toggled) {
                        register_code(KC_LSFT);
                    } else {
                        unregister_code(KC_LSFT);
                    }
                } else {
                    register_code(KC_LSFT);
                }
            } else {
                if (!record->tap.count || record->tap.interrupted) {
                    if (!SHFT_toggled) unregister_code(KC_LSFT);
                }
            }
            return false;

        case TOG_LALT:
            if (record->event.pressed) {
                if (record->tap.count && !record->tap.interrupted) {
                    alt_toggled = !alt_toggled;
                    if (alt_toggled) {
                        register_code(KC_LALT);
                    } else {
                        unregister_code(KC_LALT);
                    }
                } else {
                    register_code(KC_LALT);
                }
            } else {
                if (!record->tap.count || record->tap.interrupted) {
                    if (!alt_toggled) unregister_code(KC_LALT);
                }
            }
            return false;

        case RESET_MODS:
            if (record->event.pressed) {
                ctrl_toggled = false;
                SHFT_toggled = false;
                alt_toggled = false;
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
                unregister_code(KC_LALT);
            }
            return false;



        default:
            return true; // Process all other keycodes normally.
    }

    return true;



}


