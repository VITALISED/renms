/**
 * @file plugin.h
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

#pragma once

#include <renms.h>

#include <core/config.h>
#include <plugins/api.h>

RENMS_BEGIN

class Plugin
{
  public:
    std::string msDisplayName;
    std::string msAuthor;
    std::string msDescription;
    std::string msLibraryName;
    fs::path mPluginPath;

    Plugin(
        std::string lsDisplayName, std::string lsAuthor, std::string lsDescription, fs::path lPluginPath,
        std::string lPluginLib);
    void LoadExecutable();
};

RENMS_END