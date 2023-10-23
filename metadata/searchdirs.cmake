file(GLOB_RECURSE SOURCE_METADATA "source/")
file(GLOB_RECURSE TOOLKIT_METADATA "toolkit/")

target_precompile_headers(exeMetadata
    ${SOURCE_METADATA}
    ${TOOLKIT_METADATA}
)