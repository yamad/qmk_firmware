
#include QMK_KEYBOARD_H
#include "drashna.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_wrapper(
     KC_ESC,  ________________NUMBER_LEFT________________,                       ________________NUMBER_RIGHT_______________, KC_MINS,
     KC_TAB , _________________QWERTY_L1_________________,                       _________________QWERTY_R1_________________, KC_BSLS,
     KC_C1R3, _________________QWERTY_L2_________________,                       _________________QWERTY_R2_________________, KC_QUOT,
     KC_MLSF, _________________QWERTY_L3_________________, ALT_APP,     OS_RGUI, _________________QWERTY_R3_________________, KC_MRSF,
                             LT(_LOWER,KC_GRV), KC_SPC,  KC_BSPC,         KC_DEL,  KC_ENT,  RAISE
  ),
  [_COLEMAK] = LAYOUT_wrapper(
     KC_ESC , ________________NUMBER_LEFT________________,                       ________________NUMBER_RIGHT_______________, KC_MINS,
     KC_TAB , _________________COLEMAK_L1________________,                       _________________COLEMAK_R1________________, KC_BSLS,
     KC_C1R3, _________________COLEMAK_L2________________,                       _________________COLEMAK_R2________________, KC_QUOT,
     KC_MLSF, _________________COLEMAK_L3________________, ALT_APP,     OS_RGUI, _________________COLEMAK_R3________________, KC_MRSF,
                             LT(_LOWER,KC_GRV), KC_SPC,  KC_BSPC,         KC_DEL,  KC_ENT,  RAISE
  ),
  [_DVORAK] = LAYOUT_wrapper(
     KC_ESC,  ________________NUMBER_LEFT________________,                       ________________NUMBER_RIGHT_______________, KC_MINS,
     KC_TAB , _________________DVORAK_L1_________________,                       _________________DVORAK_R1_________________, KC_BSLS,
     KC_C1R3, _________________DVORAK_L2_________________,                       _________________DVORAK_R2_________________, KC_QUOT,
     KC_MLSF, _________________DVORAK_L3_________________, ALT_APP,     OS_RGUI, _________________DVORAK_R3_________________, KC_MRSF,
                             LT(_LOWER,KC_GRV), KC_SPC,  KC_BSPC,         KC_DEL,  KC_ENT,  RAISE
  ),
  [_WORKMAN] = LAYOUT_wrapper(
     KC_ESC,  ________________NUMBER_LEFT________________,                       ________________NUMBER_RIGHT_______________, KC_MINS,
     KC_TAB , _________________WORKMAN_L1________________,                       _________________WORKMAN_R1________________, KC_BSLS,
     KC_C1R3, _________________WORKMAN_L2________________,                       _________________WORKMAN_R2________________, KC_QUOT,
     KC_MLSF, _________________WORKMAN_L3________________, ALT_APP,     OS_RGUI, _________________WORKMAN_R3________________, KC_MRSF,
                             LT(_LOWER,KC_GRV), KC_SPC,  KC_BSPC,         KC_DEL,  KC_ENT,  RAISE
  ),

  [_MODS] = LAYOUT_wrapper(
     _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
     KC_LSFT, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, KC_RSFT,
                                       _______, _______, _______,         _______, _______, _______
  ),

  [_GAMEPAD] = LAYOUT_wrapper(
     KC_ESC,  KC_NO,   KC_1,    KC_2,    KC_3,    KC_P,                          _______, _______, _______, _______, _______, _______,
     KC_F1,   KC_K,    KC_Q,    KC_W,    KC_E,    KC_R,                          _______, _______, _______, _______, _______, _______,
     KC_TAB,  KC_G,    KC_A,    KC_S,    KC_D,    KC_F,                          _______, _______, _______, _______, _______, _______,
     KC_LCTL, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_H,    TG_GAME,     _______, _______, _______, _______, _______, _______, _______,
                                       LOWER,   KC_V,    KC_SPC,          _______, _______, _______
  ),


  [_LOWER] = LAYOUT_wrapper(
     KC_F12,  _________________FUNC_LEFT_________________,                       _________________FUNC_RIGHT________________, KC_F11,
     KC_TILD, _________________LOWER_L1__________________,                       _________________LOWER_R1__________________, _______,
     _______, ___________________BLANK___________________,                       _________________LOWER_R2__________________, KC_PIPE,
     _______, ___________________BLANK___________________, _______,     _______, _________________LOWER_R3__________________, _______,
                                       _______, _______, _______,         _______, _______, _______
  ),

  [_RAISE] = LAYOUT_wrapper(
      KC_F12,  _________________FUNC_LEFT_________________,                      _________________FUNC_RIGHT________________, KC_F11,
      KC_GRV,  _________________RAISE_L1__________________,                      _________________RAISE_R1__________________, _______,
      _______, _________________RAISE_L2__________________,                      _________________RAISE_R2__________________, KC_BSLS,
      _______, _________________RAISE_L3__________________, _______,    _______, _________________RAISE_R3__________________, _______,
                                        _______, _______, _______,        _______, _______, _______
   ),

  [_ADJUST] = LAYOUT_wrapper(
      KC_MAKE, _______, _______, _______, _______, _______,                      _________________ADJUST_R1_________________, KC_RST,
      VRSN,    _________________ADJUST_L1_________________,                      KC_NUKE, _______, _______, _______, _______, EPRM,
      _______, _________________ADJUST_L2_________________,                      _________________ADJUST_R2_________________, TG_MODS,
      _______, _________________ADJUST_L3_________________, TG_GAME,    _______, _________________ADJUST_R3_________________, KC_MPLY,
                                        _______, _______, _______,        _______, _______, _______
   )

};


void matrix_init_keymap(void) {
  DDRD &= ~(1<<5);
  PORTD &= ~(1<<5);

  DDRB &= ~(1<<0);
  PORTB &= ~(1<<0);
}
