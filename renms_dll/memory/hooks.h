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

inline LPVOID RelToAbsPtr(int lpRelPtr);

//An easier way of defining a HookFunction object.
#define Hook(name, signature, detour, offset) HookFunction<signature> name = HookFunction<signature>(#name, detour, offset);

template<typename HOOK_TYPE>
class HookFunction
{
private:
    char* ID;
    LPVOID* ppOriginal;
    LPVOID pDetour;
public:
    LPVOID offset;
    bool isActive;

    HookFunction(char* ID, LPVOID pDetour, LPVOID offset) : ID(ID) pDetour(pDetour) offset(offset) {};
    ~HookFunction() {};

    HOOK_TYPE CallOriginal(...);
    HOOK_TYPE CallDetour(...);
    
    void IsEnabled(bool enabled);
};