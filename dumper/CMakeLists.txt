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


add_subdirectory(heridium)

make_directory(${CMAKE_SOURCE_DIR}/metadata)

add_custom_command(
    OUTPUT "${CMAKE_SOURCE_DIR}/metadata/GIVEMEALLTHECLASSES.h"
    COMMAND "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/heridiumLauncher.exe" "${NMS_EXE_DIR}/NMS.exe"
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/metadata
    DEPENDS Heridium heridiumLauncher
)

add_library(PrecompiledMetadata STATIC
    "pch.cpp"
    "${CMAKE_SOURCE_DIR}/metadata/GIVEMEALLTHECLASSES.h"
)

target_include_directories(PrecompiledMetadata
    PRIVATE "${CMAKE_SOURCE_DIR}/skyscraper"
    PRIVATE "${CMAKE_SOURCE_DIR}/metadata/toolkit"
    PRIVATE "${CMAKE_SOURCE_DIR}/metadata/source"
)

target_precompile_headers(PrecompiledMetadata
    PRIVATE "${CMAKE_SOURCE_DIR}/metadata/GIVEMEALLTHECLASSES.h"
)