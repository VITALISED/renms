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

#include "../renms.h"
#include "memory.h"
#include "hooks.h"

RENMS_BEGIN

MH_STATUS lastHookRes = MH_UNKNOWN;

template<typename HOOK_TYPE>
HookFunction<HOOK_TYPE>::HookFunction(char* lpacID, LPVOID lpDetour, LPVOID lpOffset) : mpacID(lpacID), mpDetour(lpDetour), mpOffset(lpOffset)
{
    if (lpOffset == 0) {
        //TODO: If the offset isn't specified, search by HOOK_TYPE.
    }

    this->mppOriginal = (LPVOID *) malloc(sizeof(LPVOID));
	lastHookRes = MH_CreateHook(lpOffset, lpDetour, lppOriginal);
    
    if (lastHookRes == MH_OK)
        spdlog::info("Created hook: {}", lpacID);
    else
        spdlog::error("MH_CreateHook failed: {}", MH_StatusToString(lastHookRes));
}

template<typename HOOK_TYPE>
HookFunction<HOOK_TYPE>::~HookFunction() {
    free(mppOriginal);
}

template<typename HOOK_TYPE>
void HookFunction<HOOK_TYPE>::IsEnabled(bool enabled) {
    if (enabled)
        lastHookRes = MH_EnableHook(mpOffset);
    else
        lastHookRes = MH_DisableHook(mpOffset);
    
    if (lastHookRes != MH_OK)
        spdlog::error("MH_ToggleHook failed: {}", MH_StatusToString(lastHookRes));
}

template<typename HOOK_TYPE>
HOOK_TYPE HookFunction<HOOK_TYPE>::CallOriginal(...) {
    HOOK_TYPE Original = *reinterpret_cast<HOOK_TYPE*>(mppOriginal);
    return Original(va_list());
}

template<typename HOOK_TYPE>
HOOK_TYPE HookFunction<HOOK_TYPE>::CallDetour(...) {
    HOOK_TYPE Original = *reinterpret_cast<HOOK_TYPE*>(&mpDetour);
    return Original(this, va_list());
}

RENMS_END