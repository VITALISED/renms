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

file(GLOB HEADERS *.h)

add_subdirectory(filesystem)
add_subdirectory(memory)
add_subdirectory(pc)
add_subdirectory(thread)
add_subdirectory(timer)

add_library(skyscraper_toolkit_system STATIC
    ${HEADERS}
)

target_link_libraries(skyscraper_toolkit_system PUBLIC
    skyscraper_toolkit_system_filesystem
    skyscraper_toolkit_system_memory
    skyscraper_toolkit_system_pc
    skyscraper_toolkit_system_thread
    skyscraper_toolkit_system_timer
)