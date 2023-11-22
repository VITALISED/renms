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

add_subdirectory(animation)
add_subdirectory(attachments)
add_subdirectory(audio)
add_subdirectory(data)
add_subdirectory(graphics)
add_subdirectory(resources)
add_subdirectory(system)
add_subdirectory(utilities)
add_subdirectory(voxel)

add_library(skyscraper_toolkit STATIC
    dummy.h
)

target_link_libraries(skyscraper_toolkit PUBLIC
    skyscraper_toolkit_animation
    skyscraper_toolkit_attachments
    skyscraper_toolkit_audio
    skyscraper_toolkit_data
    skyscraper_toolkit_graphics
    skyscraper_toolkit_resources
    skyscraper_toolkit_system
    skyscraper_toolkit_utilities
    skyscraper_toolkit_voxel
)