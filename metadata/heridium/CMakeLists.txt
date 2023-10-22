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

add_library(paths STATIC
    "paths.cpp"
)

target_link_libraries(Heridium PRIVATE
    ${CMAKE_SOURCE_DIR}/thirdparty/lib/MinHook.x64.lib
    paths
)

add_subdirectory(launcher)

add_custom_command(
    OUTPUT ${META_SOURCE_DIR} ${META_TOOLKIT_DIR}
    COMMAND "${CMAKE_BINARY_DIR}/metadata/heridium/launcher/launcher.exe" "${NMS_EXE_DIR}/NMS.exe"
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    DEPENDS Heridium launcher
)

add_custom_target(
    BuildMetadata
    DEPENDS ${META_SOURCE_DIR} ${META_TOOLKIT_DIR}
)