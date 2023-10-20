#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcrewardmissionoverride.meta.h>

class cGcStoryUtilityOverride
{
    static unsigned long long muNameHash = 0xE1C7E19E0F5C0C48;
    static unsigned long long muTemplateHash = 0x51F076B588C99C1D;

    TkID<256> mName;
    TkID<128> mReward;
    cTkDynamicArray<cGcRewardMissionOverride> maSpecificRewardOverrideTable;
}
