# -- Doxygen
find_package(Doxygen)

if(DOXYGEN_FOUND)

    file(GLOB_RECURSE SKYSCRAPER_SOURCES "../skyscraper" "*.h")
    file(GLOB_RECURSE METADATA_SOURCES "./metadata" "*.h")

    set(DOXYGEN_METADATA_INPUT_DIR ${PROJECT_SOURCE_DIR}/metadata)
    set(DOXYGEN_SKYSCRAPER_INPUT_DIR ${PROJECT_SOURCE_DIR}/skyscraper)
    set(DOXYGEN_OUTPUT_DIR ${PROJECT_SOURCE_DIR}/docs/doxygen)
    set(DOXYGEN_INDEX_FILE ${DOXYGEN_OUTPUT_DIR}/html/index.html)
    set(DOXYFILE_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(DOXYFILE_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # Replace variables inside @@ with the current values
    configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)

    file(MAKE_DIRECTORY ${DOXYGEN_OUTPUT_DIR}) # Doxygen won't create this for
                                               # us
    add_custom_command(
        OUTPUT ${DOXYGEN_INDEX_FILE}
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
        MAIN_DEPENDENCY ${DOXYFILE_OUT}
        ${DOXYFILE_IN}
        COMMENT "Generating docs"
    )

    add_custom_target(Doxygen DEPENDS ${DOXYGEN_INDEX_FILE})

    # -- Sphinx

    find_package(Sphinx)

    if(SPHINX_FOUND)

        set(SPHINX_SOURCE ${CMAKE_CURRENT_SOURCE_DIR})
        set(SPHINX_BUILD ${CMAKE_CURRENT_BINARY_DIR}/docs/sphinx)

        add_custom_target(
            Sphinx
            COMMAND
                ${SPHINX_EXECUTABLE} -j auto -b html
                # Tell Breathe where to find the Doxygen output
                -Dbreathe_projects.ReNMS=${DOXYGEN_OUTPUT_DIR}/xml
                ${SPHINX_SOURCE} ${SPHINX_BUILD}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating documentation with Sphinx"
        )

        add_dependencies(Sphinx Doxygen)
        add_dependencies(Doxygen resdk)

    elseif(NOT SPHINX_FOUND)
        message(
            WARNING
                "Sphinx not found, only building partial documentation with Doxygen."
        )

    endif()
elseif(NOT DOXYGEN_FOUND)
    message(WARNING "Doxygen not found, cannot build documentation")

endif()

message(
    "Due to the size of the metadata, the documentation takes a million years to build."
    " As a result of that, the documentation is not built by default. If you want to build"
    " it, specify the Sphinx target. You can also build docs sooner with just Doxygen, but"
    " it won't be as complete."
)
