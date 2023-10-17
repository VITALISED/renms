add_library(
    renms_dll
    "dllmain.cpp"
    "memory/memory.h"
    "memory/hooks.h"
)

set_target_properties(renms_dll PROPERTIES OUTPUT_NAME libSceFios2)

target_link_libraries(
    renms_dll PRIVATE ${CMAKE_SOURCE_DIR}/thirdparty/lib/MinHook.x64.lib
)

target_include_directories(
    renms_dll PRIVATE
    ${CMAKE_SOURCE_DIR}/thirdparty/include
)

target_precompile_headers(renms_dll PRIVATE renms.h)

add_subdirectory(proxy)