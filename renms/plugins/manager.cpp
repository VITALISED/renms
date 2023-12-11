/**
 * @file manager.cpp
 * @author VITALISED & Contributors
 * @since 2023-12-05
 *
 * Copyright (C) 2023  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <plugins/manager.h>

RENMS_BEGIN

Plugin *PluginManager::CreatePluginFromManifest(fs::path lPluginPath)
{
    fs::path lIniPath = lPluginPath / "manifest.ini";
    std::ifstream pluginIniFile(lIniPath);

    if (pluginIniFile.good())
    {
        spdlog::info("Found manifest");
        ini::IniFile pluginIni;
        pluginIni.decode(pluginIniFile);

        std::string lsName        = pluginIni["manifest"]["name"].as<std::string>();
        std::string lsAuthor      = pluginIni["manifest"]["author"].as<std::string>();
        std::string lsDescription = pluginIni["manifest"]["description"].as<std::string>();

        Plugin *lPlugin = new Plugin(lsName, lsAuthor, lsDescription, lPluginPath);

        spdlog::info("-----------PLUGIN INFORMATION-----------");
        spdlog::info(lsName);
        spdlog::info(lsAuthor);
        spdlog::info(lsDescription);
        spdlog::info("----------------------------------------");

        return lPlugin;
    }

    spdlog::error("Failed to find/parse plugin manifest at {}. Plugin not loaded", lPluginPath.string());

    return NULL;
}

PluginManager::PluginManager()
{
    // Populate the list with everything that's in the plugins folder
    fs::path nmsPath      = fs::current_path();
    fs::path PluginFolder = nmsPath / "RENMS/plugins";
    Plugin *lPlugin       = NULL;

    for (fs::directory_entry PluginEntry : fs::directory_iterator(PluginFolder))
    {
        if (!PluginEntry.is_directory()) continue;
        lPlugin = this->CreatePluginFromManifest(PluginEntry.path());

        if (!lPlugin) continue;

        lPlugin->LoadExecutable();
        lPlugin->LoadScripts();

        mPluginList.push_back(lPlugin);
    }

    if (mPluginList.size() == 0) { spdlog::warn("No plugins found."); }
}

RENMS_END