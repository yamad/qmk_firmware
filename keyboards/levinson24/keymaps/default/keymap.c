#include "levinson24.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

#define SFT_ENT MT(MOD_RSFT, KC_ENT)  //  Enter/Right Shift

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  MKITPNK,						/* toggle pink/blue LEDs */
  DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

#define DREC_1  DYN_REC_START1
#define DREC_2  DYN_REC_START2
#define DPLAY_1 DYN_MACRO_PLAY1
#define DPLAY_2 DYN_MACRO_PLAY2
#define DSTOP   DYN_REC_STOP

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = KEYMAP(										    \
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      \
		KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      \
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      \
		ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   RAISE      \
		),
	[_LOWER] = KEYMAP(										    \
		KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,   \
		KC_H,    KC_J,    KC_K   , KC_L,    KC_SCLN, KC_QUOT,   \
		KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT,   \
		_______, _______, _______, _______, _______, _______	\
		),
	[_RAISE] = KEYMAP(											\
		KC_F7,   KC_F8,   KC_F9,   KC_7,    KC_8,    KC_9,		\
		KC_F4,   KC_F5,   KC_F6,   KC_4,    KC_5,    KC_6,		\
		KC_F1,   KC_F2,   KC_F3,   KC_1,    KC_2,    KC_3,	    \
		KC_LSFT, _______, _______, KC_0,    KC_DOT,  _______	\
		),
	[_ADJUST] =  KEYMAP(    									\
		BL_STEP, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_M_P,	\
		XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, MKITPNK,	\
		XXXXXXX, DREC_1,  DPLAY_1, DREC_2,  DPLAY_2, DSTOP,	    \
		_______, _______, _______, _______, _______, _______	\
		)
};

void persistent_default_layer_set(uint16_t default_layer) {
	eeconfig_update_default_layer(default_layer);
	default_layer_set(default_layer);
}

/* toggle pink/blue underglow LEDs,
 * inspired by Disney's Sleeping Beauty */
void make_it_pink_blue(void) {
	uint16_t blue_hue = 210;
	uint16_t pink_hue = 315;

	/* key is pressed */
	uint16_t hue = rgblight_get_hue();
	uint8_t sat = rgblight_get_sat();
	uint8_t val = rgblight_get_val();

	if (hue != blue_hue)
		rgblight_sethsv(blue_hue, sat, val);
	else
		rgblight_sethsv(pink_hue, sat, val);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (!process_record_dynamic_macro(keycode, record)) {
		return false;
	}
	switch (keycode) {
    case QWERTY:
		if (record->event.pressed) {
			persistent_default_layer_set(1UL<<_QWERTY);
		}
		return false;
		break;
    case LOWER:
		if (record->event.pressed) {
			layer_on(_LOWER);
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
		} else {
			layer_off(_LOWER);
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
		}
		return false;
		break;
    case RAISE:
		if (record->event.pressed) {
			layer_on(_RAISE);
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
		} else {
			layer_off(_RAISE);
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
		}
		return false;
		break;
    case ADJUST:
		if (record->event.pressed) {
			layer_on(_ADJUST);
		} else {
			layer_off(_ADJUST);
		}
		return false;
		break;
	case MKITPNK:
		if (record->event.pressed)
			make_it_pink_blue();
		return false;
		break;
	}
	return true;
}
