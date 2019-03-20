/* Copyright 2017 Kenny Hung
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
 *
 * This layout is upside down so that the cable works out better on top of a Mac.
 */
#include QMK_KEYBOARD_H
#include "keymap_uk.h"

// Layer shorthand
enum Layers {
  cm, // colemak
  dv, // dvorak
  qw, // qwerty
  nbl, // numbers left
  nbr, // numbers right
  syl, // symbols left
  syr, // symbols right
  nal, // navigation left
  nar // navigation right
};

// Layer buttons
#define _Z_SFT SFT_T(UK_Z)
#define _SCLSH SFT_T(UK_SCLN)
#define _SLSH SFT_T(UK_SLSH)

#define _X_NB LT(nbl, UK_X)
#define _Q_NB LT(nbl, UK_Q)
#define _DOT_NB LT(nbr, UK_DOT)
#define _V_NB LT(nbr, UK_V)
#define __NBL LT(nbl, _______)
#define __NBR LT(nbr, _______)

#define _C_SY LT(syl, UK_C)
#define _J_SY LT(syl, UK_J)
#define _W_SY LT(syr, UK_W)
#define _COM_SY LT(syr, UK_COMM)
#define __SYL LT(syl, _______)
#define __SYR LT(syr, _______)

#define _V_NAL LT(nal, UK_V)
#define _K_NAL LT(nal, UK_K)
#define _M_NAR LT(nar, UK_M)
#define __NAL LT(nal, _______)
#define __NAR LT(nar, _______)

// Custom hotkeys
#define _TERM LCTL(UK_QUOT) // Hotkey for terminal
#define _S_TAB S(UK_TAB)
#define _C_LEFT LCTL(UK_LEFT)
#define _C_RGHT LCTL(UK_RGHT)
#define _A_LEFT LALT(UK_LEFT)
#define _A_RGHT LALT(UK_RGHT)

// Custom hotkeys
#define _TERM LCTL(UK_QUOT) // Hotkey for terminal
#define _S_TAB S(UK_TAB)
#define _C_LEFT LCTL(UK_LEFT)
#define _C_RGHT LCTL(UK_RGHT)
#define _A_LEFT LALT(UK_LEFT)
#define _A_RGHT LALT(UK_RGHT)

