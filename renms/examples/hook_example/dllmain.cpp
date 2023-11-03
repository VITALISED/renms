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

#define SIGNATURE                                                                                         \
    DWORD_PTR thiscall, const char *lpacWarningTitle, const char *lpacWarningPress, const char *lStatus1, \
        char *lStatus2, float lfTimeout

typedef void (*__cGcApplicationGameModeSelectorState__RenderWarning__SIGNATURE)(SIGNATURE);

void __cGcApplicationGameModeSelectorState__RenderWarning__(SIGNATURE)
{
    std::printf(lpacWarningTitle, "\n");
    std::printf(lpacWarningPress, "\n");
    std::printf(lStatus1, "\n");
    std::printf(lStatus2, "\n");
}

void RENMS_API PluginMain()
{
    std::printf("hello!!!", "\n");

    HOOK(
        cGcApplicationGameModeSelectorState__RenderWarning,
        __cGcApplicationGameModeSelectorState__RenderWarning__SIGNATURE,
        static_cast<LPVOID>(__cGcApplicationGameModeSelectorState__RenderWarning__), renms::RelToAbsolute(0x1BF7E0));
}

// you shouldn't need to use this, in fact it's preferred not to
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    UNREFERENCED_PARAMETER(hModule);
    UNREFERENCED_PARAMETER(ul_reason_for_call);
    UNREFERENCED_PARAMETER(lpReserved);

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH: break;
    }
    return TRUE;
}