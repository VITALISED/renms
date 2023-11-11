#include <core/warning.h>

//choose randomly from a list of quippy lines at startup
std::vector<std::string> startupQuips = {
    "\"Half baked and ready to roll.\" - tractorbeam",
    "\"Now with 50% more crashes!\" - tractorbeam",
    "\"Ready to serve you yet another crash log.\" - tractorbeam",
    "\"Good luck lol\" - tractorbeam",
    "\"Still not hooking cTkMemoryManager!\" - tractorbeam",
    "\"Also try Starfield!\" - tractorbeam",
    "\"What do you mean 'it works on my machine?'\" - tractorbeam",
    "\"You guys have been hooking?\" - tractorbeam",
    "\"I read something about a hooker in the logs.\" - tractorbeam",
    "\"I'd like two number nines, a number nine large, a number six with extra dip, a number seven, two number forty-fives, one with cheese, and a large soda.\" - tractorbeam, supposedly"
};

char* randomQuip()
{
    srand(time(NULL));
    int startupQuipOfChoice = 0;
    startupQuipOfChoice = rand() % startupQuips.size();
    return (char*)startupQuips[startupQuipOfChoice].c_str();
}

auto startupQuip = randomQuip();

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