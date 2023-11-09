#!/usr/bin/env python3
#

import pefile
import sys
import os.path

dll = pefile.PE("libSceFios2.dll")

print("EXPORTS")
for export in dll.DIRECTORY_ENTRY_EXPORT.symbols:
    if export.name:
        print('{}=libSceFios2_orig.{} @{}'.format(export.name.decode(), export.name.decode(), export.ordinal))