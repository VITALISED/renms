/**
 * @file config.h
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

#include <common/platform/wine.h>
#include <inicpp.h>

RENMS_BEGIN

class PluginManager;

namespace config
{

extern bool gShouldShowWarning;
extern PluginManager *gPluginManager;
extern std::vector<void *> *gUpdateCallbacks;

void Init();
void Generate(fs::path configPath);

}; // namespace config

RENMS_END