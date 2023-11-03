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

add_library(
    renms SHARED
    "commands/commands.h"
    # "commands/manager.h"
    # "commands/manager.cpp"
    # "commands/test.cpp"
    "dllmain.cpp"
    "framework.h"
    "log.h"
    "memory/hooks.h"
    "memory/hooks.tpp"
    "memory/malloc.cpp"
    "memory/malloc.h"
    "memory/memory.h"
    "memory/thread.h"
    "plugins/api.h"
    "plugins/plugin.cpp"
    "plugins/plugin.h"
)

add_dependencies(renms renms_skyscraper Heridium heridiumLauncher)

target_include_directories(
    renms
    PUBLIC "../skyscraper"
    PUBLIC "../metadata/source"
    PUBLIC "../metadata/toolkit"
    PUBLIC "../spdlog/include"
)

set_target_properties(renms PROPERTIES OUTPUT_NAME renms)

target_link_libraries(renms fmt minhook spdlog)

add_dependencies(renms MetadataClasses)

target_precompile_headers(
    renms
    PRIVATE
    renms.h
    PRIVATE
    ../skyscraper/skyscraper.h
    PRIVATE
    ../metadata/GIVEMEALLTHECLASSES.h
)

target_compile_definitions(renms PRIVATE RENMS)

add_subdirectory(proxy)

if(SHOULD_COMPILE_EXAMPLES)
    add_subdirectory(examples)
endif()
