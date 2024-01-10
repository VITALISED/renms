/**
 * @file callbacks.cpp
 * @author VITALISED & Contributors
 * @since 2024-01-08
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
#include <callbacks.h>
#include <polyhook2/Detour/NatDetour.hpp>
#include <toolkit/system/filesystem/TkFileSystem.h>

SKYSCRAPER_BEGIN

ADD_HOOK_CALLBACK(cTkFileSystem, IsModded, bool cTkFileSystem_IsModded(cTkFileSystem *thiscall), thiscall);

SETUP_CALLBACK_DETOUR_ENTRY(INVOKE_CALLBACK_ENTRY(cTkFileSystem, IsModded));

SKYSCRAPER_END