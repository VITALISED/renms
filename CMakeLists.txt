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

cmake_minimum_required(VERSION 3.15)

project(
    renms
    LANGUAGES C CXX
    VERSION 0.0.1
)

# Set the output directory properly.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
message(STATUS "Binaries will be placed in: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

# Fix an issue with windows gnu systems where the c++std libs don't get privately
# linked, and since it isn't available on windows systems by default, it fails as
# it can't find the library.
if(CMAKE_CROSSCOMPILING)
    set(CMAKE_EXE_LINKER_FLAGS
        "${CMAKE_EXE_LINKER_FLAGS} -static-libstdc++ -static-libgcc"
    )
    message(STATUS "Crosscompiling setup detected, linking libstdc++ and libgcc statically.")
endif()

# Fix another issue where this dll can't be statically linked on windows, and must
# be copied to the output directory.
if (CMAKE_CROSSCOMPILING)
    find_path(WINPTHREAD_PATH NAMES libwinpthread-1.dll)
    if (NOT WINPTHREAD_PATH)
        message(WARNING "libwinpthread-1.dll not found! You may get an error while running heridiumLauncher.exe.")
    else()
        message(STATUS "libwinpthread-1.dll found at ${WINPTHREAD_PATH}")
        file(COPY ${WINPTHREAD_PATH}/libwinpthread-1.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    endif()
endif()

# Fix a dumb problem with certain setups where it adds "lib" to the front of the
# library name.
set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_PREFIX "")

# Fix a problem with Ninja where it doesn't place a newline and the first cmake
# output is on the same line as Ninja's.
if(CMAKE_GENERATOR STREQUAL "Ninja")
    message("")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG -D_DEBUG)
endif()

# ==================================================================================================
# First checks.

if(CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE "Release")
endif()

if(EXISTS "${CMAKE_SOURCE_DIR}/config.cmake")
    include(./config.cmake)
else()
    message(
        FATAL_ERROR
            "No config.cmake found! Check out the config-template.cmake."
    )
endif()

if(NOT DEFINED RENMS_CONFIG_VERSION OR RENMS_CONFIG_VERSION LESS 3)
    message(
        WARNING
            "Your config.cmake is out of date! Chances are it'll still build fine, but I highly \
suggest checking out the config-template.cmake and updating your config.cmake."
    )

endif()

if(NOT DEFINED NMS_EXE_PATH AND NOT SKIP_NMS_CHECK)
    message(
        FATAL_ERROR
            "NMS_EXE_PATH not defined!\n\
Look inside the config.cmake for the option, and set it's exact path. \
It must be the directory that contains NMS.exe. See the BUILD.md for why it needs to know this."
    )

endif()

get_filename_component(NMS_EXE_PATH "${NMS_EXE_PATH}" ABSOLUTE)
if(NOT EXISTS "${NMS_EXE_PATH}" AND NOT SKIP_NMS_CHECK)
    message(
        FATAL_ERROR
            "NMS_EXE_PATH either isn't a valid directory or doesn't contain NMS.exe!\n\
Look inside the config.cmake for the option, and set it's exact path. \
It must be the directory that contains NMS.exe. See the BUILD.md for why it needs to know this."
    )

elseif(NOT SKIP_NMS_CHECK)
    message(STATUS "NMS Executable found: ${NMS_EXE_PATH}")
else()
    message(
        STATUS
            "NMS.exe check skipped! Unless you already extracted all the metadata, the build will fail! Be warned!"
    )
endif()

# ==================================================================================================
# Dependencies.

# set Polyhook to use our dynamic runtime
if(MSVC)
    set(POLYHOOK_BUILD_STATIC_RUNTIME OFF)
endif()

macro(add_dependency_custom dir include)
    message(STATUS "Adding dependency: ${dir} (${include})")

    if(NOT EXISTS "${CMAKE_SOURCE_DIR}/${dir}/CMakeLists.txt")
        execute_process(
            COMMAND git submodule update --init --recursive ${dir}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        )
    endif()

    add_subdirectory(${dir})
    include_directories(${CMAKE_SOURCE_DIR}/${include})
