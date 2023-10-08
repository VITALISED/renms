cmake_minimum_required(VERSION 3.15)

project(
    renms
    LANGUAGES C CXX ASM_MASM
    VERSION 0.0.1
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(skyscraper)
add_subdirectory(renms_dll)
add_subdirectory(metadata)