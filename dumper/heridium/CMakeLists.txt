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


add_library(Heridium SHARED
    "dllmain.cpp"
    "analysis.h"
    "analysis.cpp"
    "heridium.h"
    "heridium.cpp"
    "cpp/header.cpp"
    "cpp/source.cpp"
    "cpp/notation.h"
    "cpp/lex.h"
    "cpp/lang.h"
)

target_include_directories(
    Heridium PUBLIC
    ${CMAKE_SOURCE_DIR}/skyscraper
    ${CMAKE_SOURCE_DIR}/renms_dll
)

target_link_libraries(Heridium PRIVATE
    fmt
    minhook
    spdlog
)

target_precompile_headers(Heridium PRIVATE
    "paths.h"
)

add_subdirectory(launcher)
