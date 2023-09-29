#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_planck_grid(
    KC_GRV,         KC_Q,           KC_W,           KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,           KC_O,           KC_P,           KC_MINS,
    KC_EQL,         KC_A,           KC_S,           KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,           KC_L,           KC_SCLN,        KC_QUOT,
    KC_LSFT,        KC_Z,           KC_X,           KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,        KC_DOT,         KC_SLSH,        KC_RSFT,
    CTL_T(KC_VOLD), ALT_T(KC_VOLU), GUI_T(KC_MUTE), MO(2),   KC_BSPC, KC_ENT,  KC_SPC,  MO(1),   GUI_T(KC_LBRC), ALT_T(KC_RBRC), CTL_T(KC_BRID), KC_BRIU
),
[1] = LAYOUT_planck_grid(
    _______,        KC_1,           KC_2,           KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,           KC_9,           KC_0,           _______,
    _______,        KC_EXLM,        KC_AT,          KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,        KC_LPRN,        KC_RPRN,        _______,
    _______,        XXXXXXX,        XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,          KC_RGHT,        KC_BSLS,        _______,
    _______,        _______,        _______,        _______, _______, _______, _______, _______, GUI_T(KC_HOME), ALT_T(KC_PGDN), CTL_T(KC_PGUP), KC_END
),
[2] = LAYOUT_planck_grid(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,   KC_F5,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
    KC_F6,          KC_F7,          KC_F8,          KC_F9,   KC_F10,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
    XXXXXXX,        XXXXXXX,        RGB_TOG,        KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX, 
    XXXXXXX,        KC_VOLU,        XXXXXXX,        _______, KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX
)
};

const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};

combo_t key_combos[] = {
    COMBO(we_combo, KC_ESC),
    COMBO(sd_combo, KC_TAB),
};