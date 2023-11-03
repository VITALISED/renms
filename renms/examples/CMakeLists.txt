add_library(example SHARED)

target_link_libraries(example minhook)

target_include_directories(
    example
    PUBLIC ${CMAKE_SOURCE_DIR}
    PUBLIC ${CMAKE_SOURCE_DIR}/renms
    PUBLIC ${CMAKE_SOURCE_DIR}/skyscraper
)

if(DEFINED EXAMPLE_BUILD_TYPE)
    if(${EXAMPLE_BUILD_TYPE} MATCHES "hook_example")
        add_subdirectory(hook_example)
    else()
        message(FATAL_ERROR "No example target found!")
    endif()
endif()
