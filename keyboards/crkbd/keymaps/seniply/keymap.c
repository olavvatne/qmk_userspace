

#include QMK_KEYBOARD_H

enum layer_names {
  _BASE,
  _EXT,
  _SYM,
  _NUM,
  _FUNC,
};

os_variant_t current_os = OS_UNSURE;

#define MO_EXT   MO(_EXT)
#define MO_SYM   MO(_SYM)
#define MO_NUM   MO(_NUM)
#define MO_FUNC   MO(_FUNC)

#define GUI_Z GUI_T(KC_Z)
#define ALT_X ALT_T(KC_X)
#define CTL_C CTL_T(KC_C)
#define SFT_D SFT_T(KC_D)

#define SFT_H SFT_T(KC_H)
#define CTL_COMM CTL_T(KC_COMM)
#define ALT_DOT ALT_T(KC_DOT)
#define GUI_SLSH GUI_T(KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
      XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,XXXXXXX,
      XXXXXXX,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                     KC_M,    KC_N,    KC_E,    KC_I,    KC_O,  XXXXXXX,
      XXXXXXX,    GUI_Z ,  ALT_X,   CTL_C,   SFT_D,   KC_V,                     KC_K,    SFT_H,   CTL_COMM,ALT_DOT, GUI_SLSH,MO_FUNC,
                                           KC_TAB, MO_EXT, KC_LSFT,    KC_SPC, MO_SYM, _______
  ),
  [_EXT] = LAYOUT_split_3x6_3(
      _______, KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,                      KC_HOME, KC_PGUP, KC_UP,   KC_PGDN,  XXXXXXX, _______,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_END,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_DELETE, _______,
      _______, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX,                      XXXXXXX, KC_BSPC, KC_TAB,  KC_DELETE,  XXXXXXX, _______,
                                          _______, _______, _______,    KC_ENT, _______, _______
      //                                           ^^^^^^^
  ),
  [_SYM] = LAYOUT_split_3x6_3(
      _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC,                     KC_EQL, XXXXXXX, XXXXXXX,  KC_COLN,  KC_SCLN, _______,
      _______, XXXXXXX, KC_SLSH, KC_BSLS, KC_PIPE, KC_CIRC,                    KC_LABK, KC_LPRN, KC_LCBR, KC_LBRC,  KC_MINS, _______,
      _______, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, KC_AMPR,                      KC_RABK, KC_RPRN, KC_RCBR, KC_RBRC,  KC_UNDS, _______,
                                          _______, _______, _______,    _______, _______, _______
      //                                                                         ^^^^^^^
  ),
    [_NUM] = LAYOUT_split_3x6_3(
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PEQL, KC_7, KC_8, KC_9,  KC_PPLS, _______,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PAST, KC_4, KC_5, KC_6,  KC_PMNS, _______,
      _______, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                        KC_0,      KC_1,   KC_2,   KC_3,   KC_PSLS, _______,
                                          _______, _______, _______,    _______, _______, _______
      //                                           ^^^^^^^                       ^^^^^^^
  ),
  [_FUNC] = LAYOUT_split_3x6_3(
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_F10, KC_F7, KC_F8, KC_F9,  XXXXXXX, _______,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_F11, KC_F4, KC_F5, KC_F6,  XXXXXXX, _______,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_F12, KC_F1, KC_F2, KC_F3,  XXXXXXX, _______,
                                          _______, _______, _______,    _______, _______, _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _EXT, _NUM);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {

  return true;
}


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("BASE\n"), false);
            break;
        case _EXT:
            oled_write_P(PSTR("EXT\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("SYM\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("NUM\n"), false);
            break;
        case _FUNC:
            oled_write_P(PSTR("FUNC\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    oled_write_P(PSTR("OS: "), false);
    switch (current_os) {
        case OS_MACOS:
            oled_write_ln_P(PSTR("macOS"), false);
            break;
        case OS_IOS:
            oled_write_ln_P(PSTR("iOS"), false);
            break;
        case OS_WINDOWS:
            oled_write_ln_P(PSTR("Win"), false);
            break;
        case OS_LINUX:
            oled_write_ln_P(PSTR("Linux"), false);
            break;
        case OS_UNSURE:
        default:
            oled_write_ln_P(PSTR("?"), false);
            break;
    }

    return false;
}
#endif

#ifdef OS_DETECTION_ENABLE
bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }

    current_os = detected_os;
    return true;
}
#endif
