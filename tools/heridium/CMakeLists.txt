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

set(HERIDIUM_SOURCE_DIR ${PROJECT_SOURCE_DIR}/tools/heridium)

add_library(
    Heridium SHARED
    ${HERIDIUM_SOURCE_DIR}/dllmain.cpp
    ${HERIDIUM_SOURCE_DIR}/analysis.h
    ${HERIDIUM_SOURCE_DIR}/analysis.cpp
    ${HERIDIUM_SOURCE_DIR}/heridium.h
    ${HERIDIUM_SOURCE_DIR}/heridium.cpp
    ${HERIDIUM_SOURCE_DIR}/cpp/header.cpp
    ${HERIDIUM_SOURCE_DIR}/cpp/source.cpp
    ${HERIDIUM_SOURCE_DIR}/cpp/notation.h
    ${HERIDIUM_SOURCE_DIR}/cpp/lex.h
    ${HERIDIUM_SOURCE_DIR}/cpp/lang.h
)

target_include_directories(
    Heridium PUBLIC ${CMAKE_SOURCE_DIR}/skyscraper ${CMAKE_SOURCE_DIR}/renms
)

target_link_libraries(Heridium PRIVATE fmt PolyHook_2 spdlog)

add_subdirectory(launcher)
