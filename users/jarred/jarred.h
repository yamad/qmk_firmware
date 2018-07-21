/* Copyright 2018 Jarred Steenvoorden
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

// Use 7 wide characters for keymaps
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Layers
#define _QW 0
#define _LW 1
#define _NV 2
#define _NP 3
#define _MS 4 // Mouse

#define MS_A LT(_MS,KC_A)

// Wrappers
#define LAYOUT_planck_grid_wrapper(...)      LAYOUT_planck_grid(__VA_ARGS__)

/* Qwerty Layer */
#define QWERTY_L1   KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define QWERTY_L2   MO(_NV),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define QWERTY_L3   KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B
#define QWERTY_L4   KC_LCTL, KC_LGUI, MO(_NP), KC_LALT, MO(_LW),  KC_SPC

#define QWERTY_R1                                                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC
#define QWERTY_R2                                                           KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT
#define QWERTY_R3                                                           KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT
#define QWERTY_R4                                                         KC_ENT, MO(_LW), KC_RALT, MO(_MS),  KC_APP, KC_RCTL

/* Lower / Upper Layer */
#define LOWER_L1   KC_ESC ,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define LOWER_L2   _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define LOWER_L3   _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10
#define LOWER_L4   _______, _______, _______, _______, _______, _______

#define LOWER_R1                                                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______
#define LOWER_R2                                                          KC_F11,  KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS
#define LOWER_R3                                                          KC_F12,  KC_GRV, _______, _______, _______, _______
#define LOWER_R4                                                         _______, _______, _______, _______, _______, _______

/* Navigation Layer */
#define NAV_L1     _______, _______, _______, KC_LGUI,  KC_DEL, KC_BSPC
#define NAV_L2     _______, _______, _______, KC_LSFT, KC_LCTL,  KC_ENT
#define NAV_L3     _______, _______, _______, _______, _______, _______
#define NAV_L4     _______, _______, _______, _______, _______, _______

#define NAV_R1                                                           _______, KC_HOME, KC_UP  , KC_END ,  KC_INS, _______
#define NAV_R2                                                           _______, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, _______
#define NAV_R3                                                           _______, KC_PGUP, KC_PGDN, _______, _______, _______
#define NAV_R4                                                           _______, _______, _______, _______, _______, _______

/* Numpad Layer */
#define NUMPAD_L1  RGB_TOG, RGB_MOD, _______, _______, RGB_HUD, RGB_HUI
#define NUMPAD_L2  BL_TOGG, BL_STEP, BL_BRTG, _______, RGB_SAD, RGB_SAI
#define NUMPAD_L3  _______, _______, _______, _______, RGB_VAD, RGB_VAI
#define NUMPAD_L4    RESET, _______, _______, _______, RGB_SPD, RGB_SPI

#define NUMPAD_R1                                                        _______, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______
#define NUMPAD_R2                                                        _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______
#define NUMPAD_R3                                                        _______, KC_P1,   KC_P2,   KC_P3,   KC_PAST, KC_ENT
#define NUMPAD_R4                                                        _______, KC_P0,   XXXXXXX, KC_PDOT, KC_PSLS, KC_ENT

/* Mouse Layer */
#define MOUSE_L1   _______, _______, _______, _______, _______, _______
#define MOUSE_L2   _______, _______, KC_ACL1, KC_ACL0, KC_BTN1, KC_BTN2
#define MOUSE_L3   _______, _______, _______, _______, _______, _______
#define MOUSE_L4   _______, _______, _______, _______, _______, KC_BTN1

#define MOUSE_R1                                                         _______, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______
#define MOUSE_R2                                                         _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______
#define MOUSE_R3                                                         _______, _______, _______, _______, _______, _______
#define MOUSE_R4                                                         KC_BTN2, _______, _______, _______, _______, _______

#define QWERTY_1_12 QWERTY_L1, QWERTY_R1
#define QWERTY_2_12 QWERTY_L2, QWERTY_R2
#define QWERTY_3_12 QWERTY_L3, QWERTY_R3
#define QWERTY_4_12 QWERTY_L4, QWERTY_R4

#define LOWER_1_12 LOWER_L1, LOWER_R1
#define LOWER_2_12 LOWER_L2, LOWER_R2
#define LOWER_3_12 LOWER_L3, LOWER_R3
#define LOWER_4_12 LOWER_L4, LOWER_R4

#define NAV_1_12 NAV_L1, NAV_R1
#define NAV_2_12 NAV_L2, NAV_R2
#define NAV_3_12 NAV_L3, NAV_R3
#define NAV_4_12 NAV_L4, NAV_R4

#define NUMPAD_1_12 NUMPAD_L1, NUMPAD_R1
#define NUMPAD_2_12 NUMPAD_L2, NUMPAD_R2
#define NUMPAD_3_12 NUMPAD_L3, NUMPAD_R3
#define NUMPAD_4_12 NUMPAD_L4, NUMPAD_R4

#define MOUSE_1_12 MOUSE_L1, MOUSE_R1
#define MOUSE_2_12 MOUSE_L2, MOUSE_R2
#define MOUSE_3_12 MOUSE_L3, MOUSE_R3
#define MOUSE_4_12 MOUSE_L4, MOUSE_R4

#define QWERTY_4x12 QWERTY_1_12, QWERTY_2_12, QWERTY_3_12, QWERTY_4_12
#define LOWER_4x12 LOWER_1_12, LOWER_2_12, LOWER_3_12, LOWER_4_12
#define NAV_4x12 NAV_1_12, NAV_2_12, NAV_3_12, NAV_4_12
#define NUMPAD_4x12 NUMPAD_1_12, NUMPAD_2_12, NUMPAD_3_12, NUMPAD_4_12
#define MOUSE_4x12 MOUSE_1_12, MOUSE_2_12, MOUSE_3_12, MOUSE_4_12

#endif
