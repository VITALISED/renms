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
    ${LIB}/minhook/minhook.x64d.a
    paths
)

add_subdirectory(launcher)

if (DEFINED WINE_EXECUTABLE)
    add_custom_target(ExtractMetadata
        COMMAND "${WINE_EXECUTABLE}" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/heridiumLauncher.exe" "${NMS_EXE_DIR}/NMS.exe"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/classcache
        DEPENDS Heridium heridiumLauncher
    )
else()
    add_custom_target(ExtractMetadata
        COMMAND "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/heridiumLauncher.exe" "${NMS_EXE_DIR}/NMS.exe"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/classcache
        DEPENDS Heridium heridiumLauncher
    )
endif()