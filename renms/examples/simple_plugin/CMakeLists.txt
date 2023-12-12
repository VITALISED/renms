add_library(example SHARED "dllmain.cpp")

target_link_libraries(example PRIVATE PolyHook_2 spdlog fmt renms_sdk)

target_include_directories(
    example
    PUBLIC ${CMAKE_SOURCE_DIR}
    PUBLIC ${CMAKE_SOURCE_DIR}/renms
    PUBLIC ${CMAKE_SOURCE_DIR}/skyscraper
    PUBLIC ${CMAKE_SOURCE_DIR}/metadata
    PUBLIC ${CMAKE_SOURCE_DIR}/sdk
)
