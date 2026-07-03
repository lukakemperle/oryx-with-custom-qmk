#!/usr/bin/env python3
"""Applies custom QMK patches after Oryx update. Called by the GitHub Actions workflow."""
import subprocess, sys

lid = sys.argv[1]

# Save custom section from current main branch keymap.c
main_kc = open(lid + '/keymap.c').read()
sep = '// CUSTOM QMK'
idx = main_kc.find(sep)
start = main_kc.rfind('// ====', 0, idx) if idx >= 0 else -1
custom = ('\n' + main_kc[start:]) if start >= 0 else ''

# Rebuild keymap.c from fresh Oryx content, then re-append the custom section.
# NOTE: combos (incl. K+L -> toggle L9) are now defined natively in Oryx,
# so no combo injection / COMBO_COUNT bump is needed here anymore.
kc = subprocess.check_output(['git', 'show', 'oryx:' + lid + '/keymap.c']).decode()
kc = kc.rstrip() + custom
open(lid + '/keymap.c', 'w').write(kc)
print('keymap.c patched')

# Take config.h verbatim from Oryx (COMBO_COUNT already correct there).
cfg = subprocess.check_output(['git', 'show', 'oryx:' + lid + '/config.h']).decode()
open(lid + '/config.h', 'w').write(cfg)
print('config.h synced from oryx')
