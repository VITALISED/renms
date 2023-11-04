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

#pragma once

#include "../renms.h"

RENMS_BEGIN

#define RENMS_HOOK(name, return_type, arguments, types, offset, detour)                 \
    typedef return_type (*name##_SIGNATURE)(arguments);                                 \
    return_type name##__HOOK(arguments);                                                \
                                                                                        \
    renms::HookFunction<name##_SIGNATURE, return_type, types> name =                    \
        renms::HookFunction<name##_SIGNATURE, return_type, types>(                      \
            const_cast<char *>(#name), reinterpret_cast<LPVOID>(name##__HOOK), offset); \
                                                                                        \
    return_type name##__HOOK(arguments) detour

template <typename Fn, typename Ret, typename... Args>
class HookFunction
{
  private:
    char *mpacID;
    LPVOID *mppOriginal;
    LPVOID mpDetour;
    MH_STATUS mLastHookRes;

  public:
    LPVOID mpOffset;
    bool mbIsActive;

    HookFunction(char *lpacID, LPVOID lpDetour, LPVOID lpOffset);
    ~HookFunction();

    Ret CallOriginal(Args... lArgs);
    Ret CallDetour(Args... lArgs);

    void Toggle(bool lbEnabled);
};

RENMS_END

// This is just the way templates have to work, I'm sorry.
#include "hooks.tpp"
