/**
 * @file config.cpp
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

#include <core/config.h>
#include <plugins/manager.h>

RENMS_BEGIN

bool config::gShouldShowWarning               = true;
PluginManager *config::gPluginManager         = NULL;
std::vector<void *> *config::gUpdateCallbacks = NULL;

void config::Init()
{
    fs::path lNNSPath          = fs::current_path();
    fs::path lSettingsFilePath = lNNSPath / "RENMS/settings.ini";
    std::ifstream lSettingsIniFile(lSettingsFilePath);
    ini::IniFile pluginIni;

    config::gUpdateCallbacks = new std::vector<void *>();

    bool lbCreatePluginManager = true;

    if (!lSettingsIniFile.good())
    {
        config::Generate(lSettingsFilePath);
        spdlog::warn("No config found, one has been generated at {}", lSettingsFilePath.string());
        return;
    }
    else { spdlog::info("Config found at {}", lSettingsFilePath.string()); }

    pluginIni.decode(lSettingsIniFile);

    if (pluginIni["settings"].contains("show_warning"))
        gShouldShowWarning = pluginIni["settings"]["show_warning"].as<bool>();

    if (pluginIni["settings"].contains("disable_plugins")) lbCreatePluginManager = false;

    if (IsPlatformWine()) { spdlog::warn("You're running on a Wine-based installation. You might have problems!"); }

    if (lbCreatePluginManager) { gPluginManager = new PluginManager(); }
}

void config::Generate(fs::path configPath)
{
    ini::IniFile pluginIni;

    // Defaults

    pluginIni["settings"]["show_warning"]    = true;
    pluginIni["settings"]["disable_plugins"] = false;

    std::ofstream settingsIniFile(configPath);
    pluginIni.encode(settingsIniFile);
}

RENMS_END