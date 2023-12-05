# Copyright (C) 2023  VITALISED & Contributors
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

set(RENMS_CONFIG_VERSION 3)

# Sorry for having it in a seperate file instead of having the option stuff be a
# part of the main CMakeLists.txt, but it's just to make sure these settings
# don't get synced with the repo.

option(SKIP_NMS_CHECK FALSE)
set(NMS_EXE_PATH "C:/Your/Path/To/NMS/Exe/Dir/Here/NMS.exe")
set(EXAMPLE_BUILD_TYPE "hook_example") # you can comment this out to not build
                                       # any examples
