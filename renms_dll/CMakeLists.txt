add_library(
    renms_dll
    "dllmain.cpp"
    "commands/commands.h"
    # "commands/manager.h"
    # "commands/manager.cpp"
    # "commands/test.cpp"
    "memory/memory.h"
    "memory/hooks.h"
    "plugins/plugin.h"
    "plugins/plugin.cpp"

)

set_target_properties(renms_dll PROPERTIES OUTPUT_NAME renms)

target_link_libraries(
    renms_dll PRIVATE ${CMAKE_SOURCE_DIR}/thirdparty/lib/MinHook.x64.lib
)

target_include_directories(
    renms_dll PRIVATE
    ${CMAKE_SOURCE_DIR}/thirdparty/include
)

target_precompile_headers(renms_dll PRIVATE renms.h)

add_subdirectory(proxy)