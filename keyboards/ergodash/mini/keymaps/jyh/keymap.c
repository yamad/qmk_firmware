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
#define GUI_LBC MT(MOD_LGUI, KC_LBRC) //  [       Left Meta

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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Esc |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |   [  |                    |   ]  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Space|                    | Enter|   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|Delete|||||||| Bksp | Enter| Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    GUI_GRV, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                        KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    GUSH_BS, \
    CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB,                         KC_ENT,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    SFT_MIN, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LSFT,                        KC_RSFT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_EQL, \
    CTL_TAB, GUI_LBC, KC_LALT, KC_MEH,           LOWER,   CTL_BSP, KC_LALT,        KC_ENT,KC_SPC, RAISE,             KC_HYPR, KC_RALT, GUI_RBC, KC_ENT   \
  ),

  /* Lower
   * ,------------------------------------------------.                    ,------+-----------------------------------------.
   * |      |  !   |  @   |  #   |  $   |  %   |      |                    |      |  ^   |  &   |  *   |  (   |  )   |      |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * |      |  <M  | MPlay|  M>  |      |      |      |                    |      | Left | Down |  Up  | Right|      |      |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * |      | Vol- | Mute | Vol+ |      |      |      |                    |      | Home | PgDn | PgUp | End  |      |      |
   * |------+------+------+------+------+------+------+------.      ,------|------+------+------+------+------+------+------|
   * |MS_BT2|MS_BT3|MS_BT1|      ||||||||Adjust|      |      |      |      |      | RAISE||||||||      |      |      |      |
   * `-------------------------------------------------------.      `-------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,                        _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_HOME, KC_PGUP, _______,                        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
    _______, KC_VOLD, KC_MUTE, KC_VOLD, KC_END,  KC_PGDN, _______,                        _______, _______, _______, _______, _______, _______, _______, \
    KC_MS_BTN2, KC_MS_BTN3, KC_MS_BTN1, _______,   LOWER, _______, _______,       _______,_______, _______,          _______, _______, _______, _______ \
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

  /* Adjust */
  [_ADJUST] = LAYOUT(
    _______, RESET  , _______, _______, _______, _______,_______,                       _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
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
