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

file(GLOB_RECURSE RENMS_HEADERS ${PROJECT_SOURCE_DIR}/renms/ "*.h", "*.tpp")

add_library(
    renms SHARED
    ${PROJECT_SOURCE_DIR}/renms/dllmain.cpp
    ${PROJECT_SOURCE_DIR}/renms/memory/malloc.cpp
    ${PROJECT_SOURCE_DIR}/renms/plugins/plugin.cpp ${RENMS_HEADERS}
)

add_dependencies(renms renms_skyscraper Heridium heridiumLauncher)

target_include_directories(
    renms
    PUBLIC ${PROJECT_SOURCE_DIR}/renms
    PUBLIC ${PROJECT_SOURCE_DIR}/skyscraper
    PUBLIC ${PROJECT_SOURCE_DIR}/metadata/source
    PUBLIC ${PROJECT_SOURCE_DIR}/metadata/toolkit
    PUBLIC ${PROJECT_SOURCE_DIR}/submodules/spdlog/include
)

set_target_properties(renms PROPERTIES OUTPUT_NAME renms)

target_link_libraries(renms fmt PolyHook_2 spdlog)

add_dependencies(renms MetadataClasses)

target_precompile_headers(
    renms PRIVATE ${PROJECT_SOURCE_DIR}/renms/renms.h PRIVATE
    ${PROJECT_SOURCE_DIR}/skyscraper/skyscraper.h
)

target_compile_definitions(renms PRIVATE RENMS)

add_subdirectory(proxy)
add_subdirectory(examples)
