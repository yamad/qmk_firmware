#include "ergo42.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_jp.h"       // qmk_firmware-master/quantum/keymap_extras/keymap_jp.h ���{��L�[�{�[�h�ݒ�p
#include <sendstring_jis.h>  // macro sendstring for jis keyboard �}�N�������񑗐M���ɓ��{��L�[�{�[�h�ݒ�ł̕����������

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _GAME 3
#define _ADJUST 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  MCR1,
  MCR2,
  MCR3,
  DYNAMIC_MACRO_RANGE,
  WN_SCLN,          // �^�b�v��JIS�́u:�v  �V�t�g��JIS�́u;�v (Windows)
};

// Use Dynamic macro
#include "dynamic_macro.h"

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_LOWR LT(_LOWER, KC_MHEN)    // �^�b�v�Ŗ��ϊ�   �z�[���h��Lower
#define KC_RASE LT(_RAISE, KC_HENK)    // �^�b�v�ŕϊ�     �z�[���h��Raise
#define KC_ALPS LALT(KC_PSCR)          // Alt + PrintScreen
#define KC_LSLP MT(MOD_LSFT, JP_LPRN)  // �^�b�v��(        �z�[���h�ō�Shift
#define KC_RSRP MT(MOD_RSFT, JP_RPRN)  // �^�b�v��)        �z�[���h�ŉEShift
#define KC_ALTB MT(MOD_LALT, KC_TAB)   // �^�b�v��TAB      �z�[���h�ō�ALT
#define KC_ESCA LT(_ADJUST,KC_ESC)     // �^�b�v��ESC      �z�[���h��ADJUST���C���[on


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-------------------------------------------------------.   ,-------------------------------------------------------.
 * |Tab/Alt|   Q   |   W   |   E   |   R   |   T   |   -   |   |   ~   |   Y   |   U   |   I   |   O   |   P   | BSPC  |
 * |-------+-------+-------+-------+-------+-------+-------|   |-------+-------+-------+-------+-------+-------+-------|
 * | Ctrl  |   A   |   S   |   D   |   F   |   G   |   [   |   |   ]   |   H   |   J   |   K   |   L   |   :   |   '   |
 * |-------+-------+-------+-------+-------+-------+-------|   |-------+-------+-------+-------+-------+-------+-------|
 * | (/Sft |   Z   |   X   |   C   |   V   |   B   |  F2   |   |  Home |   N   |   M   |   ,   |   .   |   /   | )/Sft |
 * |-------+-------+-------+-------+-------+-------+-------|   |-------+-------+-------+-------+-------+-------+-------|
 * |  TT   |  GUI  |   \   | Esc/  | LOWER | Enter |  Del  |   |  End  | Space | RAISE | Left  | Down  |   Up  | Right |
 * |(_GAME)|       |       |_ADJUST| ���ϊ�|       |       |   |       |       | �ϊ�  |       |       |       |       |
 * `-------------------------------------------------------'   `-------------------------------------------------------'
 */

