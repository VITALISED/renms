add_subdirectory(heridium)

make_directory(${CMAKE_SOURCE_DIR}/classcache)

add_executable(ClassMetadata
    "pch.cpp"
)

target_include_directories(ClassMetadata
    PRIVATE ${CMAKE_SOURCE_DIR}/classcache
    PRIVATE ${CMAKE_SOURCE_DIR}/classcache/source
    PRIVATE ${CMAKE_SOURCE_DIR}/classcache/toolkit
    PRIVATE ${CMAKE_SOURCE_DIR}/metadata/common
    PRIVATE ${CMAKE_SOURCE_DIR}/skyscraper
    PRIVATE ${CMAKE_SOURCE_DIR}/thirdparty/include
)

target_precompile_headers(ClassMetadata
    PRIVATE $ENV{CLASSMETADATA_FILES}
)

add_custom_command(OUTPUT ENV{CLASSMETADATA_FILES}
    COMMAND ${CMAKE_COMMAND} -P ./searchdirs.cmake
    COMMAND ${CMAKE_COMMAND} --build . --target ClassMetadata
    DEPENDS ExtractMetadata
)