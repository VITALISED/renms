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

#pragma once

#include <renms.h>

#include <core/config.h>
#include <inicpp.h>
#include <plugins/api.h>
#include <scripts/python.h>

#include <filesystem>
#include <limits>
#include <string>

RENMS_BEGIN

class Plugin
{
  public:
    std::string mpacDisplayName;
    std::string mpacAuthor;
    std::string mpacDescription;
    LPVOID mpPluginMain;
    LPVOID mpPluginUpdate;
};

class PluginManager
{
  public:
    std::vector<Plugin *> mPluginList;

    PluginManager();
    void HandleGamedata(std::filesystem::path lPluginPath);
    void HandleScripts(std::filesystem::path lScriptPath);
    void Load(std::filesystem::path PluginPath, Plugin *lpPlugin);
    void Unload(std::filesystem::path PluginPath);
    void Reload(std::filesystem::path PluginPath);
};

RENMS_END