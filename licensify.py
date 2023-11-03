#    Copyright (C) 2023  VITALISED, tractorbeam
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <https://www.gnu.org/licenses/>.

# This file appends the license to the top of every file in all the files.

import os
import sys
import argparse
import subprocess

COPYRIGHT_YEAR = "2023"
COPYRIGHT_AUTHOR = "VITALISED, tractorbeam"


LICENSE = "    Copyright (C) " + COPYRIGHT_YEAR + "  " + COPYRIGHT_AUTHOR + """

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>."""

filecount = 0
# Find all files in the current directory.
def getfiles(extension):
    files = []
    for root, dirs, filenames in os.walk('.'):
        for filename in filenames:
            if filename.endswith(extension):
                fullpath = os.path.join(root, filename)
                if "build/" not in fullpath and "metadata/" not in fullpath:
                    files.append(fullpath)
    return files


def add_to_beginning(filepath, text):
    global filecount

    oldfile = open(filepath, "r")
    if text in oldfile.read():
        return
    newfilestr = text + oldfile.read()
    oldfile.close()

    filecount += 1
    newfile = open(filepath, "w")
    newfile.write(newfilestr)
    newfile.close()

c_files  = getfiles('.cpp')
c_files += getfiles('.h')
py_cmake_files  = getfiles('.py')
py_cmake_files += getfiles('.cmake')
py_cmake_files += getfiles('.txt')

# Appends to the beginning of the c files:
# /*
#   ...
# */
for file in c_files:
    cLICENSE = "/*\n" + LICENSE + "\n*/\n\n"
    add_to_beginning(file, cLICENSE)

# Appends to the beginning of the python or cmake files:
# #  ...
for file in py_cmake_files:
    pyLICENSE = "#"
    for c in LICENSE:
        if c == '\n':
            pyLICENSE += '\n#'
        else:
            pyLICENSE += c
    
    pyLICENSE += "\n\n"
    add_to_beginning(file, pyLICENSE)

print("Added license info to " + str(filecount) + " files.")