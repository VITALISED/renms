function(parse_config_values_renms)

    if(NOT DEFINED RENMS_CONFIG_VERSION OR RENMS_CONFIG_VERSION LESS 4)
        message(
            WARNING
                "Your config.cmake is out of date! Chances are it'll still build fine, but I highly \
suggest checking out the config-template.cmake and updating your config.cmake."
        )

    endif()

    if(NOT DEFINED NMS_EXE_PATH AND NOT SKIP_NMS_CHECK)
        message(
            FATAL_ERROR
                "NMS_EXE_PATH not defined!\n\
Look inside the config.cmake for the option, and set it's exact path. \
It must be the directory that contains NMS.exe. See the BUILD.md for why it needs to know this."
        )

    endif()

    get_filename_component(NMS_EXE_PATH "${NMS_EXE_PATH}" ABSOLUTE)
    if(NOT EXISTS "${NMS_EXE_PATH}" AND NOT SKIP_NMS_CHECK)
        message(
            FATAL_ERROR
                "NMS_EXE_PATH either isn't a valid directory or doesn't contain NMS.exe!\n\
Look inside the config.cmake for the option, and set it's exact path. \
It must be the directory that contains NMS.exe. See the BUILD.md for why it needs to know this."
        )

    elseif(NOT SKIP_NMS_CHECK)
        message(STATUS "NMS Executable found: ${NMS_EXE_PATH}")
    else()
        message(
            STATUS
                "NMS.exe check skipped! Unless you already extracted all the metadata, the build will fail! Be warned!"
        )
    endif()

    if(NOT DEFINED NMS_BUILD AND NOT SKIP_NMS_CHECK)
        message(
            FATAL_ERROR
                "NMS_BUILD isn't specified, this means metadata cannot generate properly."
        )
    endif()

endfunction()
