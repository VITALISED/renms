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

add_subdirectory(2d)
add_subdirectory(camera)
add_subdirectory(shader)
add_subdirectory(utilities)

file(GLOB HEADERS *.h)

add_library(skyscraper_toolkit_graphics STATIC
    ${HEADERS}
)

target_link_libraries(skyscraper_toolkit_graphics PUBLIC
    skyscraper_toolkit_graphics_2d
    skyscraper_toolkit_graphics_camera
    skyscraper_toolkit_graphics_shader
    skyscraper_toolkit_graphics_utilities
)