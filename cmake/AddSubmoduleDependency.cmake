macro(add_dependency_custom dir include)
    message(STATUS "Adding dependency: ${dir} (${include})")

    file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/${dir}/*.h")
    if(HEADERS STREQUAL "")
        execute_process(
            COMMAND git submodule update --init --recursive --depth 1 ${dir}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        )
    endif()

    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${dir}/CMakeLists.txt")
        add_subdirectory(${dir} SYSTEM)
        set_source_files_properties(
            DIRECTORY ${dir} PROPERTIES COMPILE_FLAGS "-w"
        )
        set_source_files_properties(
            DIRECTORY ${dir} PROPERTIES LINKER_FLAGS "-w"
        )
    endif()
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/${include} SYSTEM)
endmacro()
