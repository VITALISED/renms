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

MH_STATUS lastHookRes = MH_UNKNOWN;

inline LPVOID RelToAbsPtr(uintptr_t lpRelPtr) {
    return (LPVOID) ((uintptr_t)GetModuleHandleA("NMS.exe") + (uintptr_t)lpRelPtr);
}

template<typename HOOK_TYPE>
HookFunction<HOOK_TYPE>::HookFunction(char* ID, LPVOID pDetour, LPVOID offset)
{
    if (offset == 0) {
        //TODO: If the offset isn't specified, search by HOOK_TYPE.
    }

    this->ppOriginal = (LPVOID *) malloc(sizeof(LPVOID));
	lastHookRes = MH_CreateHook(offset, pDetour, ppOriginal);
    
    if (lastHookRes == MH_OK)
        spdlog::info("Created hook: {}", ID);
    else
        spdlog::error("MH_CreateHook failed: {}", MH_StatusToString(lastHookRes));
}

template<typename HOOK_TYPE>
HookFunction<HOOK_TYPE>::~HookFunction() {
    free(ppOriginal);
}

template<typename HOOK_TYPE>
void HookFunction<HOOK_TYPE>::IsEnabled(bool enabled) {
    if (enabled)
        lastHookRes = MH_EnableHook(offset);
    else
        lastHookRes = MH_DisableHook(offset);
    
    if (lastHookRes != MH_OK)
        spdlog::error("MH_ToggleHook failed: {}", MH_StatusToString(lastHookRes));
}

template<typename HOOK_TYPE>
HOOK_TYPE HookFunction<HOOK_TYPE>::CallOriginal(...) {
    HOOK_TYPE = *reinterpret_cast<HOOK_TYPE*>(ppOriginal);
    return HOOK_TYPE(...);
}

template<typename HOOK_TYPE>
HOOK_TYPE HookFunction<HOOK_TYPE>::CallDetour(...) {
    HOOK_TYPE = *reinterpret_cast<HOOK_TYPE*>(ppDetour);
    return HOOK_TYPE(this ...)
}