# Copyright (C) 2023  VITALISED & Contributors
#
# This program is free software: you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation, either version 3 of the License, or (at your option) any later
# version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
# details.
#
# You should have received a copy of the GNU General Public License along with
# this program.  If not, see <https://www.gnu.org/licenses/>.

set(RENMS_CORE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/dllmain.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/plugins/plugin.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/plugins/api.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/plugins/fsm.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/plugins/manager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/logging/logger.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/core/warning.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/core/config.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/core/filesystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/commands/builtin.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/commands/commands.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/commands/dispatcher.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fios/fios.cpp
)

set(RENMS_CORE_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/commands/builtin.h
    ${CMAKE_CURRENT_SOURCE_DIR}/commands/commands.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core/config.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core/filesystem.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core/framework.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core/warning.h
    ${CMAKE_CURRENT_SOURCE_DIR}/fios/fios.h
    ${CMAKE_CURRENT_SOURCE_DIR}/logging/logger.h
    ${CMAKE_CURRENT_SOURCE_DIR}/logging/textchatsink.h
    ${CMAKE_CURRENT_SOURCE_DIR}/memory/hook.h
    ${CMAKE_CURRENT_SOURCE_DIR}/memory/memory.h
    ${CMAKE_CURRENT_SOURCE_DIR}/memory/thread.h
    ${CMAKE_CURRENT_SOURCE_DIR}/memory/vtable.h
    ${CMAKE_CURRENT_SOURCE_DIR}/plugins/api.h
    ${CMAKE_CURRENT_SOURCE_DIR}/plugins/fsm.h
    ${CMAKE_CURRENT_SOURCE_DIR}/plugins/manager.h
    ${CMAKE_CURRENT_SOURCE_DIR}/plugins/plugin.h
    ${CMAKE_CURRENT_SOURCE_DIR}/renms.h
)

add_library(renms_core SHARED ${RENMS_CORE_HEADERS} ${RENMS_CORE_SOURCES})

add_dependencies(renms_core skyscraper)

target_link_libraries(
    renms_core PRIVATE skyscraper fmt PolyHook_2 spdlog renms_sdk
                       renms_submodule_dependencies
)
target_compile_definitions(renms_core PRIVATE RENMS FIOS_TYPES_ONLY)
target_compile_definitions(renms_core PUBLIC RENMS_VERSION="${PROJECT_VERSION}")

set_target_properties(renms_core PROPERTIES OUTPUT_NAME renms)

target_include_directories(
    renms_core
    PRIVATE ${PROJECT_SOURCE_DIR}
    PRIVATE ${PROJECT_SOURCE_DIR}/renms
    PRIVATE ${PROJECT_SOURCE_DIR}/skyscraper
    PRIVATE ${PROJECT_SOURCE_DIR}/metadata
    PRIVATE ${PROJECT_SOURCE_DIR}/sdk
)

set_target_properties(renms_core PROPERTIES PREFIX "")

add_subdirectory(proxy)
add_subdirectory(examples)
