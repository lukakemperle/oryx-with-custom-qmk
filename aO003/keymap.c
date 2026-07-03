#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
};



enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
};

#define DUAL_FUNC_0 LT(14, KC_X)
#define DUAL_FUNC_1 LT(9, KC_Z)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_TAB,         KC_Q,           KC_W,           LT(8, KC_E),    LT(7, KC_R),    KC_T,                                           KC_Y,           TD(DANCE_1),    KC_I,           KC_O,           KC_P,           KC_BSLS,        
    TD(DANCE_0),    MT(MOD_LGUI, KC_A),MT(MOD_LALT, KC_S),MT(MOD_LSFT, KC_D),MT(MOD_LCTL, KC_F),KC_G,                                           KC_H,           MT(MOD_RCTL, KC_J),MT(MOD_RSFT, KC_K),MT(MOD_RALT, KC_L),MT(MOD_RGUI, KC_SCLN),MT(MOD_RCTL | MOD_RSFT | MOD_LALT, KC_QUOTE),
    LCTL(LSFT(KC_F13)),LT(6, KC_Z),    KC_X,           KC_C,           LT(4, KC_V),    KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         LT(6, KC_SLASH),KC_EQUAL,       
                                                    LT(1, KC_SPACE),LT(12, KC_BSPC),                                LT(2, KC_ENTER),KC_SPACE
  ),
  [1] = LAYOUT_voyager(
    RGB_TOG,        TOGGLE_LAYER_COLOR,RGB_MODE_FORWARD,RGB_SLD,        RGB_VAD,        RGB_VAI,                                        KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_0,     ST_MACRO_1,     LALT(LCTL(LSFT(KC_W))),QK_BOOT,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,KC_TRANSPARENT,                                 KC_TRANSPARENT, LALT(KC_LEFT),  KC_DELETE,      LALT(KC_RIGHT), KC_BSPC,        LALT(LCTL(LSFT(KC_S))),
    KC_ENTER,       KC_LEFT_GUI,    KC_LEFT_ALT,    KC_LEFT_SHIFT,  KC_LEFT_CTRL,   LGUI(LCTL(KC_LBRC)),                                KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_ENTER,       ST_MACRO_2,     
    KC_TRANSPARENT, KC_TRANSPARENT, MT(MOD_LCTL, KC_F13),LSFT(KC_F13),   KC_F13,         LGUI(LCTL(KC_SPACE)),                                RGUI(KC_BSPC),  LALT(KC_BSPC),  LALT(KC_DELETE),ST_MACRO_3,     ST_MACRO_4,     KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_F20,         KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_7,           KC_8,           KC_9,           KC_MINUS,       KC_SLASH,       KC_F12,         
    KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,                                        KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_ASTR,        KC_BSPC,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_LBRC,        KC_RBRC,        KC_LCBR,        KC_RCBR,                                        KC_1,           KC_2,           KC_3,           KC_DOT,         KC_EQUAL,       KC_ENTER,       
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_0
  ),
  [3] = LAYOUT_voyager(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    KC_ESCAPE,      MT(MOD_LGUI, KC_A),MT(MOD_LALT, KC_S),MT(MOD_LSFT, KC_D),MT(MOD_LCTL, KC_F),KC_G,                                           KC_H,           MT(MOD_RCTL, KC_J),MT(MOD_RSFT, KC_K),MT(MOD_RALT, KC_L),MT(MOD_RGUI, KC_SCLN),KC_QUOTE,       
    TO(0),          KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
                                                    KC_SPACE,       KC_BSPC,                                        KC_ENTER,       KC_SPACE
  ),
  [4] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, LGUI(KC_F20),   LGUI(LSFT(KC_GRAVE)),LGUI(KC_GRAVE), KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, LGUI(KC_Q),     KC_TRANSPARENT, LGUI(KC_W),     LGUI(KC_S),     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, RALT(KC_F20),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, RCTL(KC_F20),   RGUI(RCTL(RSFT(KC_F19))),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, RSFT(KC_F20),   RGUI(RSFT(KC_F20)),KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, RALT(RGUI(KC_F20)),RGUI(RCTL(KC_F20)),RALT(RGUI(RCTL(KC_F20))),RALT(RCTL(KC_F20)),                                KC_TRANSPARENT, RGUI(KC_F19),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    RALT(KC_F19),   KC_TRANSPARENT,                                 KC_TRANSPARENT, RALT(KC_F19)
  ),
  [7] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, RSFT(KC_F19),   RCTL(KC_F19),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_F19,         LALT(LCTL(KC_F19)),LALT(LGUI(LCTL(KC_F19))),LCTL(LSFT(KC_F19)),LALT(LSFT(KC_F19)),KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 RALT(RGUI(KC_F19)),LALT(LGUI(LCTL(KC_F19))),LALT(LGUI(LSFT(KC_F19))),RGUI(RSFT(KC_F19)),KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [8] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    RALT(RCTL(RSFT(KC_F19))),KC_Q,           KC_TRANSPARENT, KC_TRANSPARENT, KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    TO(0),          KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,       
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
                                                    KC_SPACE,       RALT(RCTL(RSFT(KC_F19))),                                KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [9] = LAYOUT_voyager(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT, 
    TO(0),          KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
                                                    KC_SPACE,       KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_SPACE
  ),
  [10] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, RSFT(KC_Q),     RSFT(KC_W),     RSFT(KC_E),     RSFT(KC_R),     RSFT(KC_T),                                     LSFT(KC_Y),     LSFT(KC_U),     RSFT(KC_I),     LSFT(KC_O),     LSFT(KC_P),     KC_TRANSPARENT, 
    TO(0),          RSFT(KC_A),     RSFT(KC_S),     DUAL_FUNC_0,    RSFT(KC_F),     RSFT(KC_G),                                     LSFT(KC_H),     LSFT(KC_J),     DUAL_FUNC_1,    LSFT(KC_L),     KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, RSFT(KC_Z),     RSFT(KC_X),     RSFT(KC_C),     RSFT(KC_V),     RSFT(KC_B),                                     LSFT(KC_N),     LSFT(KC_M),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [11] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MS_ACCEL1,   KC_MS_ACCEL0,   KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_MS_ACCEL2,   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [12] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F13,         KC_F14,         KC_ENTER,       KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_F13),   LCTL(KC_F13),   LSFT(KC_F13),   KC_F13,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


