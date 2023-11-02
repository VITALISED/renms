/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "plugin.h"
#include <filesystem>
using namespace std::filesystem;

RENMS_BEGIN

PluginManager::PluginManager()
{

    //Populate the list with everything that's in the plugins folder
    path nmsPath = current_path();
    path PluginFolder = nmsPath / "renms/plugins";

    if (!is_directory(PluginFolder))
        create_directories(PluginFolder);

    for (directory_entry PluginEntry : directory_iterator(PluginFolder)) {
        if (!PluginEntry.is_regular_file()) continue;
        path Plugin = PluginEntry;
        
        if (Plugin.filename().extension() != "rn") continue;

        
    }
}

RENMS_END