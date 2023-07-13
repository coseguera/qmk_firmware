#include QMK_KEYBOARD_H

enum custom_keycodes {
  BKTS = SAFE_RANGE,
  BRCS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_planck_grid(
    KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,          XXXXXXX, XXXXXXX, KC_Y,          KC_U,        KC_I,           KC_O,          KC_P,
    KC_A,        KC_S,        KC_D,        KC_F,        KC_G,          XXXXXXX, XXXXXXX, KC_H,          KC_J,        KC_K,           KC_L,          ALT_T(KC_SCLN),
    SFT_T(KC_Z), CTL_T(KC_X), CTL_T(KC_C), GUI_T(KC_V), GUI_T(KC_B),   XXXXXXX, XXXXXXX, GUI_T(KC_N),   GUI_T(KC_M), CTL_T(KC_COMM), CTL_T(KC_DOT), RSFT_T(KC_SLSH),
    XXXXXXX,     XXXXXXX,     XXXXXXX,     BKTS,        LT(2, KC_ENT), XXXXXXX, XXXXXXX, LT(1, KC_SPC), KC_BSPC,     XXXXXXX,        XXXXXXX,       XXXXXXX
),
[1] = LAYOUT_planck_grid(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, BRCS,    _______, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
),
[2] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU,
    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX, XXXXXXX, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX
)
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_Z):
        case RSFT_T(KC_SLSH):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case BKTS:
        if (record->event.pressed) {
            SEND_STRING("[]"SS_TAP(X_LEFT));
        }
        break;
    case BRCS:
        if (record->event.pressed) {
            SEND_STRING("{}"SS_TAP(X_LEFT));
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {CTL_T(KC_C), GUI_T(KC_V), COMBO_END};
const uint16_t PROGMEM vb_combo[] = {GUI_T(KC_V), GUI_T(KC_B), COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM dotslash_combo[] = {CTL_T(KC_DOT), RSFT_T(KC_SLSH), COMBO_END};

combo_t key_combos[] = {
    COMBO(qw_combo, KC_GRV),
    COMBO(we_combo, KC_ESC),
    COMBO(sd_combo, KC_TAB),
    COMBO(df_combo, KC_MINS),
    COMBO(fg_combo, KC_UNDS),
    COMBO(cv_combo, KC_PLUS),
    COMBO(vb_combo, KC_EQL),
    COMBO(hj_combo, KC_DQT),
    COMBO(jk_combo, KC_QUOT),
    COMBO(dotslash_combo, KC_BSLS),
};