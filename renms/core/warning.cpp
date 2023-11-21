#include <core/warning.h>

RENMS_HOOK(
    cTkFileSystem__IsModded, renms::RelToAbsolute(0x256EC60), bool, (uint64_t thiscall) {
        if (renms::config::gShouldShowWarning) return true;

        return false;
    });

RENMS_HOOK(
    cGcApplicationGameModeSelectorState__RenderWarning, renms::RelToAbsolute(0x1BF7E0), void,
    (uint64_t thiscall, const char *lpacWarningTitle, const char *lpacWarningPress, const char *lStatus1,
     char *lStatus2, float lfTimeout) {
        return RENMS_CAST(
            cGcApplicationGameModeSelectorState__RenderWarning, thiscall, "You're running ReNMS",
            "PRESS ANYTHING TO ACKNOWLEDGE",
            "ReNMS is extremely unstable. If you encounter issues check the repository for tips or to open an "
            "issue. "
            "(https://github.com/VITALISED/renms)",
            const_cast<char *>("We're not endorsed by Hello Games. Please don't send them any Zendesk Tickets."),
            lfTimeout);
    });

RENMS_BEGIN

void CreateWarningHooks()
{
    RENMS_DISPATCH_HOOK(cGcApplicationGameModeSelectorState__RenderWarning);
    RENMS_DISPATCH_HOOK(cTkFileSystem__IsModded);
}

RENMS_END