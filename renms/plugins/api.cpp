/**
 * @file api.cpp
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

#include <memory/memory.h>
#include <plugins/api.h>
#include <polyhook2/Detour/x64Detour.hpp>

nms::cGcApplication *GetGcApplication()
{
    return reinterpret_cast<nms::cGcApplication *>(renms::RelToAbsolute(GCAPPLICATION));
}

renmshook_t RENMS_API CreateHook(uint64_t lpTarget, uint64_t lpDetour, uint64_t lpTrampoline)
{
    PLH::x64Detour *lpHook = new PLH::x64Detour(lpTarget, lpDetour, &lpTrampoline);

    return reinterpret_cast<renmshook_t>(lpHook);
}

bool RENMS_API DispatchHook(renmshook_t lpHook)
{
    PLH::x64Detour *lpHook_casted = reinterpret_cast<PLH::x64Detour *>(lpHook);

    return lpHook_casted->hook();
}

template <typename FnCastTo>
FnCastTo RENMS_API FnCast(uint64_t fnToCast, FnCastTo)
{
    return (FnCastTo)fnToCast;
}

template <typename FnCastTo>
FnCastTo RENMS_API FnCast(void *fnToCast, FnCastTo)
{
    return (FnCastTo)fnToCast;
}
