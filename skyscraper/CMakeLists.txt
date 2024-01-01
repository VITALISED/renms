# Copyright (C) 2023  VITALISED, tractorbeam
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

# old way of doing things @tractorbeam: everyone point and laugh at the cmake
# noob

file(GLOB_RECURSE SKYSCRAPER_HEADERS "./" "*.h" "*.inl")
file(GLOB_RECURSE SKYSCRAPER_SOURCES "./" "*.cpp")

add_library(skyscraper STATIC ${SKYSCRAPER_HEADERS} ${SKYSCRAPER_SOURCES})

target_include_directories(
    skyscraper
    PUBLIC ${PROJECT_SOURCE_DIR}/skyscraper
    PUBLIC ${RENMS_METADATA_DIR}
)

target_link_libraries(
    skyscraper PUBLIC renms_submodule_dependencies renms_common
)

if(NOT ${SKIP_NMS_CHECK})
    add_dependencies(skyscraper metadata_generator)
endif()
