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


file(GLOB_RECURSE SKYSCRAPER_SOURCES "./" "*.cpp" "*.h")

add_library(
    renms_skyscraper
    ${SKYSCRAPER_SOURCES}
)

target_precompile_headers(
    renms_skyscraper REUSE_FROM PrecompiledMetadata
)

target_include_directories(
    renms_skyscraper PRIVATE
    ${CMAKE_SOURCE_DIR}/thirdparty/include
    ${CMAKE_SOURCE_DIR}/skyscraper
    ${CMAKE_SOURCE_DIR}/metadata/common
    ${CMAKE_SOURCE_DIR}/metadata/source
    ${CMAKE_SOURCE_DIR}/metadata/toolkit
)
