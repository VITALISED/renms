/**
 * @file TkFileSystem.cpp
 * @author VITALISED & Contributors
 * @since 2024-01-03
 *
 * Copyright (C) 2024  VITALISED & Contributors
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

#include <toolkit/system/filesystem/TkFileSystem.h>

SKYSCRAPER_BEGIN

cTkFileSystem *cTkFileSystem::GetInstance()
{
    if (GetModuleHandleA("Galaxy64.dll")) return reinterpret_cast<cTkFileSystem *>(renms::RelToAbsolute(0x44C0578));
    if (GetModuleHandleA("steam_api64.dll")) return reinterpret_cast<cTkFileSystem *>(renms::RelToAbsolute(0x44AEC88));

    std::runtime_error("Unknown platform!");

    return NULL;
}

SKYSCRAPER_END