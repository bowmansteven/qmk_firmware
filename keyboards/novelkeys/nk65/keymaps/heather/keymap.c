// Copyright 2019 Yiancar
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

/* Custom keycodes */
enum custom_keycodes {
    PASSWORD = SAFE_RANGE,
    USERNAME
};

/* Macro handling */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case PASSWORD:
            if (record->event.pressed) {
                SEND_STRING_DELAY(
                    "steven.bowman"
                    SS_DELAY(100) SS_TAP(X_TAB)
                    "CollapseCollapse!17"
                    SS_DELAY(100) SS_TAP(X_ENT),
                    10
                );
            }
            return false;

        case USERNAME:
            if (record->event.pressed) {
                SEND_STRING_DELAY(
                    "heather.bowman@ventriclehealth.com"
                    SS_DELAY(300) SS_TAP(X_TAB)
                    SS_DELAY(300) SS_TAP(X_ENT)
                    SS_DELAY(750)
                    "September2016!B"
                    SS_DELAY(400) SS_TAP(X_ENT),
                    20
                );
            }
            return false;
    }
    return true;
}

/* Keymaps */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi( /* Base */
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT_65_ansi( /* FN */
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC, _______,
        _______, _______, _______, _______, _______, _______, _______, USERNAME, _______, _______, PASSWORD, _______, _______, QK_BOOT, _______,
        _______, RM_TOGG, _______, _______, RM_SATD, RM_SATU, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, RM_PREV, RM_NEXT, RM_HUED, RM_HUEU, _______, _______, RM_VALD, RM_VALU, RM_SPDD, RM_SPDU, _______,          _______, _______,
        KC_VOLU, KC_VOLD, KC_MUTE,                   _______,                            _______, _______, _______, _______, _______, _______
    )
};
