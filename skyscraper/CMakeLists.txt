file(GLOB_RECURSE SKYSCRAPER_SOURCES "./" "*.cpp" "*.h")

add_library(
    renms_skyscraper
    ${SKYSCRAPER_SOURCES}
)

target_precompile_headers(
    renms_skyscraper REUSE_FROM PrecompiledMetadata
)

target_include_directories(
    renms_skyscraper PRIVATE
    ${CMAKE_SOURCE_DIR}
)
