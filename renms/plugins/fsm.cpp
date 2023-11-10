#include <plugins/fsm.h>

uint64_t cGcApplication__Update__TRAMPOLINE = NULL;

int Ticker = 0;

void cGcApplication__Update__DETOUR(uint64_t thiscall)
{
    if (Ticker = 60)
    {
        spdlog::debug("gGcApplication::Update: 60th frame");
        Ticker = 0;
    }

    Ticker += 1;

    return PLH::FnCast(cGcApplication__Update__TRAMPOLINE, cGcApplication__Update__DETOUR)(thiscall);
}

PLH::x64Detour cGcApplication__Update__HOOK(
    reinterpret_cast<uint64_t>(renms::RelToAbsolute(0x19AF10)),
    reinterpret_cast<uint64_t>(cGcApplication__Update__DETOUR), &cGcApplication__Update__TRAMPOLINE);

RENMS_BEGIN

void CreateFSMGcApplicationHooks()
{
    // TODO: would prefer this but gGcApplication seems to be null for some period extending to a little after window
    // creation. A way to time this would be an improvement.

    // void *lGcApplication          = reinterpret_cast<void *>(GCAPPLICATION);
    // void **lpaGcApplicationVTable = GetVTable(lGcApplication);
    // uint64_t lpDetour             = reinterpret_cast<uint64_t>(lpaGcApplicationVTable[2]);

    cGcApplication__Update__HOOK.hook();
}

RENMS_END