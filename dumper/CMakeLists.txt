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