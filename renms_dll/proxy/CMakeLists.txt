add_library(
    renms_proxy SHARED
    "dllmain.cpp"    
    "exports.h"
)

set_target_properties(renms_proxy PROPERTIES OUTPUT_NAME libSceFios2)
