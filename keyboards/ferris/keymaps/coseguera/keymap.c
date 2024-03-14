#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
    KC_Q,        KC_W, KC_E, KC_R,           KC_T,          KC_Y,          KC_U,   KC_I,           KC_O,          KC_P,
    KC_A,        KC_S, KC_D, KC_F,           KC_G,          KC_H,          KC_J,   KC_K,           KC_L,          GUI_T(KC_SCLN),
    SFT_T(KC_Z), KC_X, KC_C, ALT_T(KC_V),    CTL_T(KC_B),   KC_N,          KC_M,   ALT_T(KC_COMM), CTL_T(KC_DOT), RSFT_T(KC_SLSH),
                             GUI_T(KC_MINS), LT(2, KC_ENT), LT(1, KC_SPC), KC_BSPC
),
[1] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    XXXXXXX, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
                               _______, _______, _______, _______
),
[2] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_MUTE, KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU,
    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,  KC_F12,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BSLS,
                               _______, _______, _______, KC_DEL
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

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[] = {
    COMBO(qw_combo, KC_GRV),
    COMBO(we_combo, KC_ESC),
    COMBO(sd_combo, KC_TAB),
    COMBO(df_combo, KC_EQL),
    COMBO(fg_combo, KC_PLUS),
    COMBO(hj_combo, KC_DQT),
    COMBO(jk_combo, KC_QUOT),
};
