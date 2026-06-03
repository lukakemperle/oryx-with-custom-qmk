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
kc = kc.replace('LT(8, KC_E)', 'E_L8')
kc = kc.replace(
    'combo_t key_combos[COMBO_COUNT] = {',
    'const uint16_t PROGMEM combo11[] = { KC_K, KC_L, COMBO_END};\n\ncombo_t key_combos[COMBO_COUNT] = {'
)
kc = kc.replace(
    '    COMBO(combo10, KC_BSPC),\n};',
    '    COMBO(combo10, KC_BSPC),\n    COMBO(combo11, TG(9)),\n};'
)
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
