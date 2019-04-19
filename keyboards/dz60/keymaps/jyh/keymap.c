#include QMK_KEYBOARD_H

/* [NAME] = LAYOUT_directional( */
/* //  `        1        2        3        4        5        6        7        8        9        0        -        =       Meh     Bksp */
/* _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
/* //   Tab         Q        W        E        R        T        Y        U        I        O        P        [        ]         | */
/*   _______  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______   , */
/* //    Caps         A        S        D        F        G        H        J        K        L        ;        '            Enter */
/*     _______   , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______     , */
/* //     Shift         Z        X        C        V        B       N         M        ,        .        /      Shift      Up      Fn1 */
/*       _______   , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
/* //  Ctrl        Gui          Alt            Bksp            Fn1             Space           Alt      Fn2      Left     Down    Right */
/*   _______  ,  _______   ,  _______   ,     _______     ,  _______  ,       _______      , _______, _______, _______, _______, _______), */


enum custom_layers {
	_QWERTY = 0,
	_FN1 = 1,
	_FN2 = 2,
	_FN3 = 3,
	_FN4 = 4,
};

#define _QW _QWERTY
#define FN1  MO(_FN1)
#define FN2  MO(_FN2)
#define FN3  MO(_FN3)
#define FN4  MO(_FN4)

enum custom_keycodes {
	QWERTY = SAFE_RANGE,
	MKITPNK
};


// Mod Tap Definitions
// -------------------
                                      //  Tap     Hold
                                      //  ------------------
#define GUI_GRV MT(MOD_LGUI, KC_GRV)  //  `       Meta
#define CTL_ESC MT(MOD_LCTL, KC_ESC)  //  Esc     Left Control
#define SFT_MIN MT(MOD_LSFT, KC_MINS) //  -       Left Shift
#define MEH_LBC MT(MOD_MEH,  KC_LBRC) //  [       Meh
#define CTL_BSP MT(MOD_LCTL, KC_BSPC)  // Bkspce  Left Control
#define HPR_RBC MT(MOD_HYPR, KC_RBRC) //  ]       Hyper
#define SFT_EQL MT(MOD_RSFT, KC_EQL)  //  =       Right Shift
#define CTL_BSL MT(MOD_RCTL, KC_BSLS) //  /       Right Control

