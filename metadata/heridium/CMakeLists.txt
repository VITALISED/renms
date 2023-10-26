add_library(Heridium SHARED
    "dllmain.cpp"
    "analysis.h"
    "analysis.cpp"
    "heridium.h"
    "heridium.cpp"
    "cpp/header.cpp"
    "cpp/source.cpp"
    "cpp/notation.h"
    "cpp/lex.h"
    "cpp/lang.h"
)

target_include_directories(
    Heridium PRIVATE
    ${CMAKE_SOURCE_DIR}/thirdparty/include
    ${CMAKE_SOURCE_DIR}/skyscraper
    ${CMAKE_SOURCE_DIR}/renms_dll
)

target_link_libraries(Heridium PRIVATE
    fmt
    minhook
)

target_precompile_headers(Heridium PRIVATE
    "paths.h"
)

add_subdirectory(launcher)
make_directory(${CMAKE_SOURCE_DIR}/classcache)

add_custom_target(ExtractMetadata
    BYPRODUCTS ${CMAKE_SOURCE_DIR}/classcache/GIVEMEALLTHECLASSES.h
    COMMAND "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/heridiumLauncher.exe" "${NMS_EXE_DIR}/NMS.exe"
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/classcache
    DEPENDS Heridium heridiumLauncher
)