const uint16_t PROGMEM combo0[] = { LT(6, KC_Z), KC_X, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_C, LT(4, KC_V), COMBO_END};
const uint16_t PROGMEM combo3[] = { LT(4, KC_V), KC_B, COMBO_END};
const uint16_t PROGMEM combo4[] = { MT(MOD_LCTL, KC_F), MT(MOD_RCTL, KC_J), COMBO_END};
const uint16_t PROGMEM combo5[] = { MT(MOD_LSFT, KC_D), MT(MOD_RSFT, KC_K), COMBO_END};
const uint16_t PROGMEM combo6[] = { MT(MOD_LALT, KC_S), MT(MOD_LSFT, KC_D), COMBO_END};
const uint16_t PROGMEM combo7[] = { MT(MOD_RSFT, KC_K), MT(MOD_RALT, KC_L), COMBO_END};
const uint16_t PROGMEM combo8[] = { LT(7, KC_R), LT(8, KC_E), COMBO_END};
const uint16_t PROGMEM combo9[] = { KC_W, LT(8, KC_E), COMBO_END};
const uint16_t PROGMEM combo10[] = { KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo11[] = { KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo12[] = { MT(MOD_LCTL, KC_F), MT(MOD_LSFT, KC_D), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, LGUI(KC_Z)),
    COMBO(combo1, RGUI(KC_X)),
    COMBO(combo2, RGUI(KC_C)),
    COMBO(combo3, RGUI(KC_V)),
    COMBO(combo4, KC_ENTER),
    COMBO(combo5, LALT(LGUI(LCTL(KC_G)))),
    COMBO(combo6, KC_ESCAPE),
    COMBO(combo7, TG(9)),
    COMBO(combo8, LGUI(LCTL(KC_F19))),
    COMBO(combo9, KC_BSPC),
    COMBO(combo10, KC_ENTER),
    COMBO(combo11, KC_SPACE),
    COMBO(combo12, KC_SPACE),
};



extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178}, {149,213,178} },

    [1] = { {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {0,0,0}, {0,0,0}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190}, {20,225,190} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170}, {36,216,170} },

    [8] = { {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238}, {37,235,238} },

    [9] = { {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137}, {192,214,137} },

    [11] = { {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204}, {236,218,204} },

    [12] = { {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204}, {100,218,204} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
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
      case 3:
        set_layer_color(3);
        break;
      case 8:
        set_layer_color(8);
        break;
      case 9:
        set_layer_color(9);
        break;
      case 11:
        set_layer_color(11);
        break;
      case 12:
        set_layer_color(12);
        break;
     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,      
    SINGLE_HOLD,         
    DOUBLE_TAP,          
    DOUBLE_HOLD,         
    DOUBLE_SINGLE_TAP,   
    MORE_TAPS            
};

