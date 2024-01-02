/**
 * @file GcApplication.cpp
 * @author VITALISED & Contributors
 * @since 2024-01-02
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

#include <application/GcApplication.h>

SKYSCRAPER_BEGIN

cGcApplication *cGcApplication::GetInstance()
{
    if (GetModuleHandleA("Galaxy64.dll"))
        return reinterpret_cast<nms::cGcApplication *>(renms::RelToAbsolute(0x49707E0));
    if (GetModuleHandleA("steam_api64.dll"))
        return reinterpret_cast<nms::cGcApplication *>(renms::RelToAbsolute(0x495EF10));

    std::runtime_error("Unknown platform!");

    return NULL;
}

SKYSCRAPER_END