#ifndef LEVINSON24_H
#define LEVINSON24_H

#include "quantum.h"

#ifdef KEYBOARD_levinson_rev1
    #include "rev1.h"
#else
    #include "rev2.h"
#endif

// Used to create a keymap using only KC_ prefixed keys
#define KC_KEYMAP( \
    K00, K01, K02, K03, K04, K05, \
    K10, K11, K12, K13, K14, K15, \
    K20, K21, K22, K23, K24, K25, \
    K30, K31, K32, K33, K34, K35  \
    ) \
    KEYMAP( \
        KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, \
        KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, \
        KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, \
        KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35  \
    )

#define KC_LAYOUT_ortho_4x6 KC_KEYMAP

#endif
