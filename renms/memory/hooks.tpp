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
#include "hooks.h"
#include "memory.h"

RENMS_BEGIN

template <typename Fn>
HookFunction<Fn>::HookFunction(char *lpacID, Fn *lpDetour, LPVOID lpOffset)
    : mpacID(lpacID), mpDetour(lpDetour), mpOffset(lpOffset)
{
    if (lpOffset == 0 || lpOffset == NULL)
    {
        // TODO: If the offset isn't specified, search by HOOK_TYPE.
    }

    this->mppOriginal  = (LPVOID *)malloc(sizeof(LPVOID));
    this->mLastHookRes = MH_CreateHook(lpOffset, lpDetour, mppOriginal);

    if (this->mLastHookRes == MH_OK)
        spdlog::info("Created hook: {}", lpacID);
    else
        spdlog::error("MH_CreateHook {} failed: {}", lpacID, MH_StatusToString(this->mLastHookRes));
}

template <typename Fn>
HookFunction<Fn>::~HookFunction()
{
    free(mppOriginal);
}

template <typename Fn>
bool HookFunction<Fn>::SetEnabled()
{
    if (this->mbIsActive) return this->mbIsActive;

    if (this->mLastHookRes = MH_EnableHook(mpOffset) == MH_OK) this->mbIsActive = true;

    return this->mbIsActive;
}

template <typename Fn>
bool HookFunction<Fn>::SetDisabled()
{
    if (!this->mbIsActive) return this->mbIsActive;

    if (this->mLastHookRes = MH_DisableHook(mpOffset) == MH_OK) this->mbIsActive = false;

    return this->mbIsActive;
}

template <typename Fn>
bool HookFunction<Fn>::Toggle()
{
    if (this->mbIsActive)
        this->SetDisabled();
    else
        this->SetEnabled();
}

RENMS_END