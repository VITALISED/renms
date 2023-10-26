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

if (EXISTS "${CMAKE_SOURCE_DIR}/config.cmake")
    include(./config.cmake)
else()
    message(FATAL_ERROR "No config.cmake found! Check out the config-template.cmake.")
endif()


## ================================================================================================== First checks.


if (NOT DEFINED NMS_EXE_DIR AND NOT SKIP_NMS_CHECK)
    message(FATAL_ERROR

"NMS_EXE_DIR not defined!\n\
Look inside the root CMakeLists.txt for the option, and set it's exact path. \
It must be the directory that contains NMS.exe, remember to use forward slashes (/). \
See the BUILD.md for why it needs to know this.")

endif()

get_filename_component(NMS_EXE_DIR "${NMS_EXE_DIR}" ABSOLUTE)
if (NOT EXISTS "${NMS_EXE_DIR}/NMS.exe" AND NOT SKIP_NMS_CHECK)
    message(FATAL_ERROR

"NMS_EXE_DIR either isn't a valid directory or doesn't contain NMS.exe!\n\
Remember to use forward slashes (/). See the BUILD.md for why it needs to know this.")

else()
    message(STATUS "NMS Executable found: ${NMS_EXE_DIR}/NMS.exe")
endif()


## ================================================================================================== Dependencies.


include(FetchContent)

set(CMAKE_FIND_PACKAGE_TARGETS_GLOBAL ON)

macro(FetchAndCheck dep includedir)
    message(STATUS "Looking for ${dep}...")
    FetchContent_MakeAvailable(${dep})

    set(DEP_SOURCE_DIR ${${dep}_SOURCE_DIR})

    get_directory_property(DEP_CXX_STANDARD DEP_SOURCE_DIR CMAKE_CXX_STANDARD)
    file(GLOB_RECURSE DEP_SOURCE_LIST ${DEP_SOURCE_DIR}${includedir}/*.h)
    set_source_files_properties(${DEP_SOURCE_LIST} VAR CMAKE_CXX_STANDARD DEP_CXX_STANDARD)
    include_directories(${${dep}_SOURCE_DIR}${includedir})
endmacro()

FetchContent_Declare(
    dep_fmt
    GIT_REPOSITORY "https://github.com/fmtlib/fmt.git"
)

FetchContent_Declare(
    dep_spdlog
    GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
    GIT_TAG "v1.x"
)

FetchContent_Declare(
    dep_minhook
    GIT_REPOSITORY "https://github.com/TsudaKageyu/minhook.git"
)

FetchContent_Declare(
    dep_vulkan
    GIT_REPOSITORY "https://github.com/KhronosGroup/Vulkan-Headers"
    GIT_TAG "374f9fd"
    BUILD_COMMAND "#Don't."
)

FetchContent_Declare(
    dep_robin_hood
    GIT_REPOSITORY "https://github.com/martinus/robin-hood-hashing.git"
)

FetchAndCheck(dep_fmt /include)
FetchAndCheck(dep_spdlog /include)
FetchAndCheck(dep_minhook /include)
FetchAndCheck(dep_vulkan /include)
FetchAndCheck(dep_robin_hood /src/include)


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
