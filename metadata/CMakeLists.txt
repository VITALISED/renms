add_subdirectory(heridium)

make_directory(${CMAKE_SOURCE_DIR}/classcache)

add_library(PrecompiledMetadata STATIC
    "pch.cpp"
)

target_include_directories(PrecompiledMetadata
    PRIVATE "${CMAKE_SOURCE_DIR}/skyscraper"
    PRIVATE "${CMAKE_SOURCE_DIR}/classcache/toolkit"
    PRIVATE "${CMAKE_SOURCE_DIR}/classcache/source"
)

add_dependencies(PrecompiledMetadata
    ExtractMetadata
)

target_precompile_headers(PrecompiledMetadata
    PRIVATE "${CMAKE_SOURCE_DIR}/classcache/GIVEMEALLTHECLASSES.h"
)