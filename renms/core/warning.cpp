#include <core/warning.h>

uint64_t cTkFileSystem__IsModded__TRAMPOLINE = NULL;

bool cTkFileSystem__IsModded__DETOUR(uint64_t thiscall)
{
    return true;
}

PLH::x64Detour cTkFileSystem__IsModded__HOOK(
    reinterpret_cast<uint64_t>(renms::RelToAbsolute(0x256EC60)),
    reinterpret_cast<uint64_t>(cTkFileSystem__IsModded__DETOUR), &cTkFileSystem__IsModded__TRAMPOLINE);

uint64_t cGcApplicationGameModeSelectorState__RenderWarning__TRAMPOLINE = NULL;

void cGcApplicationGameModeSelectorState__RenderWarning__DETOUR(
    uint64_t thiscall, const char *lpacWarningTitle, const char *lpacWarningPress, const char *lStatus1, char *lStatus2,
    float lfTimeout)
{
    return PLH::FnCast(
        cGcApplicationGameModeSelectorState__RenderWarning__TRAMPOLINE,
        cGcApplicationGameModeSelectorState__RenderWarning__DETOUR)(
        thiscall, "You're running ReNMS", "I understand, Click to Continue.",
        "You may run into various crashes, if you're experiencing issues check the repository for troubleshooting "
        "tips or open an issue @ https://github.com/VITALISED/renms",
        (char *)"We're not endorsed by Hello Games so please don't send them any Zendesk Tickets, they can't help.",
        lfTimeout);
}

PLH::x64Detour cGcApplicationGameModeSelectorState__RenderWarning__HOOK(
    reinterpret_cast<uint64_t>(renms::RelToAbsolute(0x1BF7E0)),
    reinterpret_cast<uint64_t>(cGcApplicationGameModeSelectorState__RenderWarning__DETOUR),
    &cGcApplicationGameModeSelectorState__RenderWarning__TRAMPOLINE);

RENMS_BEGIN

void CreateWarningHooks()
{
    cGcApplicationGameModeSelectorState__RenderWarning__HOOK.hook();
    cTkFileSystem__IsModded__HOOK.hook();
}

RENMS_END