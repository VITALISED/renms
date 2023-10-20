#pragma once
#include <metadata/metadata_common.h>

class cGcUnlockableSeasonReward
{
    static unsigned long long muNameHash = 0xC06F148BB67FE0E2;
    static unsigned long long muTemplateHash = 0xBAE43A4AAE4C25DF;

    TkID<128> mID;
    bool mbMustBeUnlocked;
    bool mbUniqueInventoryItem;
    bool mbIsCape;
    bool mbSwitchExclusive;
    cTkDynamicArray<int> maSeasonIds;
    cTkDynamicArray<int> maStageIds;
}
