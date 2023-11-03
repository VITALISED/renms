# Copyright (C) 2023  VITALISED, tractorbeam
#
# This program is free software: you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation, either version 3 of the License, or (at your option) any later
# version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
# details.
#
# You should have received a copy of the GNU General Public License along with
# this program.  If not, see <https://www.gnu.org/licenses/>.

# Rename this to "config.cmake" and it'll work

# Just making the options easier to read, and so you can do -DVAR=VAL on the
# command line if you really want to.
function(SetIfNotDef var val)
    if(NOT DEFINED ${var})
        set(${var}
            ${val}
            PARENT_SCOPE
        )
    endif()
endfunction()

setifnotdef(CMAKE_BUILD_TYPE Release)
setifnotdef(SKIP_NMS_CHECK FALSE)
setifnotdef(NMS_EXE_PATH "C:/Your/Path/To/NMS/Exe/Dir/Here/NMS.exe")
setifnotdef(FETCHCONTENT_QUIET OFF)
setifnotdef(EXAMPLE_BUILD_TYPE "hook_example") # you can comment this out to not
                                               # build any examples
