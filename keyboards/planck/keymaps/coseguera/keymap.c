#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_planck_grid(
    KC_Q,        KC_W,    KC_E,          KC_R,           KC_T,          XXXXXXX, XXXXXXX, KC_Y,          KC_U,    KC_I,           KC_O,          KC_P,
    KC_A,        KC_S,    KC_D,          KC_F,           KC_G,          XXXXXXX, XXXXXXX, KC_H,          KC_J,    KC_K,           KC_L,          GUI_T(KC_SCLN),
    SFT_T(KC_Z), KC_X,    KC_C,          ALT_T(KC_V),    CTL_T(KC_B),   XXXXXXX, XXXXXXX, KC_N,          KC_M,    ALT_T(KC_COMM), CTL_T(KC_DOT), RSFT_T(KC_SLSH),
    XXXXXXX,     XXXXXXX, MEH_T(KC_EQL), GUI_T(KC_MINS), LT(2, KC_ENT), XXXXXXX, XXXXXXX, LT(1, KC_SPC), KC_BSPC, MS_BTN1,        XXXXXXX,       XXXXXXX
),
[1] = LAYOUT_planck_grid(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_LSFT, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
    XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
),
[2] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, XXXXXXX, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, KC_BRIU,
    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX, XXXXXXX, MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, KC_BRID,
    KC_MUTE, KC_VOLD, KC_VOLU, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BSLS,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,  _______, XXXXXXX, XXXXXXX, MS_BTN1, MS_BTN2,  XXXXXXX, XXXXXXX, XXXXXXX
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

const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[] = {
    COMBO(we_combo, KC_ESC),
    COMBO(rt_combo, KC_GRV),
    COMBO(sd_combo, KC_TAB),
    COMBO(hj_combo, KC_DQT),
    COMBO(jk_combo, KC_QUOT),
};
