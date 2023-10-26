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


add_library(
    renms_dll SHARED
    "dllmain.cpp"
    "commands/commands.h"
    # "commands/manager.h"
    # "commands/manager.cpp"
    # "commands/test.cpp"
    "memory/memory.h"
    "memory/hooks.h"
    "plugins/plugin.h"
    "plugins/plugin.cpp"
)

set_target_properties(renms_dll PROPERTIES OUTPUT_NAME renms)

target_link_libraries(renms_dll
    fmt::fmt
)

target_precompile_headers(renms_dll
    PRIVATE renms.h
    PRIVATE ../skyscraper/skyscraper.h
    REUSE_FROM PrecompiledMetadata
)

add_subdirectory(proxy)