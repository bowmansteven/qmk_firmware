/*
Copyright 2021 CapsUnlocked

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

enum custom_keycodes {
    PASSWORD = SAFE_RANGE,
    GLOBALPROTECT
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
          case PASSWORD:
            if (record->event.pressed) {
            // when keycode PASSWORD is pressed
                SEND_STRING_DELAY("CollapseCollapse!15" SS_DELAY(100) SS_TAP(X_ENT), 10);
            } else {
            // when keycode PASSWORD is released
            }
            return false;
         case GLOBALPROTECT:
            if (record->event.pressed) {
            // when keycode PASSWORD is pressed
                SEND_STRING_DELAY("steven.bowman" SS_DELAY(100) SS_TAP(X_TAB) "CollapseCollapse!15" SS_DELAY(100) SS_TAP(X_ENT), 10);
            } else {
            // when keycode PASSWORD is released
            }
            return false; 
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
             MO(1),
    KC_1,    KC_2,    KC_3,
    PASSWORD, KC_5,    GLOBALPROTECT
  ),
  [1] = LAYOUT(
             _______,
    UG_NEXT, KC_UP,   QK_BOOT,
    KC_LEFT, KC_DOWN, KC_RGHT
  ),
};

// Volume up/down on the encoder
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
    tap_code_delay(KC_VOLU, 10);
  }
  else {
    tap_code_delay(KC_VOLD, 10);
  }

  return true;
}

