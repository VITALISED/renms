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

#include "renms.h"
#include <commands/builtin.h>
#include <commands/dispatcher.h>
#include <core/filesystem.h>
#include <core/warning.h>
#include <iat/fios.h>
#include <memory/thread.h>
#include <plugins/fsm.h>
#include <plugins/plugin.h>
#include <core/config.h>

DWORD WINAPI MainThread(LPVOID lpReserved)
{
    UNREFERENCED_PARAMETER(lpReserved);

    CreateLogger("\033[31mReNMS\033[0m");
    spdlog::info("ReNMS v.{} -- Initializing things...", RENMS_VERSION);

    renms::config::init();
    renms::AddBuiltinCommands();
    renms::CreateTextChatHooks();
    renms::CreateFiosHooks();
    renms::CreateTargetDirectories();
    renms::CreateWarningHooks();
    renms::CreateFSMGcApplicationHooks();

    renms::PluginManager lPluginManager = renms::PluginManager();

    renms::ResumeModuleThread(renms::GetNMSModuleHandle());
    spdlog::info("NMS is running.");

    return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    UNREFERENCED_PARAMETER(lpReserved);

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        AllocConsole();
        CreateThread(NULL, NULL, MainThread, hModule, NULL, NULL);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH: break;
    }
    return TRUE;
}
