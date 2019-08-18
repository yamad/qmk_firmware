#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

                                      //  Tap     Hold
                                      //  ------------------
// Left Side
#define GUI_GRV MT(MOD_LGUI, KC_GRV)  //  `       Meta
#define CTL_TAB MT(MOD_LCTL, KC_TAB)  //  Tab     Control
#define CTL_ESC MT(MOD_LCTL, KC_ESC)  //  Esc     Left Control
#define SFT_MIN MT(MOD_LSFT, KC_MINS) //  -       Left Shift
#define SFT_PLS MT(MOD_LSFT, KC_PLUS) //  +       Left Shift
#define CTL_TAB MT(MOD_LCTL, KC_TAB)  //  Tab     Left Control
#define GUI_LBC MT(MOD_LGUI, KC_LBRC) //  [       Left Gui
#define ALT_RBC MT(MOD_LALT, KC_RBRC) //  ]       Left Alt

// Middle / Thumbs
#define CTL_BSP MT(MOD_LCTL, KC_BSPC)  // Bkspce  Left Control
#define CTL_DEL MT(MOD_LCTL, KC_DEL)  //  Del     Left Control

// Right Side
#define GUSH_BS MT(MOD_RGUI | MOD_RSFT, KC_BSLS) //  \       Gui+Shift
#define CTL_QUO MT(MOD_RCTL, KC_QUOT) //  '       Right Control
#define SFT_EQL MT(MOD_RSFT, KC_EQL)  //  =       Right Shift
#define SFT_UND MT(MOD_RSFT, KC_UNDS) //  _       Right Shift
#define GUI_RBC MT(MOD_RGUI, KC_RBRC) //  ]       Right Meta
#define HPR_ENT MT(MOD_HYPR, KC_ENT)  //  Enter   Hyper

enum {
	TD_RGHT_ENT = 0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  `   |   Q  |   W  |   E  |   R  |   T  |  [   |                    |   ]  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  | Tab  |                    | Enter|   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |  -   |   Z  |   X  |   C  |   V  |   B  | Shift|                    | Shift|   N  |   M  |   ,  |   .  |   /  |  =   |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Tab  |   [  |   ]  | Super|||||||| Lower| Bksp | Ctrl |||||||| Alt  | Space| Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   *
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Gui  |   Q  |   W  |   E  |   R  |   T  |  [   |                    |   ]  |   Y  |   U  |   I  |   O  |   P  | Gui/Shift|
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  | Tab  |                    | Enter|   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Shift|                    | Shift|   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI | Meta | Super|||||||| Lower| Ctrl | Ctrl |||||||| Alt  | Space| Raise|||||||| Left | Down |  Up  | Enter|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    GUI_GRV, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                        KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    GUSH_BS, \
    CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB,                         KC_ENT,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    SFT_MIN, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LSFT,                        KC_RSFT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_EQL, \
    CTL_TAB, GUI_LBC, ALT_RBC, KC_MEH,           LOWER,   CTL_BSP, KC_LCTL,       KC_RALT,KC_SPC, RAISE,             KC_LEFT, KC_DOWN, KC_UP, TD(TD_RGHT_ENT) \
  ),

  /* Lower
   * ,------------------------------------------------.                    ,------+-----------------------------------------.
   * |      |  !   |  @   |  #   |  $   |  %   |      |                    |      |  ^   |  &   |  *   |  (   |  )   |      |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * |      |  -   |  '   |  `   |  =   |      |      |                    |      | Left | Down |  Up  | Right|      |      |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * |      |  _   |  "   |  ~   |  +   |      |      |                    |      | Home | PgDn | PgUp | End  |      |      |
   * |------+------+------+------+------+------+------+------.      ,------|------+------+------+------+------+------+------|
   * |MS_BT2|MS_BT3|MS_BT1|      ||||||||LOWER |      |      |      |      |      |Adjust||||||||      |      |      |      |
   * `-------------------------------------------------------.      `-------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,                        _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    _______, KC_MINS, KC_QUOT, KC_GRV,  KC_EQL,  KC_PGUP, _______,                        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
    _______, KC_UNDS, KC_DQUO, KC_TILD, KC_PLUS, KC_PGDN, _______,                        _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, \
    KC_MS_BTN2, KC_MS_BTN3, KC_MS_BTN1, _______,   LOWER, _______, _______,       _______,_______, _______,          _______, _______, _______, _______  \
  ),

  /* Raise
  * ,------------------------------------------------.                    ,------+-----------------------------------------.
  * |      |  1   |  2   |  3   |  4   |  5   |      |                    |      |  6   |  7   |  8   |  9   |  0   |      |
  * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
  * |      | Left |  Up  | Down | Right|  ;   |      |                    |      |  '   |  4   |  5   |  6   |  *   |      |
  * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
  * |      |  {   |  }   |  (   |  )   |  ,   |      |                    |      |  -   |  1   |  2   |  3   |  /   |  =   |
  * |------+------+------+------+------+------+------+------.      ,------|------+------+------+------+------+------+------|
  * |      |      |      |      ||||||||Adjust|      |      |      |      |      | RAISE||||||||   .  |  0   |  +   | Enter|
  * `-------------------------------------------------------.      `-------------------------------------------------------.
  */
  [_RAISE] = LAYOUT(
	_______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , _______,                        _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
	_______, KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT, KC_SCLN, _______,                        _______, KC_QUOT, KC_4   , KC_5   , KC_6   , KC_ASTR, _______,
	_______, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_COMM, _______,                        _______, KC_MINS, KC_1   , KC_2   , KC_3   , KC_SLSH, _______,
	_______, _______, _______, _______,          _______, _______, _______,       _______,_______, _______,          KC_DOT , KC_0   , KC_PLUS, _______
    ),

  /* Adjust
  * ,------------------------------------------------.                    ,------+-----------------------------------------.
  * |      | Reset|      |      |      |      |      |                    |      |      |  F7  |  F8  |  F9  | F10  | Del  |
  * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
  * |      |      | < M  | Play |  M > | Home |      |                    |      | PgUp |  F4  |  F5  |  F6  | F11  |      |
  * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
  * |      |      | Vol- | Mute | Vol+ | End  |      |                    |      | PgDn |  F1  |  F2  |  F3  | F12  |      |
  * |------+------+------+------+------+------+------+------.      ,------|------+------+------+------+------+------+------|
  * |      |      |      |      ||||||||ADJUST|      |      |      |      |      |ADJUST||||||||      |      |      |      |
  * `-------------------------------------------------------.      `-------------------------------------------------------.
  */
  [_ADJUST] = LAYOUT(
    _______, RESET  , _______, _______, _______, _______,_______,                       _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL , \
    _______, _______, KC_MPRV, KC_MPLY, KC_MNXT,KC_HOME, _______,                       _______, KC_PGUP, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______, \
    _______, _______, KC_VOLD, KC_MUTE, KC_VOLU,KC_END,  _______,                       _______, KC_PGDN, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_RGHT_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_ENT, KC_RGHT)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
