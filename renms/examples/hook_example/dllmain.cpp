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

#include <renms.h>

#define ARGUMENTS \
    DWORD_PTR thiscall, const char *lpacWarningTitle, const char *lpacWarningPress, char *lStatus1, const char *lStatus2
#define SIGNATURE DWORD_PTR, const char *, const char *, char *, const char *

RENMS_HOOK(
    cGcApplicationGameModeSelectorState__RenderWarning, void, ARGUMENTS, SIGNATURE, renms::RelToAbsolute(0x1BF7E0), {
        return cGcApplicationGameModeSelectorState__RenderWarning.CallOriginal(
            thiscall, lpacWarningTitle, lpacWarningPress, lStatus1, lStatus2);
    });

void RENMS_ENTRY PluginMain()
{

    cGcApplicationGameModeSelectorState__RenderWarning.Toggle(true);
}