endmacro()

add_dependency_custom(./submodules/fmt ./submodules/fmt/include)

set(SPDLOG_FMT_EXTERNAL ON)
set(SPDLOG_BUILD_SHARED OFF)
set(SPDLOG_ENABLE_PCH ON)
add_dependency_custom(./submodules/spdlog ./submodules/spdlog/include)
add_dependency_custom(./submodules/PolyHook2_0 ./submodules/PolyHook2_0)
add_dependency_custom(
    ./submodules/robin-hood-hashing ./submodules/robin-hood-hashing/src/include
)
add_dependency_custom(
    ./submodules/Vulkan-Headers ./submodules/Vulkan-Headers/include
)

# ==================================================================================================
# Targets.

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(renms)
add_subdirectory(skyscraper)
add_subdirectory(tools)

# --------------------------------------------------------------------------------------------------
# uberclean - A completely thorough clean that removes EVERYTHING that isn't
# included in the repo, including submodules. Useful for debugging build issues.
add_custom_target(
    uberclean
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
    COMMAND git submodule deinit --all -f
    COMMAND ${CMAKE_COMMAND} -E remove_directory
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${PROJECT_SOURCE_DIR}/metadata
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${PROJECT_SOURCE_DIR}/build
)

# --------------------------------------------------------------------------------------------------
# resdk - Generates the metadata classes for renms, giving it enough headers to make plugins for it.
make_directory(${PROJECT_SOURCE_DIR}/metadata)

add_custom_target(
    resdk DEPENDS ${PROJECT_SOURCE_DIR}/metadata/metadata.h
)

add_custom_command(
    OUTPUT ${PROJECT_SOURCE_DIR}/metadata/metadata.h
    COMMAND "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/heridiumLauncher.exe"
            "${NMS_EXE_PATH}"
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/metadata
    DEPENDS Heridium heridiumLauncher
)

# --------------------------------------------------------------------------------------------------
# renms_proxy settings
set_target_properties(renms_proxy PROPERTIES OUTPUT_NAME libSceFios2)

# --------------------------------------------------------------------------------------------------
# renms settings
add_dependencies(renms MetadataClasses Heridium heridiumLauncher)
target_link_libraries(renms fmt PolyHook_2 spdlog)

target_precompile_headers(
    renms
    PRIVATE
    ${PROJECT_SOURCE_DIR}/renms/renms.h
    PRIVATE
    ${PROJECT_SOURCE_DIR}/skyscraper/skyscraper.h
    PRIVATE
    ${PROJECT_SOURCE_DIR}/metadata/metadata.h
)

target_compile_definitions(renms PRIVATE RENMS)
set_target_properties(renms PROPERTIES OUTPUT_NAME renms)

target_include_directories(
    renms
    PUBLIC ${PROJECT_SOURCE_DIR}/renms
    PUBLIC ${PROJECT_SOURCE_DIR}/skyscraper
    PUBLIC ${PROJECT_SOURCE_DIR}/metadata/source
    PUBLIC ${PROJECT_SOURCE_DIR}/metadata/toolkit
    PUBLIC ${PROJECT_SOURCE_DIR}/submodules/spdlog/include
)

# --------------------------------------------------------------------------------------------------
# skyscraper settings
target_include_directories(
    renms_skyscraper PRIVATE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/skyscraper
)

# --------------------------------------------------------------------------------------------------
# heridiumLauncher settings (No settings needed)

# --------------------------------------------------------------------------------------------------
# Heridium settings
target_compile_definitions(Heridium PRIVATE RENMS)

target_include_directories(
    Heridium PUBLIC ${CMAKE_SOURCE_DIR}/skyscraper ${CMAKE_SOURCE_DIR}/renms
)
target_link_libraries(Heridium PRIVATE spdlog fmt PolyHook_2)
