// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#define LAYOUT( \
k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k0e, \
k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, k1e, \
k20, k21, k22, k23, k24, k25, k26,      k28, k29, k2a, k2b, k2c, k2d, k2e, \
k30, k31, k32, k33, k34, k35, k36,      k38, k39, k3a, k3b, k3c, k3d, k3e, \
k40, k41, k42,           k45,                k49, k4a, k4b, k4c, k4d, k4e  \
) { \
    {k00,   k01, k02, k03,   k04,   k05, k06,   k07,   k08,   k09, k0a, k0b, k0c, k0d, k0e}, \
    {k10,   k11, k12, k13,   k14,   k15, k16,   k17,   k18,   k19, k1a, k1b, k1c, k1d, k1e}, \
    {k20,   k21, k22, k23,   k24,   k25, k26,   KC_NO, k28,   k29, k2a, k2b, k2c, k2d, k2e}, \
    {k30,   k31, k32, k33,   k34,   k35, k36,   KC_NO, k38,   k39, k3a, k3b, k3c, k3d, k3e}, \
    {k40,   k41, k42, KC_NO, KC_NO, k45, KC_NO, KC_NO, KC_NO, k49, k4a, k4b, k4c, k4d, k4e}  \
}

enum layers {
    BASE,
    FN,
    CUSTOM,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│Del│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │Hme│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │PgU│
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│ ↑ │PgD│
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │Ctrl│GUI │Alt │                        │Alt│ Fn│Ctl│ ← │ ↓ │ → │
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
    [BASE] = LAYOUT(
        QK_GESC,  KC_1,    KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9,     KC_0,        KC_MINS,        KC_EQL,  KC_BSPC,   KC_DEL,
        KC_TAB,  KC_Q,    KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O,     KC_P,        KC_LBRC,        KC_RBRC, KC_BSLS,   PB_1,
        KC_CAPS, KC_A,    KC_S, KC_D, KC_F, KC_G, KC_H,       KC_J, KC_K,     KC_L,        KC_SCLN,        KC_QUOT, KC_ENT,    PB_2,
        KC_LSFT, KC_Z,    KC_X, KC_C, KC_V, KC_B, KC_N,       KC_M, KC_COMM,  KC_DOT,      KC_SLSH,        KC_RSFT, KC_UP,     KC_BTN5,
        KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC,                 KC_RGUI,  MO(FN), MO(CUSTOM), KC_LEFT, KC_DOWN,   KC_RGHT
        ),

    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │ ` │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│ Delete│   │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │     │   │   │   │   │   │Ins│   │   │   │   │PSc│Scr│Pause│   │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │      │   │   │   │   │   │   │   │   │   │   │   │        │   │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │        │   │   │   │   │   │   │Mut│Vl-│Vl+│   │      │   │   │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │    │    │    │                        │   │   │   │   │   │   │
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
    [FN] = LAYOUT(
        KC_GRV, KC_F1, KC_F2, KC_F3,  KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,  KC_NO,
        KC_TILD,  KC_NO, KC_NO, KC_END, KC_NO, KC_NO, KC_NO, KC_NO, KC_INS, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,
        KC_NO,   KC_NO, KC_NO, KC_DEL,  KC_NO, KC_NO, KC_HOME,      KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,
        KC_NO,   KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,        KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_PGUP, KC_NO,
        KC_NO,   QK_BOOT, KC_NO,                KC_NO,                      KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_PGDN, KC_NO
        ),

    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │ ` │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│ Delete│   │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │     │   │   │   │   │   │Ins│   │   │   │   │PSc│Scr│Pause│   │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │      │   │   │   │   │   │   │   │   │   │   │   │        │   │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │        │   │   │   │   │   │   │Mut│Vl-│Vl+│   │      │   │   │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │    │    │    │                        │   │   │   │   │   │   │
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
    [CUSTOM] = LAYOUT(
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO,
        KC_TILD,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_INS,  KC_NO,  KC_NO,  KC_NO, KC_NO,
        KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,
        KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_VOLU, KC_MUTE,
        KC_NO,   KC_NO, KC_NO,               KC_MPLY,                     KC_NO,  KC_NO,  KC_NO,  KC_MPRV,  KC_VOLD, KC_MNXT
        ),
};
