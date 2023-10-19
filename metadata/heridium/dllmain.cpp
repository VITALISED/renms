#include "framework.h"
#include "heridium.h"
#include "analysis.h"
#include "analysis.h"

#ifndef HERIDIUM_LANGUAGE_TARGET
#define HERIDIUM_LANGUAGE_TARGET EHeridiumLanguageType_CXX
#endif

DWORD WINAPI MainThread(LPVOID lpReserved)
{
    return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD ul_reason_for_call,
                      LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        AllocConsole();
        MH_Initialize();
        DisableThreadLibraryCalls(hModule);
        spdlog::set_level(spdlog::level::debug);
        spdlog::info("Hello from Heridium!");
        CreateThread(nullptr, 0, MainThread, hModule, 0, nullptr);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
