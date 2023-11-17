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

        Plugin *lpPlugin = new Plugin();

        lpPlugin->mpacAuthor      = "Someone";
        lpPlugin->mpacDescription = "A plugin for ReNMS";
        lpPlugin->mpacDisplayName = "Unnamed Plugin";
        lpPlugin->mpPluginMain    = NULL;
        lpPlugin->mpPluginUpdate  = NULL;

        if (pluginIniFile.good())
        {
            spdlog::info("Found manifest");
            ini::IniFile pluginIni;
            pluginIni.decode(pluginIniFile);

            std::string lsName        = pluginIni["manifest"]["name"].as<std::string>();
            std::string lsAuthor      = pluginIni["manifest"]["author"].as<std::string>();
            std::string lsDescription = pluginIni["manifest"]["description"].as<std::string>();

            lpPlugin->mpacAuthor      = lsAuthor;
            lpPlugin->mpacDescription = lsDescription;
            lpPlugin->mpacDisplayName = lsName;

            spdlog::info("-----------PLUGIN INFORMATION-----------");
            spdlog::info(lsName);
            spdlog::info(lsAuthor);
            spdlog::info(lsDescription);
        }

        if (pluginLibFile.good())
        {
            spdlog::info("Found plugin DLL");
            Load(pluginLibrary, lpPlugin);
        }

        path lGameDataPath = PluginEntry.path() / "GAMEDATA";
        if (exists(lGameDataPath)) { HandleGamedata(lGameDataPath); }

        path lScriptPath = PluginEntry.path() / "scripts";
        if (exists(lScriptPath)) { HandleScripts(lScriptPath); }

        mPluginList.push_back(lpPlugin);
    }

    if (mPluginList.size() == 0) { spdlog::warn("No plugins found."); }
}

void PluginManager::HandleScripts(std::filesystem::path lScriptsPath)
{
    if (exists(lScriptsPath / "main.py")) { ExecutePythonFile(lScriptsPath / "main.py"); }
}

void PluginManager::Load(std::filesystem::path PluginPath, Plugin *lpPlugin)
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

    if (pluginEntry)
    {
        pluginEntry();
        lpPlugin->mpPluginMain = reinterpret_cast<LPVOID>(pluginEntry);
    }

    else { spdlog::error("Failed to load plugin: Couldn't find: void RENMS_ENTRY PluginMain()"); }
}

void PluginManager::HandleGamedata(std::filesystem::path lPluginPath)
{
    for (directory_entry lFileEntry : recursive_directory_iterator(lPluginPath))
    {
        if (lFileEntry.is_directory()) { continue; }

        std::ifstream *lFile  = new std::ifstream(lFileEntry.path());
        std::size_t lFileSize = file_size(lFileEntry.path());

        std::pair<void *, uint64_t> lFileDataAndSize = std::pair<void *, uint64_t>();
        lFileDataAndSize.first                       = reinterpret_cast<void *>(lFile);
        lFileDataAndSize.second                      = lFileSize;

        std::pair<std::string, std::pair<void *, uint64_t>> lOverride =
            std::pair<std::string, std::pair<void *, uint64_t>>();

        lOverride.first  = lPluginPath.string();
        lOverride.second = lFileDataAndSize;

        renms::config::AddModFileOverride(lOverride);
    }
}

RENMS_END