#define FN3_N   LT(_FN3    , KC_N)    //  N       Function Layer 3
#define FN4_F   LT(_FN4    , KC_F)    //  F       Function Layer 4


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base Layer (Default Layer)
   *
   * ,----------------------------------------------------------------.
   * | ` | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = | Meh | Bksp |
   * |----------------------------------------------------------------|
   * |  Tab   | q | w | e | r | t | y | u | i | o | p | [ | ] |   /   |
   * |----------------------------------------------------------------|
   * |  Ctrl   | a | s | d | f | g | h | j | k | l | ; | ' |  enter   |
   * |----------------------------------------------------------------|
   * |    -     | z | x | c | v | b | n | m | , | . | / | RS | ^ |Fn1 |
   * |----------------------------------------------------------------|
   * | Ctl | Gui | Alt |  Back | Fn1 |  Space  | Alt |Fn2 | < | v | > |
   * `----------------------------------------------------------------'
   *
   * with Hold (Emacs-oriented)
   * ,----------------------------------------------------------------.
   * | Gui |   |   |   |   |   |   |   |   |   |   |   |   |    |     |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |   |   | Ctrl  |
   * |----------------------------------------------------------------|
   * |   Esc   |   |   |   |   |   |   |   |   |   |   |   |          |
   * |----------------------------------------------------------------|
   * |  Shift   |   |   |   |   |   |   |   |   |   |   |    |   |    |
   * |----------------------------------------------------------------|
   * |     |     |     |  Ctrl |     |         |     |    |   |   |   |
   * `----------------------------------------------------------------'
   */
	[_QW] = LAYOUT_directional(
	    GUI_GRV ,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,  KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  , KC_MINS, KC_EQL ,  KC_MEH , KC_BSPC,
	      KC_TAB   ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,  KC_Y  ,  KC_U  ,  KC_I   ,  KC_O  ,  KC_P  , KC_LBRC, KC_RBRC,   CTL_BSL    ,
		    CTL_ESC   ,  KC_A  ,  KC_S  ,  KC_D  , FN4_F  ,  KC_G  ,  KC_H  ,  KC_J  ,  KC_K  ,  KC_L  , KC_SCLN, KC_QUOT,       KC_ENT        ,
	          SFT_MIN,      KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  , FN3_N  ,  KC_M  , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,  KC_UP  , FN1    ,
	     KC_LCTL   ,   KC_LGUI   ,  KC_LALT   ,     CTL_BSP     ,     FN1    ,       KC_SPC       ,  KC_RALT,  FN2  , KC_LEFT, KC_DOWN, KC_RGHT),

  /* Primary Layer
   * ,----------------------------------------------------------------.
   * | Esc |F1|F2|F3|F4|F5|F6|F7|F8 | F9 | F10| F11| F12| Hyper | Del |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   | { | } |   | 7 | 8 | 9 | / | * |       |
   * |----------------------------------------------------------------|
   * |         | < | ^ | v | > | ( | ) |   | 4 | 5 | 6 | - |          |
   * |----------------------------------------------------------------|
   * |           |   |   |   |   | [ | ] | , | 1 | 2 | 3 | + |   |FN1 |
   * |----------------------------------------------------------------|
   * |     |     |     |     | FN1 |       |  0  |  . | Enter |   |   |
   * `----------------------------------------------------------------'
   */
	[_FN1] = LAYOUT_directional(
		KC_ESC,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12 , KC_HYPR , KC_DEL,
		 _______  , _______,  _______, _______, _______,  KC_LCBR , KC_RCBR, _______,  KC_7  ,  KC_8  ,  KC_9  , KC_SLSH, KC_ASTR,  _______  ,
     	    _______   , KC_LEFT,  KC_UP , KC_DOWN, KC_RGHT, KC_LPRN, KC_RPRN, _______,  KC_4  ,  KC_5  ,  KC_6  , KC_MINS,       _______     ,
    	         _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_COMM,  KC_1  ,  KC_2  ,  KC_3  , KC_PLUS, _______, _______,
    	  _______  ,  _______   ,  _______   ,     _______     ,  _______  ,       _______      ,  KC_0  , KC_DOT , KC_ENT , _______, _______),

  /* Secondary Layer
   * ,----------------------------------------------------------------.
   * |    |   |   |   |   |   |   |   |   |   |   |   |   |   |       |
   * |----------------------------------------------------------------|
   * |   | RGB | MOD | P | B | G | Pink |  |  | H- | H+ |  |  | Reset |
   * |----------------------------------------------------------------|
   * |      | < | ^ | v | > | |> | <M  | M> | S- | S+ |   |   |       |
   * |----------------------------------------------------------------|
   * |      |   |  |  |  | M | Vo- | Vo+ | V- | V+ |   |Ins |Home|PgUp|
   * |----------------------------------------------------------------|
   * |     |     |     |       |    |      |     | FN2 |Del |End |PgDn|
   * `----------------------------------------------------------------'
   */
	[_FN2] = LAYOUT_directional(
    	 KC_ESC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	      _______  , RGB_TOG, RGB_MOD, RGB_M_P, RGB_M_B, RGB_M_G, MKITPNK, _______, _______, RGB_HUD, RGB_HUI, _______, _______,    RESET    ,
     	    _______   , KC_LEFT,   KC_UP  , KC_DOWN , KC_RGHT, KC_MPLY, KC_MPRV, KC_MNXT, RGB_SAD, RGB_SAI, _______, _______,    _______     ,
	          _______   , _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, RGB_VAD, RGB_VAI, _______, KC_INS , KC_HOME, KC_PGUP,
	      _______  ,  _______   ,  _______   ,     _______     ,   KC_NO   ,       _______      , _______, _______, KC_DEL , KC_END , KC_PGDN),


	[_FN3] = LAYOUT_directional(
	//  `        1       2        3        4        5        6        7        8        9        0        -        =       Meh     Bksp
 	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	//  Tab         Q        W        E        R        T        Y        U        I        O        P        [        ]          |
      _______  ,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,  KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  , KC_MINS,  KC_EQL,   _______   ,
	//    Caps         A        S        D        F        G        H        J        K        L        ;        '            Enter
	    _______   , _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,  KC_UP , KC_RGHT, _______, _______,       _______     ,
	//      SHIFT       Z         X        C        V        B       N         M        ,        .        /      Shift      Up      Fn1
 	       _______  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	//  Ctrl        Gui          Alt            Bksp            Fn1             Space           Alt      Fn2      Left     Down    Right
 	  _______  ,  _______   ,  _______   ,     _______     ,  _______  ,       _______      , _______, _______, _______, _______, _______),


	[_FN4] = LAYOUT_directional(
	//  `        1       2        3        4        5        6        7        8        9        0        -        =       Meh     Bksp
 	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	//  Tab         Q        W        E        R        T        Y        U        I        O        P        [        ]          |
	  _______  , KC_EXLM,  KC_AT , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS,   KC_PIPE   ,
	//    Caps         A        S        D        F        G        H        J        K        L        ;        '            Enter
  	    _______   , _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN , KC_UP , KC_RGHT, _______, _______,       _______     ,
	//      SHIFT       Z         X        C        V        B       N         M        ,        .        /      Shift      Up      Fn1
 	       _______  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	//  Ctrl        Gui          Alt            Bksp            Fn1             Space           Alt      Fn2      Left     Down    Right
 	  _______  ,  _______   ,  _______   ,     _______     ,  _______  ,       _______      , _______, _______, _______, _______, _______),
};


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
	switch (keycode) {
    case MKITPNK:
	    if (record->event.pressed)
		    make_it_pink_blue();
	    return false;
	    break;
	}
	return true;
}
