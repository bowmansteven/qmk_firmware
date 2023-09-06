#include QMK_KEYBOARD_H


#define _LAYER0 0
#define KC_QUIT LGUI(LCTL(KC_Q))
#define KC_THINGS LCTL(KC_SPC)
#define _LOWER 1

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    PASSWORD = SAFE_RANGE,
    LOWER,
};

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_LAYER0] = LAYOUT_3key_2us(
     KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_LBRC, KC_RBRC, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BACKSPACE, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_MINS, KC_EQL, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_QUIT, KC_B, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, PASSWORD, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_THINGS, KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_LGUI, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
 ),
 [_LOWER] = LAYOUT_3key_2us(
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_LBRC, KC_RBRC, KC_F6, KC_F7, KC_F8, KC_F9, KC_0, KC_BACKSPACE, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_MINS, KC_EQL, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_QUIT, KC_B, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, PASSWORD, KC_N, KC_M, KC_MPRV, KC_MNXT, KC_MUTE, KC_ENT, KC_THINGS, KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_LGUI, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
 )
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case PASSWORD:
        if (record->event.pressed) {
            // when keycode PASSWORD is pressed
            SEND_STRING("Collapse!04" SS_DELAY(100) SS_TAP(X_ENT));
        } else {
            // when keycode PASSWORD is released
        }
        break;
    case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
          } else {
            layer_off(_LOWER);
          }
          return false;
          break;
    }
    return true;
};
