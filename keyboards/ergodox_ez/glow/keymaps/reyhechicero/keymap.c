#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define QWERTY 2 // media keys

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD,
  VIM_MACRO_0,
  VIM_MACRO_1
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(
//left hand
  KC_EQL,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_HOME,
  KC_DEL,          KC_F,        KC_L,          KC_H,    KC_V,    KC_Z,    KC_MEH,
  KC_LCTRL,        KC_S,        KC_R,          KC_N,    KC_T,    KC_K,
  KC_LSHIFT,       KC_X,		KC_J,          KC_B,    KC_M,    KC_Q,    KC_TAB,
  MO(1),		   KC_CAPSLOCK, KC_GRAVE,	   KC_LEFT, KC_RIGHT,
                                                           KC_LALT,		  KC_LGUI,
                                                                          KC_HYPR,
                                                         KC_SPC, KC_BSPC, KC_ESCAPE,
  // right hand
  KC_END,       KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_MINS,
  TG(1),		KC_QUOT, KC_W,    KC_U,    KC_O,              KC_Y,           KC_BSLASH,
  KC_C,         KC_D,    KC_E,    KC_A,    KC_I,			  KC_SCOLON,
  TG(2),		KC_P,    KC_G,    KC_COMM, KC_DOT,            KC_SLASH,		  KC_RSHIFT,
  KC_UP,        KC_DOWN, KC_LBRC, KC_RBRC, MO(1),
  KC_PGUP, KC_PGDOWN,
  VIM_MACRO_0,
  VIM_MACRO_1, KC_TAB, KC_ENTER
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 *
 */
[SYMB] = LAYOUT_ergodox(
  // left hand
  VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
  KC_TRNS, KC_LABK, KC_RABK, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
  KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
  KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
  EPRM,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_DEL,  KC_BSPC, KC_TRNS,
  // right hand
  KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  TG(1),   KC_EXLM, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12, KC_AT,   KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
  KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
  KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
  RGB_TOG, RGB_SLD,
  KC_TRNS,
  KC_TRNS, RGB_HUD, RGB_HUI
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[QWERTY] = LAYOUT_ergodox(
  // left hand
  KC_EQL,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_HOME,
  KC_DELT,         KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    TG(SYMB),
  KC_BSPC,         KC_A,        KC_S,          KC_D,    KC_F,    KC_G,
  KC_LSFT,         KC_Z,		KC_X,          KC_C,    KC_V,    KC_B,    KC_NO,
  KC_TRNS,		   KC_QUOT,     LALT(KC_LSFT), KC_LEFT, KC_RGHT,
																 KC_APP,  KC_LGUI,
                                                                          KC_HOME,
                                                         KC_SPC, KC_BSPC, KC_END,
  // right hand
  KC_RGHT,      KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_MINS,
  TG(SYMB),     KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,           KC_BSLS,
  KC_H,         KC_J,    KC_K,    KC_L,    KC_SCLN,			  KC_QUOT,
  KC_TRNS,		KC_N,    KC_M,    KC_COMM, KC_DOT,            KC_SLSH,		  KC_RSFT,
  KC_UP,        KC_DOWN, KC_LBRC, KC_RBRC, TT(SYMB),
  KC_LALT,		KC_ESC,
  KC_PGUP,
  KC_PGDN, KC_TAB, KC_ENT

),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206}, {0,251,206} },

    [1] = { {154,255,255}, {14,255,255}, {154,255,255}, {35,255,255}, {105,255,255}, {249,228,255}, {105,255,255}, {14,255,255}, {249,228,255}, {35,255,255}, {35,255,255}, {249,228,255}, {35,255,255}, {105,255,255}, {249,228,255}, {249,228,255}, {154,255,255}, {249,228,255}, {35,255,255}, {154,255,255}, {35,255,255}, {105,255,255}, {14,255,255}, {105,255,255}, {105,255,255}, {249,228,255}, {35,255,255}, {154,255,255}, {14,255,255}, {35,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {249,228,255}, {0,0,255}, {0,0,255}, {14,255,255}, {105,255,255}, {154,255,255}, {0,0,255}, {0,0,255}, {249,228,255}, {35,255,255}, {35,255,255}, {154,255,255}, {14,255,255}, {105,255,255} },

    [2] = { {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134}, {84,253,134} },

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VIM_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE)) SS_DELAY(100) SS_LSFT(SS_TAP(X_EQUAL)) SS_DELAY(100) SS_TAP(X_P));

    }
    break;
    case VIM_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE)) SS_DELAY(100) SS_LSFT(SS_TAP(X_EQUAL)) SS_DELAY(100) SS_TAP(X_Y));

    }
    break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
