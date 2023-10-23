add_subdirectory(heridium)

add_custom_target(PrecompileMetadata
    COMMAND "${CMAKE_COMMAND} -P" "./searchdirs.cmake"
    DEPENDS ExtractMetadata anotherfakething
)

add_library(exeMetadata SHARED
    "PrecompileMetadata.cpp"
)

add_custom_command(OUTPUT anotherfakething
    COMMAND "${CMAKE_COMMAND} -P" "./searchdirs.cmake"
)