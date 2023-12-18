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
    heridium SHARED
    "analysis.cpp"
    "analysis.h"
    "cpp/header.cpp"
    "cpp/lang.h"
    "cpp/lex.h"
    "cpp/notation.h"
    "cpp/source.cpp"
    "dllmain.cpp"
    "heridium.cpp"
    "heridium.h"
    "logger.cpp"
    "logger.h"
)

target_compile_definitions(heridium PRIVATE D_NMS_VER=${NMS_BUILD})

set_target_properties(heridium PROPERTIES PREFIX "")

target_compile_definitions(heridium PRIVATE RENMS HERIDIUM)

target_include_directories(
    heridium PRIVATE ${PROJECT_SOURCE_DIR}/skyscraper
                     ${PROJECT_SOURCE_DIR}/renms ${PROJECT_SOURCE_DIR}
)
# Some of skyscraper's stuff requires the metadata that heridium generates, so
# we need to include only the bit of skyscraper that heridium needs.
target_link_libraries(
    heridium PRIVATE spdlog fmt PolyHook_2 renms_submodule_dependencies
)

add_subdirectory(launcher)
