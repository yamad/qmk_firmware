#include "levinson.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3																/* Symbols, Media */
#define _RAISE 4																/* Numbers, Arrows */
#define _FUNC  5																/* Function Keys */
#define _NUMS  6																/* Numpad */
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define KC_ KC_TRNS
#define XX  KC_NO
#define ______ KC_TRNS
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// tap toggle numpad on
#define NUMPAD TT(_NUMS)

// Mod Tap Definitions
// -------------------
                                      //  Tap     Hold
                                      //  ------------------
#define CTL_ESC MT(MOD_LCTL, KC_ESC)  //  Esc     Left Control
#define SFT_ENT MT(MOD_RSFT, KC_ENT)  //  Enter   Right Shift
#define CTL_SPC MT(MOD_LCTL, KC_SPC)  //  Space   Left Control
#define ALT_SPC MT(MOD_LALT, KC_SPC)  //  Space   Left Alt
#define ALT_BSP MT(MOD_LALT, KC_BSPC) //  Bkspace Left Alt
#define HPR_TAB MT(MOD_HYPR, KC_TAB)  //  Tab     Hyper (Super+Ctrl+Alt+Shift)
#define HPR_GRV MT(MOD_HYPR, KC_GRV)  //  `       Hyper
#define HPR_TIL MT(MOD_HYPR, KC_TILD) //  ~       Hyper
#define MEH_TIL MT(MOD_MEH,  KC_GRV)  //  `       Meh (Ctrl+Alt+Shift)
#define SFT_MIN MT(MOD_LSFT, KC_MINS) //  -       Left Shift
#define NPD_UND LT(_NUMS,    KC_UNDS) //  _       Layer Numpad
#define FNC_PIP LT(_FUNC,    KC_PIPE) //  |       Layer Function Keys

#define CTL_DEL MT(MOD_LCTL, KC_DEL)  //  Del     Left Control
#define CTL_QOT MT(MOD_LCTL, KC_QUOT) //  '       Right Control
#define CTL_BSL MT(MOD_RCTL, KC_BSLS) //  \       Right Control
#define CTL_PIP MT(MOD_LCTL, KC_PIPE) //  |       Right Control

// Redefine for KC_KEYMAP
#define KC_CTL_BSL CTL_BSL
#define KC_CTL_PIP CTL_PIP
#define KC_CTL_DEL CTL_DEL
#define KC_HPR_TIL HPR_TIL
#define KC_HPR_GRV HPR_GRV


// Tap Dance Declarations
// ----------------------
enum {
				TD_S1,
				TD_S2,
				TD_S3,
				TD_S4,
				TD_S5,
				TD_S6,
				TD_S7,
				TD_S8,
				TD_S9,
				TD_S0
};

#define KC_TDS1 TD(TD_S1)
#define KC_TDS2 TD(TD_S2)
#define KC_TDS3 TD(TD_S3)
#define KC_TDS4 TD(TD_S4)
#define KC_TDS5 TD(TD_S5)
#define KC_TDS6 TD(TD_S6)
#define KC_TDS7 TD(TD_S7)
#define KC_TDS8 TD(TD_S8)
#define KC_TDS9 TD(TD_S9)
#define KC_TDS0 TD(TD_S0)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,-----------------------------------------.    ,-----------------------------------------.
 * | Tab  |  Q   |  W   |  E   |  R   |  T   |    |  Y   |  U   |  I   |  O   |  P   | Bksp |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Esc  |  A   |  S   |  D   |  F   |  G   |    |  H   |  J   |  K   |  L   |  ;   |  '   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |  -   |  Z   |  X   |  C   |  V   |  B   |    |  N   |  M   |  ,   |  .   |  /   | Enter|
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Numpd| Hyper| Meta | Alt  | Lower| Spc  |    | Spc  | Raise| Alt  | Meta | Meh  |  \   |
 * `-----------------------------------------'    `-----------------------------------------'
 *
 * with Hold (Emacs-oriented)
 * ,-----------------------------------------.    ,-----------------------------------------.
 * | Hyper|      |      |      |      |      |    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |      |    |      |      |      |      |      | Ctrl |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |    |      |      |      |      |      | Shift|
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      | Ctrl |    | Alt  |      |      |      |      | Func |
 * `-----------------------------------------'    `-----------------------------------------'
 */
				[_QWERTY] = KEYMAP(
								HPR_TAB, KC_Q   , KC_W   , KC_E   , KC_R , KC_T   ,    KC_Y   , KC_U , KC_I   , KC_O   , KC_P   , KC_BSPC,
								CTL_ESC, KC_A   , KC_S   , KC_D   , KC_F , KC_G   ,    KC_H   , KC_J , KC_K   , KC_L   , KC_SCLN, CTL_QOT,
								SFT_MIN, KC_Z   , KC_X   , KC_C   , KC_V , KC_B   ,    KC_N   , KC_M , KC_COMM, KC_DOT , KC_SLSH, SFT_ENT,
								NUMPAD , KC_HYPR, KC_LGUI, KC_LALT, LOWER, CTL_SPC,    ALT_SPC, RAISE, KC_RALT, KC_RGUI, KC_MEH , FNC_PIP
								),


