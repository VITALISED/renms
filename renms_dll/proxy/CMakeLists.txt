add_library(
    renms_proxy SHARED
    "dllmain.cpp"    
)

set_target_properties(renms_proxy PROPERTIES OUTPUT_NAME SceFios2)
