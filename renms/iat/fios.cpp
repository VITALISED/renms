#include <iat/fios.h>

//----------------------------sceFiosFHGetSize

uint64_t sceFiosFHGetSize__TRAMPOLINE = NULL;

SceFiosSize WINAPI sceFiosFHGetSize__DETOUR(SceFiosHandle lFH)
{
    return PLH::FnCast(sceFiosFHGetSize__TRAMPOLINE, sceFiosFHGetSize__DETOUR)(lFH);
}

PLH::IatHook sceFiosFHGetSize__HOOK(
    "libSceFios2.dll", "sceFiosFHGetSize", reinterpret_cast<uint64_t>(sceFiosFHGetSize__DETOUR),
    &sceFiosFHGetSize__TRAMPOLINE, L"NMS.exe");

//----------------------------sceFiosIOFilterAdd

uint64_t sceFiosIOFilterAdd__TRAMPOLINE = NULL;

uint64_t WINAPI sceFiosIOFilterAdd__DETOUR(int unk1, uintptr_t lpIOFilter, SceFiosFilterContext *lpRamCacheContext)
{
    return PLH::FnCast(sceFiosIOFilterAdd__TRAMPOLINE, sceFiosIOFilterAdd__DETOUR)(unk1, lpIOFilter, lpRamCacheContext);
}

PLH::IatHook sceFiosIOFilterAdd__HOOK(
    "libSceFios2.dll", "sceFiosIOFilterAdd", reinterpret_cast<uint64_t>(sceFiosIOFilterAdd__DETOUR),
    &sceFiosIOFilterAdd__TRAMPOLINE, L"NMS.exe");

//----------------------------sceFiosInitialize

uint64_t sceFiosInitialize__TRAMPOLINE = NULL;

void WINAPI sceFiosInitialize__DETOUR(SceFiosParams lParams)
{
    spdlog::info("sceFiosInitialize");
    return PLH::FnCast(sceFiosInitialize__TRAMPOLINE, sceFiosInitialize__DETOUR)(lParams);
}

PLH::IatHook sceFiosInitialize__HOOK(
    "libSceFios2.dll", "sceFiosInitialize", reinterpret_cast<uint64_t>(sceFiosInitialize__DETOUR),
    &sceFiosInitialize__TRAMPOLINE, L"NMS.exe");

//----------------------------sceFiosIsValidHandle

uint64_t sceFiosIsValidHandle__TRAMPOLINE = NULL;

bool WINAPI sceFiosIsValidHandle__DETOUR(SceFiosHandle lFH)
{
    return PLH::FnCast(sceFiosIsValidHandle__TRAMPOLINE, sceFiosIsValidHandle__DETOUR)(lFH);
}

PLH::IatHook sceFiosIsValidHandle__HOOK(
    "libSceFios2.dll", "sceFiosIsValidHandle", reinterpret_cast<uint64_t>(sceFiosIsValidHandle__DETOUR),
    &sceFiosIsValidHandle__TRAMPOLINE, L"NMS.exe");

//----------------------------

uint64_t sceFiosFileGetSizeSync__TRAMPOLINE = NULL;

SceFiosSize WINAPI sceFiosFileGetSizeSync__DETOUR(SceFiosOpAttr lAttr, const char *lpacFilename)
{
    return PLH::FnCast(sceFiosFileGetSizeSync__TRAMPOLINE, sceFiosFileGetSizeSync__DETOUR)(lAttr, lpacFilename);
}

PLH::IatHook sceFiosFileGetSizeSync__HOOK(
    "libSceFios2.dll", "sceFiosFileGetSizeSync", reinterpret_cast<uint64_t>(sceFiosFileGetSizeSync__DETOUR),
    &sceFiosFileGetSizeSync__TRAMPOLINE, L"NMS.exe");

//----------------------------

RENMS_BEGIN

void CreateFiosHooks()
{
    sceFiosFHGetSize__HOOK.hook();
    sceFiosIOFilterAdd__HOOK.hook();
    sceFiosInitialize__HOOK.hook();
    sceFiosIsValidHandle__HOOK.hook();
    sceFiosFileGetSizeSync__HOOK.hook();
}

RENMS_END