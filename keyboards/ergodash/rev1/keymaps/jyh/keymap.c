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
#define GUI_ESC MT(MOD_LGUI, KC_ESC)  //  Esc     Meta
#define CTL_ESC MT(MOD_LCTL, KC_ESC)  //  Esc     Left Control
#define SFT_MIN MT(MOD_LSFT, KC_MINS) //  -       Left Shift
#define SFT_PLS MT(MOD_LSFT, KC_PLUS) //  +       Left Shift
#define MEH_LBC MT(MOD_MEH,  KC_LBRC) //  [       Meh
#define CTL_BSP MT(MOD_LCTL, KC_BSPC)  // Bkspce  Left Control
#define HPR_RBC MT(MOD_HYPR, KC_RBRC) //  ]       Hyper
#define HPR_ENT MT(MOD_HYPR, KC_ENT)  //  Enter   Hyper
#define SFT_EQL MT(MOD_RSFT, KC_EQL)  //  =       Right Shift
#define GUI_BSL MT(MOD_RGUI, KC_BSLS) //  \       Meta
#define GUI_F11 MT(MOD_LGUI, KC_F11)  //  F11     Meta
#define GUI_F12 MT(MOD_RGUI, KC_F12)  //  F12     Meta
#define MEH_TAB MT(MOD_MEH, KC_TAB)   //  Tab     Meh

#define CTL_DEL MT(MOD_LCTL, KC_DEL)  //  Del     Left Control
#define CTL_QUO MT(MOD_RCTL, KC_QUOT) //  '       Right Control



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Esc  |   1  |   2  |   3  |   4  |   5  |   -  |                    |   =  |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  `   |   Q  |   W  |   E  |   R  |   T  |   [  |                    |   ]  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  |  Tab |                    | Enter|   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Space|                    | RAlt |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Meh  |  GUI |  Alt | Lower|||||||| Bksp | LShft| Gui  |||||||| RShft| LAlt | Space|||||||| Raise| Down |  Up  | Enter|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
	GUI_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,                        KC_EQL , KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    GUI_BSL, \
    KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                        KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
	CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB,                         KC_ENT , KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, CTL_QUO, \
    SFT_MIN, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LCTL,                        KC_RALT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_EQL, \
	MEH_TAB, KC_LGUI, KC_LALT, LOWER,            CTL_BSP, KC_LSFT,KC_LGUI,        KC_RSFT,KC_LALT, KC_SPC,           RAISE,   KC_DOWN, KC_UP,   HPR_ENT  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |                    |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   !  |   @  |   #  |   $  |   %  |   {  |                    |   }  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |      | < M  | Play |  M > |      |      |                    |      |   <  |   v  |   ^  |   >  |   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |   +  |      | Vol- | Mute | Vol+ |      |      |                    |      |      |      |      | Home | PgUp |  _   |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Mou2 | Mou3 | Mou1 | LOWER||||||||      |      |      ||||||||      |      | Enter||||||||      | End  | PgDn |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,                        _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,                        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_COLN, KC_DQT , \
    _______, _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______,                        _______, _______, _______, _______, KC_HOME, KC_PGUP, _______, \
    KC_MS_BTN2, KC_MS_BTN3, KC_MS_BTN1, LOWER,   _______, _______,_______,        _______,_______, KC_ENT,           _______, KC_END,  KC_PGDN, _______  \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |                    |   =  |  F6  |  F7  |  F8  |  F9  |  F10 |   /  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   1  |   2  |   3  |   4  |   5  |      |                    |      |   6  |   7  |   7  |   8  |   9  |   *  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   <  |   ^  |   v  |   >  |      |      |                    |      |      |   4  |   4  |   5  |   6  |   -  |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |   7  |   8  |   9  |   0  |      |                    |      |      |   1  |   1  |   2  |   3  |   +  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |  Del |      ||||||||      |      |      |||||||| RAISE|   .  |   0  | Enter|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                         _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_SLSH, \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,                        _______, KC_6,    _______, KC_7,    KC_8,    KC_9,   KC_ASTR, \
    _______, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, _______, _______,                        _______, _______, _______, KC_4,    KC_5,    KC_6,   KC_MINS, \
    SFT_PLS, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, KC_1,    KC_2,    KC_3,   KC_PLUS, \
    _______, _______, _______,     _______,      KC_DEL,  _______,_______,        _______,_______, _______,      RAISE,       KC_DOT, KC_0,    KC_ENT   \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      | BL ON|  BRTG|  INC|   DEC|      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
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
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
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
