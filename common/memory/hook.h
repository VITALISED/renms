/**
 * @file hook.h
 * @author VITALISED & Contributors
 * @since 2023-12-31
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

#include <common/common_pch.h>
#include <common/memory/memory.h>
#include <polyhook2/Detour/NatDetour.hpp>
#include <polyhook2/Enums.hpp>
#include <polyhook2/IHook.hpp>
#include <polyhook2/PE/IatHook.hpp>

#if RENMS_POINTER_TYPE != uint64_t
#pragma message( \
    "RENMS_POINTER_TYPE does not equal uint64_t, if it isn't implicitly castable PolyHook might have problems.")
#endif

RENMS_BEGIN

inline std::string replace_hookid(std::string lsName)
{
    size_t liPos = lsName.find("__");
    if (liPos != std::string::npos) { return lsName.replace(liPos, 2, "::"); }
    return lsName;
}

#define RENMS_CAST(name, ...) PLH::FnCast(name##__TRAMPOLINE, name##__DETOUR)(__VA_ARGS__)

#define RENMS_HOOK(name, offset, return_type, detour_fn)              \
    RENMS_POINTER_TYPE name##__TRAMPOLINE = NULL;                     \
    return_type name##__DETOUR detour_fn PLH::x64Detour name##__HOOK( \
        offset, reinterpret_cast<RENMS_POINTER_TYPE>(name##__DETOUR), &name##__TRAMPOLINE)

#define RENMS_IAT_HOOK(name, module, return_type, detour_fn)        \
    RENMS_POINTER_TYPE name##__TRAMPOLINE = NULL;                   \
    return_type name##__DETOUR detour_fn PLH::IatHook name##__HOOK( \
        module, #name, reinterpret_cast<RENMS_POINTER_TYPE>(name##__DETOUR), &name##__TRAMPOLINE, L"NMS.exe");

#define RENMS_DISPATCH_HOOK(name)                                                                 \
    if (name##__HOOK.hook()) { spdlog::info("Enabling hook: {}", renms::replace_hookid(#name)); } \
    else { spdlog::error("Failed to enable hook: {}", renms::replace_hookid(#name)); }

RENMS_END