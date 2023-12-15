function(add_dependency_custom dir include)
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
    target_include_directories(
        renms_submodule_dependencies
        INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/${include}" SYSTEM
    )
endfunction()

function(invoke_adding_dependencies_renms)

    add_dependency_custom(./submodules/libSceFios2 ./submodules/libSceFios2)
    add_dependency_custom(
        ./submodules/inifile-cpp ./submodules/inifile-cpp/include
    )
    add_dependency_custom(./submodules/fmt ./submodules/fmt/include)

    add_dependency_custom(./submodules/spdlog ./submodules/spdlog/include)

    add_dependency_custom(./submodules/PolyHook2_0 ./submodules/PolyHook2_0)

    add_dependency_custom(
        ./submodules/robin-hood-hashing
        ./submodules/robin-hood-hashing/src/include
    )

    add_dependency_custom(
        ./submodules/Vulkan-Headers ./submodules/Vulkan-Headers/include
    )
    add_dependency_custom(
        ./submodules/VulkanMemoryAllocator
        ./submodules/VulkanMemoryAllocator/include
    )
    add_dependency_custom(./submodules/stb ./submodules/stb)

    add_dependency_custom(./submodules/pybind11 ./submodules/pybind11/include)

    add_dependency_custom(./submodules/rapidxml ./submodules/rapidxml)

    add_dependency_custom(./submodules/rapidjson ./submodules/rapidjson/include)
endfunction()
