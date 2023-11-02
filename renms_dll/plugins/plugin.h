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
#include "../memory/hooks.h"
#include <string>

RENMS_BEGIN

class PluginTemplate
{
    enum status
    {
        Ok,
        Failed,
        Exiting,
        Loading,
    };
    public:
    char* lpacPluginId;
    char* mpacDisplayName;
    char* mpacAuthor;
    char* mpacDescription;
};

class PluginManager
{
    public:
    std::vector<void*> mPluginList;

    PluginManager();
    void Load(const char* lpacPluginId);
    void Unload(const char* lpacPluginId);
    void Reload(const char* lpacPluginId);
};

RENMS_END