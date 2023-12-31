set(RENMS_COMMON_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/logging/logger.h
    ${CMAKE_CURRENT_SOURCE_DIR}/memory/hook.h
    ${CMAKE_CURRENT_SOURCE_DIR}/memory/memory.h
    ${CMAKE_CURRENT_SOURCE_DIR}/memory/vtable.h
    ${CMAKE_CURRENT_SOURCE_DIR}/thread/thread.h
)
set(RENMS_COMMON_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/logging/logger.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/memory/memory.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/platform/wine.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/thread/thread.cpp
)

add_library(renms_common STATIC ${RENMS_COMMON_HEADERS} ${RENMS_COMMON_SOURCES})

target_link_libraries(
    renms_common PUBLIC fmt PolyHook_2 spdlog renms_submodule_dependencies
)

target_include_directories(renms_common PUBLIC ${PROJECT_SOURCE_DIR})

target_precompile_headers(renms_common PUBLIC common_pch.h)
