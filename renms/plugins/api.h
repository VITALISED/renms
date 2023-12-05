/**
 * @file api.h
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

#include <application/GcApplication.h>
#include <toolkit/utilities/string/TkString.h>

typedef uint64_t renmshook_t;

#ifdef RENMS
#define RENMS_ENTRY __declspec(dllimport)
#else
#define RENMS_ENTRY __declspec(dllexport)
#endif

#define RENMS_API extern

#define GCAPPLICATION         0x49707E0
#define GCTEXTCHATMANAGER_SAY 0x806080

void RENMS_ENTRY PluginMain();
void RENMS_ENTRY PluginUpdate(float lfTimeStep);

typedef decltype(PluginMain) *PluginMain_t;
typedef decltype(PluginUpdate) *PluginUpdate_t;

renmshook_t RENMS_API CreateHook(uint64_t lpTarget, uint64_t lpDetour, uint64_t lpTrampoline);
bool RENMS_API DispatchHook(renmshook_t lpHook);
nms::cGcApplication *GetGcApplication();

// re-exported from PLH

template <typename FnCastTo>
FnCastTo RENMS_API FnCast(uint64_t fnToCast, FnCastTo);

template <typename FnCastTo>
FnCastTo RENMS_API FnCast(void *fnToCast, FnCastTo);