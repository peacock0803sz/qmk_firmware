#include QMK_KEYBOARD_H
#include "keymap_jp.h"

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

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * +----------------------------------------------------------------------------------------------------------------------+
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   `  |                    |   `  |   6  |   7  |   8  |   9  |   0  |  BS  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   [  |                    |   ]  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |   -  |                    |   =  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Enter|                    | Enter|   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | EISU | EISU |  GUI |  Alt |||||||| Lower| Enter| Space||||||||Soace | Enter| Raise|||||||| Alt  |RCtrl | EISU | EISU |
   * +----------------------------------------------------------------------------------------------------------------------+
   */
  [_QWERTY] = LAYOUT( \
    KC_ESC,    KC_1,      KC_2,    KC_3,    KC_4, KC_5,  KC_MINS,                        KC_EQL,  KC_6,  KC_7, KC_8,    KC_9,    KC_0,      KC_BSPC,  \
    KC_TAB,    KC_Q,      KC_W,    KC_E,    KC_R, KC_T,  KC_LBRC,                        KC_RBRC, KC_Y,  KC_U, KC_I,    KC_O,    KC_P,      KC_BSLS,  \
    KC_LCTL,   KC_A,      KC_S,    KC_D,    KC_F, KC_G,  KC_GRV,                         KC_GRV,  KC_H,  KC_J, KC_K,    KC_L,    KC_SCLN,   KC_QUOT,  \
    KC_LSFT,   KC_Z,      KC_X,    KC_C,    KC_V, KC_B,  KC_SPC,                         KC_ENT,  KC_N,  KC_M, KC_COMM, KC_DOT,  KC_SLSH,   KC_RSFT,  \
    C(KC_SPC), C(KC_SPC), KC_LGUI, KC_LALT,       LOWER, KC_SPC,  KC_ENT,        KC_SPC, KC_ENT,  RAISE,       KC_RALT, KC_RCTL, C(KC_SPC), C(KC_SPC) \
  ),

  /* Lower
   * +----------------------------------------------------------------------------------------------------------------------+
   * |   ~  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |  Del |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  Tab |PGDown|  Up  | PGUp | Home | Stop |Mouse4|                    | Prev |Mouse1|Mouse3|Mouse2| PScr | VolUp| Alt+\|
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Caps | Left | Down | Right|  End | Play |Mouse5|                    | Next | MLeft|  MUp | MDown|MRight| Mute |  Mic |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift| Undo |  Cut | Copy | Paste| Redo | Enter|                    | Enter|  MWL |  MWU |  MWD |  MWR | VolDn| Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | C-SPC| C-SPC|  GUI |  Alt |||||||| Lower| Enter| Space||||||||Soace | Enter| Raise|||||||| Alt  |RCtrl |C-SPC |C-SPC |
   * +----------------------------------------------------------------------------------------------------------------------+
   */
  [_LOWER] = LAYOUT(
    KC_TILD,   KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                            KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,    KC_DEL,          \
    KC_TAB,    KC_PGUP,   KC_UP,   KC_PGDN, KC_HOME, KC_MSTP, KC_BTN4,                          KC_MPRV, KC_BTN1, KC_BTN3, KC_BTN2, KC_PSCR, KC_VOLU,   RALT(KC_BSLASH), \
    KC_CAPS,   KC_LEFT,   KC_DOWN, KC_RGHT, KC_END,  KC_MPLY, KC_BTN5,                          KC_MNXT, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, KC_MUTE,   KC_CALC,         \
    KC_LSFT,   KC_UNDO,   KC_CUT,  KC_COPY, KC_PSTE, KC_AGIN, KC_SPC,                           KC_ENT,  KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_VOLD,   KC_RSFT,         \
    C(KC_SPC), C(KC_SPC), KC_LGUI, KC_LALT,          LOWER,   KC_SPC,  KC_ENT,          KC_SPC, KC_ENT,  RAISE,            KC_RALT, KC_RCTL, C(KC_SPC), C(KC_SPC)        \
  ),

  /* Raise
   * +----------------------------------------------------------------------------------------------------------------------+
   * |   ~  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |  Del |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  Tab |PGDown|  Up  | PGUp | Home | Stop |Mouse4|                    | Prev |Mouse1|Mouse3|Mouse2| PScr | VolUp| Alt+\|
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Caps | Left | Down | Right|  End | Play |Mouse5|                    | Next | MLeft|  MUp | MDown|MRight| Mute |  Mic |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift| Undo |  Cut | Copy | Paste| Redo | Enter|                    | Enter|  MWL |  MWU |  MWD |  MWR | VolDn| Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | C-SPC| C-SPC|  GUI |  Alt |||||||| Lower| Enter| Space||||||||Soace | Enter| Raise|||||||| Alt  |RCtrl |C-SPC |C-SPC |
   * +----------------------------------------------------------------------------------------------------------------------+
   */
[_RAISE] = LAYOUT(
    KC_TILD,   KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                            KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,    KC_DEL,          \
    KC_TAB,    KC_PGUP,   KC_UP,   KC_PGDN, KC_HOME, KC_MSTP, KC_BTN4,                          KC_MPRV, KC_BTN1, KC_BTN3, KC_BTN2, KC_PSCR, KC_VOLU,   RALT(KC_BSLASH), \
    KC_CAPS,   KC_LEFT,   KC_DOWN, KC_RGHT, KC_END,  KC_MPLY, KC_BTN5,                          KC_MNXT, M(C(KC_LEFT)), M(C(KC_DOWN)), M(C(KC_UP)), M(C(KC_RIGHT)), KC_MUTE,   KC_CALC,         \
    KC_LSFT,   KC_UNDO,   KC_CUT,  KC_COPY, KC_PSTE, KC_AGIN, KC_SPC,                           KC_ENT,  KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_VOLD,   KC_RSFT,         \
    C(KC_SPC), C(KC_SPC), KC_LGUI, KC_LALT,          LOWER,   KC_SPC,  KC_ENT,          KC_SPC, KC_ENT,  RAISE,            KC_RALT, KC_RCTL, C(KC_SPC), C(KC_SPC)        \
  ),

  /* Adjust
   * +----------------------------------------------------------------------------------------------------------------------+
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * +----------------------------------------------------------------------------------------------------------------------+
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______, _______, _______,       _______, _______, _______,          _______, _______, _______, _______  \
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
