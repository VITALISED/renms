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

add_subdirectory(containers)
add_subdirectory(engine)
add_subdirectory(fsm)
add_subdirectory(random)

file(GLOB HEADERS *.h)
file(GLOB SOURCES *.cpp)

add_library(skyscraper_toolkit_utilities STATIC
    ${HEADERS}
    ${SOURCES}
)

target_link_libraries(skyscraper_toolkit_utilities PUBLIC
    skyscraper_toolkit_utilities_containers
    skyscraper_toolkit_utilities_engine
    skyscraper_toolkit_utilities_fsm
    skyscraper_toolkit_utilities_random
)