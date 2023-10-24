cmake_minimum_required(VERSION 3.15)

project(
    renms
    LANGUAGES C CXX
    VERSION 0.0.1
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

message("\n")   ## Fix a problem with Ninja where it doesn't place a newline and the first output is on the same line as the Ninja.


## ================================================================================================== Functions.


function(C_APPEND_FLAGS FLAGS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLAGS}" PARENT_SCOPE)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${FLAGS}" PARENT_SCOPE)
endfunction()


function(CHECK_OS)
    if (DEFINED APPLE)
        message("=== OS is macOS")
    elseif (DEFINED UNIX)
        ## While UNIX *is* defined with APPLE under macOS, this is an else if, so it won't run if APPLE is defined.
        message("=== OS is Unix/Linux")
    elseif(DEFINED WIN32)
        message("=== OS is Windows")
    else()
        message("=== OS is some strange thing other than Windows, macOS, or Unix/Linux. Building anyways! (No Promises)")
    endif()

    if (NOT DEFINED WIN32)
        message("=== Cross-compiling for Windows")
        if (NOT DEFINED WINE_EXECUTABLE)
            find_program(WINE_EXECUTABLE wine)
        endif()
    endif()
endfunction()


function(CHECK_NMS_DIR)
    if (NOT DEFINED NMS_EXE_DIR)
        message(FATAL_ERROR

"NMS_EXE_DIR not defined!\n\
Append ( -DNMS_EXE_DIR=\"C:/.../No Man's Sky/Binaries\" ) to your cmake command. \
It must be the directory that contains NMS.exe, remember to use forward slashes (/). \
See the BUILD.md for why it needs to know this.")

    endif()
    get_filename_component(NMS_EXE_DIR "${NMS_EXE_DIR}" ABSOLUTE)
    if (NOT EXISTS "${NMS_EXE_DIR}/NMS.exe")
        message(FATAL_ERROR

"NMS_EXE_DIR either isn't a valid directory or doesn't contain NMS.exe!\n\
Remember to use forward slashes (/). See the BUILD.md for why it needs to know this.")

    else()
        message("=== NMS Executable found: ${NMS_EXE_DIR}/NMS.exe")
    endif()
endfunction()


## ================================================================================================== Main.


set(LIB ${CMAKE_CURRENT_SOURCE_DIR}/lib)
CHECK_OS()
CHECK_NMS_DIR()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
message("=== Binaries will be placed in: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

if (CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE "Release")
endif()

## /await and -fcoroutines may not be part of std yet, but it makes the task
## scheduler for the OS work more efficiently with our stuff, so we'll use it.

if (MSVC)
    C_APPEND_FLAGS("/W4")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /await")
    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        C_APPEND_FLAGS("/WX")
    endif()
else()
    C_APPEND_FLAGS("-Wall -Wextra")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcoroutines")
    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        C_APPEND_FLAGS("-Werror")
    endif()
endif()

## if you aren't using it, you should be.
if (CMAKE_GENERATOR STREQUAL "Ninja")
    C_APPEND_FLAGS("-fdiagnostics-color=always")
endif()

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/lib)

add_subdirectory(metadata)
add_subdirectory(renms_dll)
add_subdirectory(skyscraper)
add_subdirectory(thirdparty)

## Finally, the clean target.
add_custom_target(uberclean
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_SOURCE_DIR}/classcache
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${LIB}
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
)