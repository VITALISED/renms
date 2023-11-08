add_library(example SHARED "dllmain.cpp")

target_link_libraries(example minhook spdlog fmt)

target_include_directories(
    example
    PUBLIC ${CMAKE_SOURCE_DIR}
    PUBLIC ${CMAKE_SOURCE_DIR}/renms
    PUBLIC ${CMAKE_SOURCE_DIR}/skyscraper
)