[_QWERTY] = KEYMAP( \
  KC_ALTB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,       JP_TILD, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    JP_LBRC,       JP_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    WN_SCLN, JP_QUOT, \
  KC_LSLP,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_F2,         KC_HOME, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSRP, \
  TT(_GAME),KC_LGUI, JP_YEN,  KC_ESCA, KC_LOWR, KC_ENT,  KC_DEL,        KC_END,  KC_SPC,  KC_RASE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* LOWER
 * ,-------------------------------------------------------.   ,-------------------------------------------------------.
 * |Tab/Alt|   1   |   2   |   3   |   4   |   5   |   6   |   |  Esc  |   7   |   8   |   9   |   O   |   =   | BSPC  |
 * |-------+-------+-------+-------+-------+-------+-------|   |-------+-------+-------+-------+-------+-------+-------|
 * | Ctrl  |  F1   |  F2   |  F3   |  F4   |  F5   |  F6   |   |  F2   |   4   |   5   |   6   |   -   |   /   | Enter |
 * |-------+-------+-------+-------+-------+-------+-------|   |-------+-------+-------+-------+-------+-------+-------|
 * | Shift |  F7   |  F8   |  F9   |  F10  |  F11  |  F12  |   |  Home |   1   |   2   |   3   |   +   |   *   | Shift |
 * |-------+-------+-------+-------+-------+-------+-------|   |-------+-------+-------+-------+-------+-------+-------|
 * |XXXXXXX|  GUI  |XXXXXXX|  Esc  |       | Enter |  Del  |   |  End  |   0   |   .   | Left  | Down  |   Up  | Right |
 * `-------------------------------------------------------'   `-------------------------------------------------------'
 */

[_LOWER] = KEYMAP( \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,          KC_ESC,  KC_7,    KC_8,    KC_9,    KC_0,    JP_EQL,  _______, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,         KC_F2,   KC_P4,   KC_P5,   KC_P6,   KC_PMNS, KC_PSLS, KC_ENT,  \
  KC_LSFT, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,        _______, KC_P1,   KC_P2,   KC_P3,   KC_PPLS, KC_PAST, KC_RSFT, \
  _______, _______, XXXXXXX, KC_ESC,  _______, _______, _______,       _______, KC_P0,   KC_PDOT, _______, _______, _______, _______ \
),

/* RAISE
 * ,-------------------------------------------------------.   ,-------------------------------------------------------.
 * |Tab/Alt|   !   |   @   |   #   |   $   |   %   |   _   |   |   `   |   ^   |   &   |  Ins  |   \   |PrntScr| BSPC  |
 * |-------+-------+-------+-------+-------+-------+-------|   |-------+-------+-------+-------+-------+-------+-------|
 * | Ctrl  |XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|   {   |   |   }   | Left  | Down  |   Up  | Right |   ;   |   "   |
 * |-------+-------+-------+-------+-------+-------+-------|   |-------+-------+-------+-------+-------+-------+-------|
 * | Shift |XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|   |PageUp |XXXXXXX|XXXXXXX|   <   |   >   |   ?   | Shift |
 * |-------+-------+-------+-------+-------+-------+-------|   |-------+-------+-------+-------+-------+-------+-------|
 * |XXXXXXX|  GUI  |   |   |  Esc  |XXXXXXX| Enter |  Del  |   |PageDwn| Space |       | Left  | Down  |   Up  | Right |
 * `-------------------------------------------------------'   `-------------------------------------------------------'
 */

[_RAISE] = KEYMAP( \
  _______, KC_EXLM, JP_AT,   KC_HASH, KC_DLR,  KC_PERC, JP_UNDS,       JP_GRV,  JP_CIRC, JP_AMPR, KC_INS,  JP_YEN,  KC_ALPS, _______, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, JP_LBRC,       JP_RBRC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SCLN, JP_DQT,  \
  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_PGUP, XXXXXXX, XXXXXXX, KC_LT,   KC_GT,   KC_QUES, KC_RSFT, \
  _______, _______, KC_PIPE, KC_ESC,  XXXXXXX, _______, _______,       KC_PGDN, _______, _______, _______, _______, _______, _______ \
),

/* GAME
 * ,-------------------------------------------------------.   ,-------------------------------------------------------.
 * |  Esc  |   Q   |   W   |   E   |   R   |   T   |PrntScr|   |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------|   |-------+-------+-------+-------+-------+-------+-------|
 * | Ctrl  |   A   |   S   |   D   |   F   |   G   |  F5   |   |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------|   |-------+-------+-------+-------+-------+-------+-------|
 * | Shift |   Z   |   X   |   C   |   V   |   B   |  F2   |   |PageUp |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------|   |-------+-------+-------+-------+-------+-------+-------|
 * |       |  GUI  |  Tab  |  Alt  | Space | Enter |  Del  |   |PageDwn| Space |XXXXXXX| Left  | Down  |   Up  | Right |
 * `-------------------------------------------------------'   `-------------------------------------------------------'
 */
[_GAME] = KEYMAP( \
  KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_ALPS,       _______, _______, _______, _______, _______, _______, _______, \
  KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    JP_LBRC,       _______, _______, _______, _______, _______, _______, _______, \
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_F2,         KC_PGUP, _______, _______, _______, _______, _______, _______, \
  _______,  KC_LGUI, KC_TAB,  KC_LALT, KC_SPC,  KC_ENT,  KC_DEL,        KC_PGDN, _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* ADJUST
 * ,-------------------------------------------------------.   ,-------------------------------------------------------.
 * |RGB_TOG| MCR1  | MCR2  | MCR3  |XXXXXXX|XXXXXXX|XXXXXXX|   |XXXXXXX|PLAY_M1|PLAY_M2|REC_M1 |REC_M2 |STP_REC| BSPC  |
 * |-------+-------+-------+-------+-------+-------+-------|   |-------+-------+-------+-------+-------+-------+-------|
 * | RESET |RGB_MOD|_PLAIN |_BREATH|RGB_HuI|RGB_SaI|RGB_VaI|   |XXXXXXX|QWERTY |XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|
 * |-------+-------+-------+-------+-------+-------+-------|   |-------+-------+-------+-------+-------+-------+-------|
 * | Shift |_RAINBW|_SNAKE |_GRADIE|RGB_HuD|RGB_SaD|RGB_VaD|   |XXXXXXX| M-PLAY|M-MUTE |VOL_DWN|VOL_UP |PREV_TR|NEXT_TR|
 * |-------+-------+-------+-------+-------+-------+-------|   |-------+-------+-------+-------+-------+-------+-------|
 * | DEBUG |XXXXXXX|XXXXXXX|       |XXXXXXX|XXXXXXX|XXXXXXX|   |XXXXXXX|XXXXXXX|XXXXXXX| Left  | Down  |   Up  | Right |
 * `-------------------------------------------------------'   `-------------------------------------------------------'
 */
[_ADJUST] = KEYMAP( \
  RGB_TOG,  MCR1,    MCR2,    MCR3,    XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, DYN_REC_START1, DYN_REC_START2, DYN_REC_STOP, KC_BSPC, \
  RESET,    RGB_MOD, RGB_M_P, RGB_M_B, RGB_HUI, RGB_SAI, RGB_VAI,       XXXXXXX, QWERTY,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  KC_LSFT,  RGB_M_R, RGB_M_SN,RGB_M_G, RGB_HUD, RGB_SAD, RGB_VAD,       XXXXXXX, KC_MPLY, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, \
  DEBUG,    XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool     lshift = false;
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
    case WN_SCLN: // �R�����u;:�v
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        if (lshift) {
          unregister_code(KC_LSFT);
          register_code(JP_SCLN);
          unregister_code(JP_SCLN);
        } else {
          register_code(JP_COLN);
          unregister_code(JP_COLN);
        }
      }
      return false;
      break;
    case MCR1:
      if (record->event.pressed) {
        SEND_STRING("hogehoge"); // ���M������
      }
      return false;
      break;
    case MCR2:
      if (record->event.pressed) {
        SEND_STRING("hogehogehoge"SS_TAP(X_ENTER)); // ���M������
      }
      return false;
      break;
    case MCR3:
      if (record->event.pressed) {
                SEND_STRING("hoge@hoge.co.jp"); // ���M������
      }
      return false;
      break;
  }
  return true;
}
