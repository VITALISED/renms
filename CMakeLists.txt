# Copyright (C) 2023  VITALISED & Contributors
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

cmake_minimum_required(VERSION 3.15)

project(
    renms
    LANGUAGES C CXX
    VERSION 0.3
)

find_package(
    Python3
    COMPONENTS Development Interpreter
    REQUIRED
)

# ==================================================================================================
# Includes

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

include(AddSubmoduleDependency)
include(ConfigParser)
include(PrefixSourceFile)

# ==================================================================================================
# Local features

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})

    # Set the output directory properly.
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
    message(
        STATUS "Binaries will be placed in: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
    )

    # Fix a problem with Ninja where it doesn't place a newline and the first
    # cmake output is on the same line as Ninja's.
    if(CMAKE_GENERATOR STREQUAL "Ninja")
        message("")
    endif()

    message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

    if(NOT CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
        message(
            FATAL_ERROR
                "CMAKE_BUILD_TYPE must be set to RelWithDebInfo. I hate to do you like this, but"
                " this is what they built the game with and if the structs aren't exactly the"
                " same in memory, it won't work. Or it might, but then we have an even bigger"
                " problem."
        )
    endif()

    # ==============================================================================================
    # Config Stuff
    if(EXISTS "${CMAKE_SOURCE_DIR}/config.cmake")
        include(${CMAKE_SOURCE_DIR}/config.cmake)
    else()
        message(
            FATAL_ERROR
                "No config.cmake found! Check out the config-template.cmake."
        )
    endif()

    parse_config_values_renms()
    # ==============================================================================================

else()
    include(DefaultConfig)
endif()

# ==================================================================================================
# First checks.

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG -D_DEBUG)
endif()

# ==================================================================================================
# Dependencies.
find_package(Python3 REQUIRED)
set(SPDLOG_FMT_EXTERNAL ON)
set(SPDLOG_BUILD_SHARED OFF)
set(POLYHOOK_BUILD_STATIC_RUNTIME OFF)

invoke_adding_dependencies_renms()

# ==================================================================================================
# Targets.

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(skyscraper)
add_subdirectory(renms)
add_subdirectory(tools)
add_subdirectory(docs)
add_subdirectory(api)

file(
    GLOB_RECURSE
    SOURCES_TO_ADD_COMMENTS
    ${CMAKE_CURRENT_SOURCE_DIR}/skyscraper/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/skyscraper/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/renms/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/renms/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tools/heridium/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/tools/heridium/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/api/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/api/*.cpp
)

foreach(SOURCE_ITEM ${SOURCES_TO_ADD_COMMENTS})
    add_sources_prefix_renms(${SOURCE_ITEM})
endforeach()

# No library prefixes, useful for cross-compiling users
set_target_properties(renms heridium PROPERTIES PREFIX "")

# Make sure warnings about conversion from NULL to a pointer are disabled with
# non-MSVC compilers.
if(NOT DEFINED MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-conversion-null")
endif()

# --------------------------------------------------------------------------------------------------
# uberclean - A completely thorough clean that removes EVERYTHING that isn't
# included in the repo, including submodules. Useful for debugging build issues.
add_custom_target(
    uberclean
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
    COMMAND git submodule deinit --all -f
    COMMAND ${CMAKE_COMMAND} -E remove_directory
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMAND ${CMAKE_COMMAND} -E remove_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/metadata
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_CURRENT_SOURCE_DIR}/bin
    COMMAND ${CMAKE_COMMAND} -E remove_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/docs/doxygen/html
    COMMAND ${CMAKE_COMMAND} -E remove_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/docs/doxygen/latex
    COMMAND ${CMAKE_COMMAND} -E remove_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/docs/doxygen/xml
    COMMAND ${CMAKE_COMMAND} -E remove_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/build
)

# --------------------------------------------------------------------------------------------------
# resdk - Generates the metadata classes for renms, giving it enough headers to
# make plugins for it.
make_directory(${CMAKE_CURRENT_SOURCE_DIR}/metadata)

add_custom_target(resdk DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/metadata/metadata.h)

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/metadata/metadata.h
    COMMAND "$<TARGET_FILE:relauncher>" "${NMS_EXE_PATH}"
            "$<TARGET_FILE:heridium>"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/metadata
    DEPENDS heridium
)

# --------------------------------------------------------------------------------------------------
# skyscraper settings

if(NOT ${SKIP_NMS_CHECK})
    add_dependencies(skyscraper resdk)
endif()

target_include_directories(
    skyscraper
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/skyscraper
            ${CMAKE_CURRENT_SOURCE_DIR}/metadata
)

# --------------------------------------------------------------------------------------------------
# renms_proxy settings (None needed)

# --------------------------------------------------------------------------------------------------
# renms settings

if(NOT ${SKIP_NMS_CHECK})
    add_dependencies(resdk heridium relauncher)
endif()

add_dependencies(renms skyscraper)

target_link_libraries(
    renms
    skyscraper
    fmt
    PolyHook_2
    spdlog
    pybind11::embed
    ${PYTHON_LIBRARIES}
)
target_include_directories(renms PUBLIC ${PYTHON_INCLUDE_DIRS})

target_compile_definitions(renms PRIVATE RENMS FIOS_TYPES_ONLY)
target_compile_definitions(renms PUBLIC RENMS_VERSION="${PROJECT_VERSION}")
set_target_properties(renms PROPERTIES OUTPUT_NAME renms)

target_include_directories(
    renms
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/renms
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/skyscraper
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/metadata
)

# --------------------------------------------------------------------------------------------------
# relauncher settings (No settings needed)

# --------------------------------------------------------------------------------------------------
# heridium settings
target_compile_definitions(heridium PRIVATE RENMS)

target_include_directories(
    heridium PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/skyscraper
                    ${CMAKE_CURRENT_SOURCE_DIR}/renms
)
# Some of skyscraper's stuff requires the metadata that heridium generates, so
# we need to include only the bit of skyscraper that heridium needs.
target_link_libraries(heridium PRIVATE spdlog fmt PolyHook_2)

# ==================================================================================================
# Launch target

get_filename_component(NMS_BIN_PATH "${NMS_EXE_PATH}" DIRECTORY)

# Make sure the past installer's leftovers are uninstalled first!
add_custom_target(
    renms_launch
    COMMAND $<TARGET_FILE:relauncher> ${NMS_EXE_PATH} $<TARGET_FILE:renms>
    WORKING_DIRECTORY ${NMS_BIN_PATH}
    DEPENDS renms relauncher
)
