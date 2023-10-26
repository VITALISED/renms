add_library(
    renms_dll SHARED
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

add_dependencies(renms_dll
    renms_skyscraper
    PrecompiledMetadata
)

target_include_directories(renms_dll
    PRIVATE ../skyscraper
    PRIVATE ../metadata/source
    PRIVATE ../metadata/toolkit
)

set_target_properties(renms_dll PROPERTIES OUTPUT_NAME renms)

target_link_libraries(renms_dll
    fmt
)

target_precompile_headers(renms_dll
    PRIVATE renms.h
    PRIVATE ../skyscraper/skyscraper.h
    PRIVATE ../metadata/GIVEMEALLTHECLASSES.h
)

add_subdirectory(proxy)