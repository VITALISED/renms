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
    paths
)

add_subdirectory(launcher)

if (NOT DEFINED WIN32)
    add_custom_command(
        OUTPUT fakething
        COMMAND "${WINE_EXECUTABLE}" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/launcher.exe" "${NMS_EXE_DIR}/NMS.exe"
        COMMAND "${CMAKE_COMMAND} -P" "${CMAKE_CURRENT_SOURCE_DIR}/SearchDirs.cmake"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        DEPENDS Heridium launcher
    )
else()
    add_custom_command(
        OUTPUT fakething
        COMMAND "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/launcher.exe" "${NMS_EXE_DIR}/NMS.exe"
        COMMAND "${CMAKE_COMMAND} -P" "${CMAKE_CURRENT_SOURCE_DIR}/SearchDirs.cmake"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        DEPENDS Heridium launcher
    )
endif()

#This is just so you can invoke the extraction without precompiling from the command line.
add_custom_target(
    ExtractMetadata
    DEPENDS fakething
)