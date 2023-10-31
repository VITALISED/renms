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

#include "../renms.h"

RENMS_BEGIN

enum PluginStatus
{
    Ok,
    Failed,
    Exiting,
    Loading,
};

class Plugin
{
    const char* mpacName;
    const char* mpacDisplayName;
    const char* mpacAuthor;
    const char* mpacDescription;
    HMODULE mHModule;

    virtual ~Plugin();
    virtual PluginStatus Initialise() = 0;
    virtual void Construct() = 0;
    virtual void Update(float lfTimeStep) = 0;
    virtual void Destruct() = 0;
};

class PluginManager
{
    std::vector<Plugin> mPlugins;

    PluginManager();
    void LoadPluginFolder();
    void Load(const char* lpacPluginName);
    void Unload(const char* lpacPluginName);
    void Reload(const char* lpacPluginName);
};

RENMS_END