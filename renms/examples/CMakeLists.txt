
if(DEFINED EXAMPLE_BUILD_TYPE)
    if(${EXAMPLE_BUILD_TYPE} MATCHES "hook_example")
        add_subdirectory(hook_example)
    else()
        message(FATAL_ERROR "No example target found!")
    endif()
endif()
