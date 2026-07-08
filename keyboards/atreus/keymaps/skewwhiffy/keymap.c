// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "keymap_uk.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum Layers {
  cm, // colemak
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
#define _S_TAB S(KC_TAB)
#define _C_LEFT LCTL(KC_LEFT)
#define _C_RGHT LCTL(KC_RGHT)
#define _A_LEFT LALT(KC_LEFT)
#define _A_RGHT LALT(KC_RGHT)

// Custom hotkeys
#define _TERM LCTL(UK_QUOT) // Hotkey for terminal
#define _S_TAB S(KC_TAB)
#define _C_LEFT LCTL(KC_LEFT)
#define _C_RGHT LCTL(KC_RGHT)
#define _A_LEFT LALT(KC_LEFT)
#define _A_RGHT LALT(KC_RGHT)

enum custom_keycodes {
  IJ_OMN = SAFE_RANGE // IntelliJ Omnibox
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * .---------------------------------------------                 ---------------------------------------------.
 * | Q      | W      | F      | P      | G      |                 | J      | L      | U      | Y      | ;      |
 * |---------------------------------------------                 ---------------------------------------------|
 * | A      | R      | S      | T      | D      |                 | H      | N      | E      | I      | O      |
 * |---------------------------------------------                 ---------------------------------------------|
 * | Z      | X      | C      | V      | B      |                 | K      | M      | ,      | .      | /      |
 * | SHIFT  | NUMBER | SYMBOL | NAV    |        |                 |        | NAV    | SYMBOL | FUNC   | SHIFT  |
 * |-----------------------------------------------------------------------------------------------------------|
 * | LSHIFT | LCTRL  | LALT   | LGUI   | SPACE  | ENT    | DEL    | BKSPC  | RGUI   | RALT   | RCTRL  | RSHIFT |
 * .-----------------------------------------------------------------------------------------------------------.
 */
 [cm] = LAYOUT( \
   UK_Q,    UK_W,    UK_F,    UK_P,    UK_G,                      UK_J,    UK_L,    UK_U,    UK_Y,    UK_SCLN, \
   UK_A,    UK_R,    UK_S,    UK_T,    UK_D,                      UK_H,    UK_N,    UK_E,    UK_I,    UK_O, \
   _Z_SFT,  _X_NB,   _C_SY,   _V_NAL,  UK_B,                      UK_K,    _M_NAR,  _COM_SY, _DOT_NB, _SLSH, \
   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  KC_ENT,  KC_DEL,  KC_BSPC, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT \
 ),

/* Numbers _NB
 * .---------------------------------------------                 ---------------------------------------------.
 * |        | F7     | F8     | F9     | F10    |                 |        | 7      | 8      | 9      |        |
 * |-----------------+--------+--------+--------+                 +--------+--------+--------+--------+--------|
 * |        | F4     | F5     | F6     | F11    |                 |        | 4      | 5      | 6      |        |
 * |-----------------+--------+--------+--------+                 +--------+--------------------------+--------|
 * |        | F1     | F2     | F3     | F12    |                 | 0      | 1      | 2      | 3      | .      |
 * |-----------------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------'
 */
 [nbl] = LAYOUT( \
   _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,                    _______, UK_7,    UK_8,    UK_9,    _______, \
   _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,                    _______, UK_4,    UK_5,    UK_6,    _______, \
   _______, __NBL,   KC_F2,   KC_F3,   KC_F12,                    UK_0,    UK_1,    UK_2,    UK_3,    UK_DOT, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
 ),
 [nbr] = LAYOUT( \
   _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,                    _______, UK_7,    UK_8,    UK_9,    _______, \
   _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,                    _______, UK_4,    UK_5,    UK_6,    _______, \
   _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,                    UK_0,    UK_1,    UK_2,    __NBR,   UK_DOT, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
 ),

/* Symbols _SY
 * .---------------------------------------------                 ---------------------------------------------.
 * | !      | £      | _      | -      | ~      |                 | \      | {      | }      | /      | #      |
 * |--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------|
 * | $      | %      | +      | =      |        |                 | "      | (      | )      | '      | @      |
 * |--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------|
 * | ^      | &      | *      | |      |        |                 | <      | [      | ]      | >      | `      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------'
 */
 [syl] = LAYOUT( \
   UK_EXLM, UK_PND,  UK_UNDS, UK_MINS, UK_TILD,                   UK_BSLS, UK_LCBR, UK_RCBR, UK_SLSH, UK_HASH, \
   UK_DLR,  UK_PERC, UK_PLUS, UK_EQL,  _______,                   UK_DQUO, UK_LPRN, UK_RPRN, UK_QUOT, UK_AT, \
   UK_CIRC, UK_AMPR, __SYL,   UK_PIPE, _______,                   UK_LABK, UK_LBRC, UK_RBRC, UK_RABK, UK_GRV, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
 ),
 [syr] = LAYOUT( \
   UK_EXLM, UK_PND,  UK_UNDS, UK_MINS, UK_TILD,                   UK_BSLS, UK_LCBR, UK_RCBR, UK_SLSH, UK_HASH, \
   UK_DLR,  UK_PERC, UK_PLUS, UK_EQL,  _______,                   UK_DQUO, UK_LPRN, UK_RPRN, UK_QUOT, UK_AT, \
   UK_CIRC, UK_AMPR, UK_ASTR, UK_PIPE, _______,                   UK_LABK, UK_LBRC, __SYR,   UK_RABK, UK_GRV, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
 ),

/*
 * Navigation
 * .---------------------------------------------                 ---------------------------------------------.
 * | Esc    | Ctrl L | Up     | Ctrl R |        |                 |        | PtSn   | ScLk   | Pause  | DVORAK |
 * +--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------|
 * | Tab    | Left   | Down   | Right  |        |                 | COLEMAK| Insert | Home   | PgUp   | Term   |
 * +--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------|
 * | ShTab  | Alt L  | IJ Omni| Alt R  |        |                 |        | ScLk   | End    | PgDn   | QWERTY |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------'
 */
 [nal] = LAYOUT( \
   KC_ESC,  _C_LEFT, KC_UP,   _C_RGHT, _______,                   _______, KC_PSCR, KC_SCRL, KC_PAUS, _______, \
   KC_TAB,  KC_LEFT, KC_DOWN, KC_RGHT, _______,                   DF(cm),  KC_INS,  KC_HOME, KC_PGUP, _TERM, \
   _S_TAB,  _A_LEFT, IJ_OMN,  __NAL,   _______,                   _______, KC_SCRL, KC_END,  KC_PGDN, _______, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
 ),
 [nar] = LAYOUT( \
   KC_ESC,  _C_LEFT, KC_UP,   _C_RGHT, _______,                   _______, KC_PSCR, KC_SCRL, KC_PAUS, _______, \
   KC_TAB,  KC_LEFT, KC_DOWN, KC_RGHT, _______,                   DF(cm),  KC_INS,  KC_HOME, KC_PGUP, _TERM, \
   _S_TAB,  _A_LEFT, IJ_OMN,  _A_RGHT, _______,                   _______, __NAR,   KC_END,  KC_PGDN, _______, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
 ),
};
