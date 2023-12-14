/**
 * @file plugin.cpp
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

#include <plugins/plugin.h>

RENMS_BEGIN

Plugin::Plugin(
    std::string lsDisplayName, std::string lsAuthor, std::string lsDescription, fs::path lPluginPath,
    std::string lPluginLib)
    : msDisplayName(lsDisplayName), msAuthor(lsAuthor), msDescription(lsDescription), mPluginPath(lPluginPath),
      msLibraryName(lPluginLib)
{}

void Plugin::LoadExecutable()
{
    // Get library
    fs::path lLibraryPath = this->mPluginPath / msLibraryName;

    if (!fs::exists(lLibraryPath))
    {
        spdlog::info("No library found for {}, skipping step.", this->msDisplayName);
        return;
    }

    // Load it
    HMODULE PluginHandle = LoadLibraryA(lLibraryPath.string().c_str());
    if (PluginHandle == NULL)
    {
        spdlog::error(
            "Failed to load plugin library {}: couldn't load {} ", this->msDisplayName,
            lLibraryPath.filename().string());
        return;
    }

    // Execute plugin main
    PluginMain_t pluginEntry = reinterpret_cast<PluginMain_t>(GetProcAddress(PluginHandle, "PluginMain"));
    if (pluginEntry) { pluginEntry(); }
    else
    {
        spdlog::error(
            "Failed to load plugin library {}: Couldn't find: void RENMS_ENTRY PluginMain(), {}", this->msDisplayName,
            GetLastError());
        return;
    }

    PluginUpdate_t pluginUpdate = reinterpret_cast<PluginMain_t>(GetProcAddress(PluginHandle, "PluginUpdate"));
    if (pluginUpdate) { renms::config::gUpdateCallbacks->push_back(pluginUpdate); }
    else { spdlog::error("Couldn't find void RENMS_ENTRY PluginUpdate in {}, skipping step.", this->msDisplayName); }
}

RENMS_END