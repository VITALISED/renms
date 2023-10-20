cmake_minimum_required(VERSION 3.15)

project(
    renms
    LANGUAGES C CXX ASM_MASM
    VERSION 0.0.1
)

function(C_APPEND_FLAGS FLAGS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLAGS}" PARENT_SCOPE)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${FLAGS}" PARENT_SCOPE)
endfunction()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD_REQUIRED ON)

if (CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE "Release")
endif()

##/await and -fcoroutines may not be part of std yet, but it makes the task scheduler for the OS work more efficiently with our stuff, so we'll use it.
if (MSVC)
    C_APPEND_FLAGS("/await /W4")
else()
    C_APPEND_FLAGS("-fcoroutines -Wall -Wextra -pedantic")
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    if (MSVC)
        C_APPEND_FLAGS("/WX")
    else()
        C_APPEND_FLAGS("-Werror")
    endif()
endif()

#if you aren't using it, you should be.
if (CMAKE_GENERATOR STREQUAL "Ninja")
    C_APPEND_FLAGS("-fdiagnostics-color=always")
endif()

#GNU Compilers have this set to "lib" by default, making some builds liblibEtc.a, which is annoying.
set(CMAKE_STATIC_LIBRARY_PREFIX "")

add_subdirectory(skyscraper)
add_subdirectory(renms_dll)
add_subdirectory(metadata)