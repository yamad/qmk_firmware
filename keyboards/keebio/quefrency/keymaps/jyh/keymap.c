#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1

#define GUI_GRV MT(MOD_LGUI, KC_GRV)  //  `
#define CTL_ESC MT(MOD_LCTL, KC_ESC)  //  Esc     Left Control
#define CTL_BSP MT(MOD_LCTL, KC_BSPC) //  Bkspce  Left Control
#define ALT_TAB MT(MOD_LALT, KC_TAB)  //  Tab     Left Alt


enum custom_keycodes {
	QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT_65_with_macro(
		KC_MUTE, KC_MPLY, GUI_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC, KC_HOME,
		KC_MPRV, KC_MNXT, KC_TAB , KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,
		KC_F1  , KC_F2  , CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGUP,
		KC_F3  , KC_F4  , KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
		KC_F5  , KC_F6  , KC_MEH , KC_LGUI, KC_LALT, CTL_BSP, ALT_TAB, KC_SPC,  KC_SPC, KC_RCTL, MO(_FN1), _______, KC_LEFT, KC_DOWN, KC_RGHT
		),

	[_FN1] = LAYOUT_65_with_macro(
		_______, HYPR(KC_Z), KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_DEL , KC_DEL , KC_INS,
		RGB_TOG, RGB_MOD, _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______, _______, _______, _______,
		KC_F7  , KC_F8  , _______, KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT, KC_MINS, KC_UNDS, KC_EQL , KC_PLUS, KC_BSLS, KC_PIPE, _______, _______, _______,
		KC_F9  , KC_F10 , _______, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, _______, _______,
		KC_F11 , KC_F12 , _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
		)
};

void encoder_update_user(uint8_t index, bool clockwise) {
	if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    else if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
