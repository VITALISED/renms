#include <core/warning.h>

uint64_t cTkFileSystem__IsModded__TRAMPOLINE = NULL;

bool cTkFileSystem__IsModded__DETOUR(uint64_t thiscall)
{
    if (renms::config::bShowWarning) return true;

    return false;
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
        thiscall, "You're running ReNMS", "PRESS ANYTHING TO ACKNOWLEDGE",
        "ReNMS is extremely unstable. If you encounter issues check the repository for tips or to open an issue. "
        "(https://github.com/VITALISED/renms)",
        const_cast<char *>("We're not endorsed by Hello Games. Please don't send them any Zendesk Tickets."),
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