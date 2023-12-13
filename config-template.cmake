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

set(RENMS_CONFIG_VERSION 5)

# This is for convenience when using vscode's cmake tools extension. VSCode,
# in fact, does not set this sometimes. This won't effect the option if it's
# already set, so it's safe to leave this here.
set(CMAKE_BUILD_TYPE RelWithDebInfo)

set(BUILD_EXAMPLES ON)
set(NMS_EXE_PATH "C:/Your/Path/To/NMS/Exe/Dir/Here/NMS.exe")

# Currently does nothing, will be used for intercompatibility between versions.
set(NMS_BUILD 123456)

# This is just for debugging the build system, and access to NMS is 100%
# required for renms to build. See the BUILD.MD for more info.
set(SKIP_NMS_CHECK OFF)