static tap dance_state[2];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(KC_F17); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(KC_F17); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_U);
        tap_code16(KC_U);
        tap_code16(KC_U);
    }
    if(state->count > 3) {
        tap_code16(KC_U);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_U); break;
        case DOUBLE_TAP: layer_move(10); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_U); register_code16(KC_U);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_U); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_U); break;
    }
    dance_state[1].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX:
    // Mouse and consumer keys (volume, media) with modifiers work inconsistently across operating systems,
    // this makes sure that modifiers are always applied to the key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode)) || IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
      if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_LEFT))SS_DELAY(100)  SS_LALT(SS_LSFT(SS_TAP(X_RIGHT))));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_LEFT))SS_DELAY(100)  SS_LGUI(SS_LSFT(SS_TAP(X_LEFT)))SS_DELAY(100)  SS_LGUI(SS_LSFT(SS_TAP(X_RIGHT))));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ENTER)SS_DELAY(100)  SS_TAP(X_UP)SS_DELAY(100)  SS_LGUI(SS_TAP(X_RIGHT)));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_RIGHT)))SS_DELAY(100)  SS_TAP(X_DELETE));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_LEFT))SS_DELAY(100)  SS_LGUI(SS_LSFT(SS_TAP(X_RIGHT)))SS_DELAY(100)  SS_TAP(X_DELETE));
    }
    break;

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(RSFT(KC_D));
        } else {
          unregister_code16(RSFT(KC_D));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_SHIFT);
        } else {
          unregister_code16(KC_LEFT_SHIFT);
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_K));
        } else {
          unregister_code16(LSFT(KC_K));
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_SHIFT);
        } else {
          unregister_code16(KC_RIGHT_SHIFT);
        }  
      }  
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
// ============================================================
// CUSTOM QMK — do not edit above this line with Oryx changes
// ============================================================

// Layer 9 (gaming, combo k+l): tap Opt+F16 on enter, Opt+Shift+F16 on exit
// to show/hide the Mouseless overlay.
// Layer 11 (mouse, hold E): hold F15 while active so Mouseless stays in free
// mode; release F15 on layer exit.
// Taps are deferred to matrix_scan_user so layer_state_set_user stays side-effect free.

static bool kl_l9_active     = false;
static bool kl_l9_send_show  = false;
static bool kl_l9_send_hide  = false;
static bool msls_free_active = false;

layer_state_t layer_state_set_user(layer_state_t state) {
    bool l9_now  = (state >> 9)  & 1;
    bool l8_now  = (state >> 8)  & 1;

    if (l9_now && !kl_l9_active) {
        kl_l9_send_show = true;
        kl_l9_active    = true;
    } else if (!l9_now && kl_l9_active) {
        kl_l9_send_hide = true;
        kl_l9_active    = false;
    }

    if (l8_now && !msls_free_active) {
        msls_free_active = true;
        register_code(KC_F15);
    } else if (!l8_now && msls_free_active) {
        msls_free_active = false;
        unregister_code(KC_F15);
    }

    return state;
}

void matrix_scan_user(void) {
    if (kl_l9_send_show) {
        kl_l9_send_show = false;
        tap_code16(LALT(KC_F16));
    }
    if (kl_l9_send_hide) {
        kl_l9_send_hide = false;
        tap_code16(LALT(LSFT(KC_F16)));
    }
}
// ============================================================
// END CUSTOM QMK
// ============================================================