/* Raise (* keys are shifted on double tap)
 * ,-----------------------------------------.    ,-----------------------------------------.
 * |  `   |  1*  |  2*  |  3*  |  4*  |  5*  |    |  6*  |  7*  |  8*  |  9*  |  0*  |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |  <   | Left | Right|  Up  |  (   |    |  )   |  -   |  =   |  [   |  ]   |  |   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |  >   |   *  |   /  | Down |  {   |    |  }   |  _   |  +   |  .   |  /   |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * `-----------------------------------------'    `-----------------------------------------'
 */
				[_RAISE] = KC_KEYMAP(
								HPR_GRV,TDS1,TDS2,TDS3,TDS4,TDS5,     TDS6,TDS7,TDS8,TDS9,TDS0,       ,
               , LT ,LEFT,RGHT, UP ,LPRN,     RPRN,MINS, EQL,LBRC,RBRC,CTL_PIP,
               , GT ,ASTR,SLSH,DOWN,LCBR,     RCBR,UNDS,PLUS,    ,    ,       ,
								       ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,
								),

/* Lower
 * ,-----------------------------------------.    ,-----------------------------------------.
 * |  ~   |  !   |  @   |  #   |  $   |  %   |    |  ^   |  &   |  *   |  (   |  )   |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Del  | Vol+ | Mute | Play | PgUp |  :   |    |  '   |  -   |  <   |  >   |  ?   |  \   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      | Vol- | < M  |  M > | PgDn |  ;   |    |  "   |  =   |  ,   |  .   |  /   |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * `-----------------------------------------'    `-----------------------------------------'
 */
				[_LOWER] = KC_KEYMAP(
								HPR_TIL,EXLM, AT ,HASH,DLR , PERC  ,     CIRC,AMPR,ASTR,LPRN,RPRN,       ,
								CTL_DEL,VOLU,MUTE,MPLY,PGUP, COLN  ,     QUOT,MINS, LT , GT ,QUES,CTL_BSL,
								       ,VOLD,MPRV,MNXT,PGDN, SCLN  ,     DQUO,EQL ,COMM, DOT,SLSH,       ,
								       ,    ,    ,    ,    ,       ,         ,    ,    ,    ,    ,
								),

				[_FUNC] = KC_KEYMAP(
// ,----+----+----+----+----+----.    ,----+----+----+----+----+----.
								, F1 , F2 , F3 , F4 , F5 ,      F6 , F7 , F8 , F9 , F10,    ,
// |----+----+----+----+----+----|    |----+----+----+----+----+----|
								, F11, F12, F13, F14, F15,      F16, F17, F18, F19, F20,    ,
// |----+----+----+----+----+----|    |----+----+----+----+----+----|
								, F21, F22, F23, F24, NO ,      NO , NO , NO , NO , NO ,    ,
// |----+----+----+----+----+----|    |----+----+----+----+----+----|
								,    ,    ,    ,    , SPC,     SPC ,    ,    ,    ,    ,
// `----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

				[_NUMS] = KC_KEYMAP(
// ,----+----+----+----+----+----.    ,----+----+----+----+----+----.
								, 1  , 2  , 3  , 4  , 5  ,      6  , 7  , 8  , 9  ,SLSH,    ,
// |----+----+----+----+----+----|    |----+----+----+----+----+----|
								,CAPS, INS,HOME,PGUP,LPRN,     RPRN, 4  , 5  , 6  ,ASTR,    ,
// |----+----+----+----+----+----|    |----+----+----+----+----+----|
								,NLCK, DEL, END,PGDN,SCLN,     COMM, 1  , 2  , 3  ,MINS,    ,
// |----+----+----+----+----+----|    |----+----+----+----+----+----|
								,    ,    ,    ,    , SPC,      SPC, 0  ,DOT ,EQL ,PLUS,
// `----+----+----+----+----+----'    `----+----+----+----+----+----'
								),

				[_ADJUST] = KEYMAP(
// ,-------+--------+--------+--------+--------+--------.   ,-------+--------+--------+--------+--------+--------.
		   RESET , _______,  KC_UP , _______, _______, _______,    _______, _______, _______, _______, _______, KC_DEL , \
// |-------+--------+--------+--------+--------+--------|   |-------+--------+--------+--------+--------+--------|
			 _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,    BL_TOGG, BL_STEP, _______, _______, _______, _______, \
// |-------+--------+--------+--------+--------+--------|   |-------+--------+--------+--------+--------+--------|
		  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, \
// |-------+--------+--------+--------+--------+--------|   |-------+--------+--------+--------+--------+--------|
		  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______  \
// `-------+--------+--------+--------+--------+--------'   `-------+--------+--------+--------+--------+--------,
		)

/*
 * ,-----------------------------------------.    ,-----------------------------------------.
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * `-----------------------------------------'    `-----------------------------------------'
 */
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
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
  }
  return true;
}

// Double-tap N sends Shift-N for numbers
// This supports XMonad's keybindings where:
//   * Mod-# move focus to workspace #
//   * Mod-Shift-# moves window to workspace #
qk_tap_dance_action_t tap_dance_actions[] = {
				[TD_S1] = ACTION_TAP_DANCE_DOUBLE(KC_1, S(KC_1)),
				[TD_S2] = ACTION_TAP_DANCE_DOUBLE(KC_2, S(KC_2)),
				[TD_S3] = ACTION_TAP_DANCE_DOUBLE(KC_3, S(KC_3)),
				[TD_S4] = ACTION_TAP_DANCE_DOUBLE(KC_4, S(KC_4)),
				[TD_S5] = ACTION_TAP_DANCE_DOUBLE(KC_5, S(KC_5)),
				[TD_S6] = ACTION_TAP_DANCE_DOUBLE(KC_6, S(KC_6)),
				[TD_S7] = ACTION_TAP_DANCE_DOUBLE(KC_7, S(KC_7)),
				[TD_S8] = ACTION_TAP_DANCE_DOUBLE(KC_8, S(KC_8)),
				[TD_S9] = ACTION_TAP_DANCE_DOUBLE(KC_9, S(KC_9)),
				[TD_S0] = ACTION_TAP_DANCE_DOUBLE(KC_0, S(KC_0)),
};
