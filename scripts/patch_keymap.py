#!/usr/bin/env python3
"""Applies custom QMK patches after Oryx update. Called by the GitHub Actions workflow."""
import re, subprocess, sys

lid = sys.argv[1]

# Save custom section from current main branch keymap.c
main_kc = open(lid + '/keymap.c').read()
sep = '// CUSTOM QMK'
idx = main_kc.find(sep)
start = main_kc.rfind('// ====', 0, idx) if idx >= 0 else -1
custom = ('\n' + main_kc[start:]) if start >= 0 else ''

# Build patched keymap.c from fresh oryx content
kc = subprocess.check_output(['git', 'show', 'oryx:' + lid + '/keymap.c']).decode()

# Patch 1: add E_L8 to enum custom_keycodes
kc = kc.replace('  ST_MACRO_4,\n};', '  ST_MACRO_4,\n  E_L8,\n};')

# Patch 2: rename process_record_user -> process_record_user_oryx
kc = kc.replace(
    'bool process_record_user(uint16_t keycode, keyrecord_t *record) {',
    'bool process_record_user_oryx(uint16_t keycode, keyrecord_t *record) {'
)

# Patch 3: replace LT(8, KC_E) with E_L8 everywhere
kc = kc.replace('LT(8, KC_E)', 'E_L8')

# Patch 4: add DANCE_1 to tap dance enum
kc = kc.replace(
    'enum tap_dance_codes {\n  DANCE_0,\n};',
    'enum tap_dance_codes {\n  DANCE_0,\n  DANCE_1,\n};'
)

# Patch 5: expand dance_state array from [1] to [2]
kc = kc.replace('static tap dance_state[1];', 'static tap dance_state[2];')

# Patch 6: add forward declarations for dance_1
kc = kc.replace(
    'void dance_0_finished(tap_dance_state_t *state, void *user_data);\nvoid dance_0_reset(tap_dance_state_t *state, void *user_data);',
    'void dance_0_finished(tap_dance_state_t *state, void *user_data);\nvoid dance_0_reset(tap_dance_state_t *state, void *user_data);\nvoid dance_1_finished(tap_dance_state_t *state, void *user_data);\nvoid dance_1_reset(tap_dance_state_t *state, void *user_data);'
)

# Patch 7: add dance_1 implementation before tap_dance_actions
# Single tap sends U respecting Caps Word; double tap toggles Caps Word
dance_1_impl = '''void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(is_caps_word_on() ? S(KC_U) : KC_U); break;
        case DOUBLE_TAP: caps_word_toggle(); break;
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(is_caps_word_on() ? S(KC_U) : KC_U); break;
    }
    dance_state[1].step = 0;
}

'''
kc = kc.replace('tap_dance_action_t tap_dance_actions[] = {', dance_1_impl + 'tap_dance_action_t tap_dance_actions[] = {')

# Patch 8: add DANCE_1 entry to tap_dance_actions
kc = kc.replace(
    '        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset),\n};',
    '        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset),\n        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_1_finished, dance_1_reset),\n};'
)

# Patch 9: replace KC_U with TD(DANCE_1) in layer 0 only
l0_start = kc.find('[0] = LAYOUT_voyager(')
l0_end = kc.find('\n  ),\n', l0_start) + 6
l0 = kc[l0_start:l0_end]
l0 = l0.replace('KC_U,', 'TD(DANCE_1),', 1)
kc = kc[:l0_start] + l0 + kc[l0_end:]

# Patch 10: add combo11 (KC_K + KC_L -> TG(9)) for layer-9 exit
kc = kc.replace(
    'combo_t key_combos[COMBO_COUNT] = {',
    'const uint16_t PROGMEM combo11[] = { KC_K, KC_L, COMBO_END};\n\ncombo_t key_combos[COMBO_COUNT] = {'
)
kc = kc.replace(
    '    COMBO(combo10, KC_BSPC),\n};',
    '    COMBO(combo10, KC_BSPC),\n    COMBO(combo11, TG(9)),\n};'
)

# Append custom section
kc = kc.rstrip() + custom
open(lid + '/keymap.c', 'w').write(kc)
print('keymap.c patched')

# Patch config.h: bump COMBO_COUNT by 1 for combo11
cfg = subprocess.check_output(['git', 'show', 'oryx:' + lid + '/config.h']).decode()
cfg = re.sub(
    r'#define COMBO_COUNT (\d+)',
    lambda m: '#define COMBO_COUNT ' + str(int(m.group(1)) + 1),
    cfg
)
open(lid + '/config.h', 'w').write(cfg)
print('config.h patched')
