#include <plugins/fsm.h>

int gTicker = 0;

void HandleGcApplicationUpdate(nms::cGcApplication *lGcApplication)
{
    /* spdlog::info(lGcApplication->mpData->mRealityManager.mpData->macCombatEffectsTable.macBuffer);
    if (lGcApplication->mpData)
    {
        if (lGcApplication->mpData->mRealityManager.maDynamicHazardProtectionIcons.data() != NULL)
        {
            spdlog::info(
                lGcApplication->mpData->mRealityManager.maDynamicHazardProtectionIcons.back().macFilename.macBuffer);
        }
    }*/
}

RENMS_HOOK(
    cGcApplication__Update, renms::RelToAbsolute(0x19AF10), void, (nms::cGcApplication * thiscall) {
        HandleGcApplicationUpdate(GetGcApplication());
        return RENMS_CAST(cGcApplication__Update, thiscall);
    });

RENMS_BEGIN

void CreateFSMGcApplicationHooks()
{
    // TODO: would prefer this but gGcApplication seems to be null for some period extending to a little after window
    // creation. A way to time this would be an improvement.

    // void *lGcApplication          = reinterpret_cast<void *>(GCAPPLICATION);
    // void **lpaGcApplicationVTable = GetVTable(lGcApplication);
    // uint64_t lpDetour             = reinterpret_cast<uint64_t>(lpaGcApplicationVTable[2]);

    RENMS_DISPATCH_HOOK(cGcApplication__Update);
}

RENMS_END