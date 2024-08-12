

#include QMK_KEYBOARD_H
#include "features/layer_lock.h"

enum layer_names {
  _BASE,
  _EXT,
  _SYM,
  _NUM,
  _FUNC,
};

enum custom_keycodes {
  LLOCK = SAFE_RANGE,
};

#define MO_EXT   MO(_EXT)
#define MO_SYM   MO(_SYM)
#define MO_NUM   MO(_NUM)
#define MO_FUNC   MO(_FUNC)

#define Z_BRM LALT_T(KC_Z)
#define X_BRM LGUI_T(KC_X)
#define C_BRM LSFT_T(KC_C)
#define V_BRM LCTL_T(KC_D)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
      XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                     KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT,  XXXXXXX,
      XXXXXXX,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                     KC_M,    KC_N,    KC_E,    KC_I,    KC_O,  XXXXXXX,
      XXXXXXX,    Z_BRM,   X_BRM,   C_BRM,   V_BRM,   KC_V,                     KC_K,    KC_H,  KC_COMM,  KC_DOT, KC_SLSH, MO_FUNC,
                                           KC_TAB, MO_EXT, KC_LSFT,    KC_SPC, MO_SYM, _______
  ),
  [_EXT] = LAYOUT_split_3x6_3(
      _______, KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,                      KC_HOME, KC_PGUP, KC_UP,   KC_PGDN,  XXXXXXX, LLOCK,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_END,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_DELETE, _______,
      _______, Z_BRM,   X_BRM,   C_BRM,   V_BRM, XXXXXXX,                      XXXXXXX, KC_BSPC, KC_TAB,  KC_DELETE,  XXXXXXX, _______,
                                          _______, _______, _______,    KC_ENT, _______, _______
      //                                           ^^^^^^^
  ),
  [_SYM] = LAYOUT_split_3x6_3(
      _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC,                     KC_EQL, XXXXXXX, XXXXXXX,  KC_COLN,  KC_SCLN, LLOCK,
      _______, XXXXXXX, KC_SLSH, KC_BSLS, KC_PIPE, KC_CIRC,                    KC_LABK, KC_LPRN, KC_LCBR, KC_LBRC,  KC_MINS, _______,
      _______, Z_BRM,   X_BRM,   C_BRM,   V_BRM, KC_AMPR,                      KC_RABK, KC_RPRN, KC_RCBR, KC_RBRC,  KC_UNDS, _______,
                                          _______, _______, _______,    _______, _______, _______
      //                                                                         ^^^^^^^
  ),
    [_NUM] = LAYOUT_split_3x6_3(
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PEQL, KC_7, KC_8, KC_9,  KC_PPLS, LLOCK,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PAST, KC_4, KC_5, KC_6,  KC_PMNS, _______,
      _______, Z_BRM,   X_BRM,   C_BRM,   V_BRM,   XXXXXXX,                        KC_0,      KC_1,   KC_2,   KC_3,   KC_PSLS, _______,
                                          _______, _______, _______,    _______, _______, _______
      //                                           ^^^^^^^                       ^^^^^^^
  ),
  [_FUNC] = LAYOUT_split_3x6_3(
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_F10, KC_F7, KC_F8, KC_F9,  XXXXXXX, LLOCK,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_F11, KC_F4, KC_F5, KC_F6,  XXXXXXX, _______,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_F12, KC_F1, KC_F2, KC_F3,  XXXXXXX, _______,
                                          _______, _______, _______,    _______, _______, _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _EXT, _NUM);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {


  if (!process_layer_lock(keycode, record, LLOCK)) {
    return false;
  }

  return true;
}
