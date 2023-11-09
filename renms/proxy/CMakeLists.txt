add_library(renms_proxy SHARED "dllmain.cpp" "exports.h")

if(NOT MSVC)
    target_sources(renms_proxy PRIVATE exports.def)
endif()
