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

using namespace std::filesystem;

RENMS_BEGIN

PluginManager::PluginManager()
{
    // Populate the list with everything that's in the plugins folder
    path nmsPath      = current_path();
    path PluginFolder = nmsPath / "RENMS/plugins";

    for (directory_entry PluginEntry : directory_iterator(PluginFolder))
    {
        if (!PluginEntry.is_directory()) continue;
        path pluginManifest = PluginEntry.path() / "config.ini";
        path pluginLibrary  = PluginEntry.path() / "plugin.dll";

        std::ifstream pluginIniFile(pluginManifest);
        std::ifstream pluginLibFile(pluginLibrary);

        if (pluginIniFile.good())
        {
            spdlog::info("Found manifest");
            ini::IniFile pluginIni;
            pluginIni.decode(pluginIniFile);

            std::string lsName        = pluginIni["manifest"]["name"].as<std::string>();
            std::string lsAuthor      = pluginIni["manifest"]["author"].as<std::string>();
            std::string lsDescription = pluginIni["manifest"]["description"].as<std::string>();

            spdlog::info("-----------PLUGIN INFORMATION-----------");
            spdlog::info(lsName);
            spdlog::info(lsAuthor);
            spdlog::info(lsDescription);
        }

        if (pluginLibFile.good())
        {
            spdlog::info("Found plugin DLL");
            Load(pluginLibrary);
        }
    }

    if (mPluginList.size() == 0) { spdlog::warn("No plugins found."); }
}

void PluginManager::Load(std::filesystem::path PluginPath)
{
    // Load the plugin DLL
    HMODULE PluginHandle = LoadLibraryW((LPCWSTR)PluginPath.string().c_str());
    if (PluginHandle == NULL)
    {
        spdlog::error("Failed to load plugin: {}", PluginPath.filename().string());
        return;
    }

    // Execute plugin main
    PluginMain_t pluginEntry = reinterpret_cast<PluginMain_t>(GetProcAddress(PluginHandle, "PluginMain"));
    if (pluginEntry) { pluginEntry(); }
    else { spdlog::error("Failed to load plugin: Couldn't find: void RENMS_ENTRY PluginMain()"); }
}

RENMS_END