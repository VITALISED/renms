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


cmake_minimum_required(VERSION 3.15)

project(
    renms
    LANGUAGES C CXX
    VERSION 0.0.1
)


## Fix a problem with Ninja where it doesn't place a newline and the first cmake output is on the same line as Ninja's.
if (CMAKE_GENERATOR STREQUAL "Ninja")
    message("")
endif()


## ================================================================================================== First checks.


if (EXISTS "${CMAKE_SOURCE_DIR}/config.cmake")
    include(./config.cmake)
else()
    message(FATAL_ERROR "No config.cmake found! Check out the config-template.cmake.")
endif()

if (NOT DEFINED NMS_EXE_PATH AND NOT SKIP_NMS_CHECK)
    message(FATAL_ERROR

"NMS_EXE_PATH not defined!\n\
Look inside the root CMakeLists.txt for the option, and set it's exact path. \
It must be the directory that contains NMS.exe. See the BUILD.md for why it needs to know this.")

endif()

get_filename_component(NMS_EXE_PATH "${NMS_EXE_PATH}" ABSOLUTE)
if (NOT EXISTS "${NMS_EXE_PATH}" AND NOT SKIP_NMS_CHECK)
    message(FATAL_ERROR

"NMS_EXE_PATH either isn't a valid directory or doesn't contain NMS.exe!\n\
See the BUILD.md for why it needs to know this.")

elseif(NOT SKIP_NMS_CHECK)
    message(STATUS "NMS Executable found: ${NMS_EXE_PATH}")
else()
    message(STATUS "NMS.exe check skipped! Unless you already extracted all the metadata, the build will fail! Be warned!")
endif()


## ================================================================================================== Dependencies.


macro(add_dependency_custom dir include)
    if (NOT EXISTS "${CMAKE_SOURCE_DIR}/${dir}")
        message(FATAL_ERROR "Dependency ${dir} doesn't exist! Did you forget to sync your submodules with 'git submodule update --init --recursive' ?")
    endif()

    if (EXISTS "${CMAKE_SOURCE_DIR}/${dir}/CMakeLists.txt")
        add_subdirectory(${dir})
    endif()
    include_directories(${CMAKE_SOURCE_DIR}/${include})
endmacro()

add_dependency_custom(./fmt                 ./fmt/include)
add_dependency_custom(./minhook             ./minhook/include)
add_dependency_custom(./robin-hood-hashing  ./robin-hood-hashing/src/include)
add_dependency_custom(./spdlog              ./spdlog/include)
include_directories(./spdlog)
add_dependency_custom(./Vulkan-Headers      ./Vulkan-Headers/include)


## ================================================================================================== Compiler setup.


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

## /await and -fcoroutines may not be part of std yet, but it makes the task
## scheduler for the OS work more efficiently with our stuff, so we'll use it.

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /await /W4")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W4")

    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /WX")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /WX")
    endif()
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -fcoroutines -Wall -Wextra")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static -Wall -Wextra")

    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror")
    endif()
endif()

if (CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE "Release")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
message(STATUS "Binaries will be placed in: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


## ================================================================================================== Targets.


add_custom_target(uberclean
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_SOURCE_DIR}/metadata
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_SOURCE_DIR}/build
)


add_subdirectory(dumper)
add_subdirectory(renms_dll)
add_subdirectory(skyscraper)
