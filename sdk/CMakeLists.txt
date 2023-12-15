add_library(
    renms_sdk STATIC
    "base.h"
    "core.h"
    "helpers.cpp"
    "helpers.h"
    "internal/memory.h"
    "textchat.cpp"
    "textchat.h"
)

target_link_libraries(renms_sdk PUBLIC skyscraper renms_submodule_dependencies)
