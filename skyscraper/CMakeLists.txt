file(GLOB_RECURSE SKYSCRAPER_SOURCES *.h *.cpp)

add_library(
    renms_skyscraper
    ${SKYSCRAPER_SOURCES}
)

target_precompile_headers(
    renms_skyscraper REUSE_FROM PrecompiledMetadata
)

target_include_directories(
    renms_skyscraper PRIVATE
    ${CMAKE_SOURCE_DIR}/thirdparty/include
    ${CMAKE_SOURCE_DIR}/skyscraper
    ${CMAKE_SOURCE_DIR}/metadata/common
    ${CMAKE_SOURCE_DIR}/metadata/source
    ${CMAKE_SOURCE_DIR}/metadata/toolkit
)

target_link_directories(
    renms_skyscraper PRIVATE
    ${CMAKE_SOURCE_DIR}/thirdparty/lib
)

# set_target_properties(renms_skyscraper PROPERTIES LINKER_LANGUAGE CXX)