enum custom_keycodes {
  IJ_OMN = SAFE_RANGE // IntelliJ Omnibox
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * .-----------------------------------------------------------------------------------------------------------.
 * | Q      | W      | F      | P      | G      |        |        | J      | L      | U      | Y      | ;      |
 * |-----------------------------------------------------------------------------------------------------------|
 * | A      | R      | S      | T      | D      |        |        | H      | N      | E      | I      | O      |
 * |-----------------------------------------------------------------------------------------------------------|
 * | Z      | X      | C      | V      | B      |        |        | K      | M      | ,      | .      | /      |
 * | SHIFT  | NUMBER | SYMBOL | NAV    |        |        |        |        | NAV    | SYMBOL | FUNC   | SHIFT  |
 * |-----------------------------------------------------------------------------------------------------------|
 * | LSHIFT | LCTRL  | LALT   | LGUI   | SPACE  | ENT    | DEL    | BKSPC  | RGUI   | RALT   | RCTRL  | RSHIFT |
 * .-----------------------------------------------------------------------------------------------------------.
 */
  [cm] = LAYOUT_ortho_4x12( \
    UK_RSFT, UK_RCTL, UK_RALT, UK_RGUI, UK_BSPC, UK_DEL,  UK_ENT,  UK_SPC,  UK_LGUI, UK_LALT, UK_LCTL, UK_LSFT, \
    _SLSH,   _DOT_NB, _COM_SY, _M_NAR,  UK_K,    _______, _______, UK_B,    _V_NAL,  _C_SY,   _X_NB,   _Z_SFT,  \
    UK_O,    UK_I,    UK_E,    UK_N,    UK_H,    _______, _______, UK_D,    UK_T,    UK_S,    UK_R,    UK_A,    \
    UK_SCLN, UK_Y,    UK_U,    UK_L,    UK_J,    _______, _______, UK_G,    UK_P,    UK_F,    UK_W,    UK_Q     \
  ),

/* Dvorak
 * .-----------------------------------------------------------------------------------------------------------.
 * | '      | ,      | .      | P      | Y      |        |        | F      | G      | C      | R      | L      |
 * |-----------------------------------------------------------------------------------------------------------|
 * | A      | O      | E      | U      | I      |        |        | D      | H      | T      | N      | S      |
 * |-----------------------------------------------------------------------------------------------------------|
 * | ;      | Q      | J      | K      | X      |        |        | B      | M      | W      | V      | Z      |
 * | SHIFT  | NUMBER | SYMBOL | NAV    |        |        |        |        | NAV    | SYMBOL | FUNC   | SHIFT  |
 * |-----------------------------------------------------------------------------------------------------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * |-----------------------------------------------------------------------------------------------------------|
 */
  [dv] = LAYOUT_ortho_4x12( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _Z_SFT,  _V_NB,   _W_SY,   _M_NAR,  UK_B,    _______, _______, UK_X,    _K_NAL,  _J_SY,   _Q_NB,   _SCLSH,  \
    UK_S,    UK_N,    UK_T,    UK_H,    UK_D,    _______, _______, UK_I,    UK_U,    UK_E,    UK_O,    UK_A,    \
    UK_L,    UK_R,    UK_C,    UK_G,    UK_F,    _______, _______, UK_Y,    UK_P,    UK_DOT,  UK_COMM, UK_QUOT  \
  ),

/* QWERTY
 * .-----------------------------------------------------------------------------------------------------------.
 * | Q      | W      | E      | R      | T      |        |        | Y      | U      | I      | O      | P      |
 * |-----------------------------------------------------------------------------------------------------------|
 * | A      | S      | D      | F      | G      |        |        | H      | J      | K      | L      | ;      |
 * |-----------------------------------------------------------------------------------------------------------|
 * | Z      | X      | C      | V      | B      |        |        | N      | M      | ,      | .      | /      |
 * | SHIFT  | NUMBER | SYMBOL | NAV    |        |        |        |        | NAV    | SYMBOL | FUNC   | SHIFT  |
 * |-----------------------------------------------------------------------------------------------------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * .-----------------------------------------------------------------------------------------------------------.
 */
  [qw] = LAYOUT_ortho_4x12( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _SLSH,   _DOT_NB, _COM_SY, _M_NAR,  UK_N,    _______, _______, UK_B,    _V_NAL,  _C_SY,   _X_NB,   _Z_SFT,  \
    UK_SCLN, UK_L,    UK_K,    UK_J,    UK_H,    _______, _______, UK_G,    UK_F,    UK_D,    UK_S,    UK_A,    \
    UK_P,    UK_O,    UK_I,    UK_U,    UK_Y,    _______, _______, UK_T,    UK_R,    UK_E,    UK_W,    UK_Q     \
  ),

/* Numbers _NB
 * .-----------------------------------------------------------------------------------------------------------.
 * |        | F7     | F8     | F9     | F10    |        |        |        | 7      | 8      | 9      |        |
 * |-----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | F4     | F5     | F6     | F11    |        |        |        | 4      | 5      | 6      |        |
 * |-----------------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        | F1     | F2     | F3     | F12    |        |        | 0      | 1      | 2      | 3      | .      |
 * |-----------------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------'
 */
  [nbl] = LAYOUT_ortho_4x12( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    UK_DOT,  UK_3,    UK_2,    UK_1,    UK_0,    _______, _______, UK_F12,  UK_F3,   UK_F2,   __NBL,   _______, \
    _______, UK_6,    UK_5,    UK_4,    _______, _______, _______, UK_F11,  UK_F6,   UK_F5,   UK_F4,   _______, \
    _______, UK_9,    UK_8,    UK_7,    _______, _______, _______, UK_F10,  UK_F9,   UK_F8,   UK_F7,   _______  \
  ),
  [nbr] = LAYOUT_ortho_4x12( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    UK_DOT,  __NBR,   UK_2,    UK_1,    UK_0,    _______, _______, UK_F12,  UK_F3,   UK_F2,   UK_F1,   _______, \
    _______, UK_6,    UK_5,    UK_4,    _______, _______, _______, UK_F11,  UK_F6,   UK_F5,   UK_F4,   _______, \
    _______, UK_9,    UK_8,    UK_7,    _______, _______, _______, UK_F10,  UK_F9,   UK_F8,   UK_F7,   _______  \
  ),

/* Symbols _SY
 * .-----------------------------------------------------------------------------------------------------------.
 * | !      | £      | _      | -      | ~      |        |        | \      | {      | }      | /      | #      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | $      | %      | +      | =      |        |        |        | "      | (      | )      | '      | @      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | ^      | &      | *      | |      |        |        |        | <      | [      | ]      | >      | `      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------'
 */
  [syl] = LAYOUT_ortho_4x12( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    UK_GRV,  UK_RABK, UK_RBRC, UK_LBRC, UK_LABK, _______, _______, _______, UK_PIPE, __SYL,   UK_AMPR, UK_CIRC, \
    UK_AT,   UK_QUOT, UK_RPRN, UK_LPRN, UK_DQUO, _______, _______, _______, UK_EQL,  UK_PLUS, UK_PERC, UK_DLR,  \
    UK_HASH, UK_SLSH, UK_RCBR, UK_LCBR, UK_BSLS, _______, _______, UK_TILD, UK_MINS, UK_UNDS, UK_PND,  UK_EXLM  \
  ),
  [syr] = LAYOUT_ortho_4x12( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    UK_GRV,  UK_RABK, __SYR,   UK_LBRC, UK_LABK, _______, _______, _______, UK_PIPE, UK_ASTR, UK_AMPR, UK_CIRC, \
    UK_AT,   UK_QUOT, UK_RPRN, UK_LPRN, UK_DQUO, _______, _______, _______, UK_EQL,  UK_PLUS, UK_PERC, UK_DLR,  \
    UK_HASH, UK_SLSH, UK_RCBR, UK_LCBR, UK_BSLS, _______, _______, UK_TILD, UK_MINS, UK_UNDS, UK_PND,  UK_EXLM  \
 ),

/*
 * Navigation
 * .-----------------------------------------------------------------------------------------------------------.
 * | Esc    | Ctrl L | Up     | Ctrl R | RGB RMD| RGB HD | RGB HI | RGB_TG | PtSn   | ScLk   | Pause  | DVORAK |
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | Tab    | Left   | Down   | Right  | RGB MD | RGB SD | RGB SI | COLEMAK| Insert | Home   | PgUp   | Term   |
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | ShTab  | Alt L  | IJ Omni| Alt R  |        | RGB VD | RGB VI |        | ScLk   | End    | PgDn   | QWERTY |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------'
 */
  [nal] = LAYOUT_ortho_4x12( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    DF(qw),  UK_PGDN, UK_END,  UK_SLCK, _______, RGB_VAI, RGB_VAD, _______, __NAL,   IJ_OMN,  _A_LEFT, _S_TAB,  \
    _TERM,   UK_PGUP, UK_HOME, UK_INS,  DF(cm),  RGB_SAI, RGB_SAD, RGB_MOD, UK_RGHT, UK_DOWN, UK_LEFT, UK_TAB,  \
    DF(dv),  UK_PAUS, UK_SLCK, UK_PSCR, RGB_TOG, RGB_HUI, RGB_RMOD,RGB_HUD, _C_RGHT, UK_UP,   _C_LEFT, UK_ESC   \
  ),
  [nar] = LAYOUT_ortho_4x12( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    DF(qw),  UK_PGDN, UK_END,  __NAR,   _______, RGB_VAI, RGB_VAD, _______, _A_RGHT, IJ_OMN,  _A_LEFT, _S_TAB,  \
    _TERM,   UK_PGUP, UK_HOME, UK_INS,  DF(cm),  RGB_SAI, RGB_SAD, RGB_MOD, UK_RGHT, UK_DOWN, UK_LEFT, UK_TAB,  \
    DF(dv),  UK_PAUS, UK_SLCK, UK_PSCR, RGB_TOG, RGB_HUI, RGB_RMOD,RGB_HUD, _C_RGHT, UK_UP,   _C_LEFT, UK_ESC   \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case IJ_OMN:
        SEND_STRING(SS_TAP(X_LSHIFT)SS_TAP(X_LSHIFT));
        return false;
    }
  }
  return true;
}
