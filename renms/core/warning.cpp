#include <core/warning.h>

//choose randomly from a list of quippy lines at startup
std::vector<std::string> startupQuips = {
    "\"Half baked and ready to roll.\" - tractorbeam",
    "\"Now with 50% more crashes!\" - tractorbeam",
    "\"Ready to serve you yet another crash log.\" - tractorbeam",
    "\"Good luck lol\" - tractorbeam",
    "\"Still not using cTkMemoryManager!\" - tractorbeam"
};

int startupQuipOfChoice = rand() % startupQuips.size();
char* startupQuip = (char*)startupQuips[startupQuipOfChoice].c_str();

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
        thiscall, "You're running ReNMS", "PRESS ANYTHING TO ACKNOWLEDGE",
        "You are very likely to run into issues, check the repo for troubleshooting tips. If you know what you're doing, submit an issue to the repo.",
        startupQuip,
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