#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/components/gameplay/gcinteractiontype.meta.h>

class cGcRewardSetInteractionSeenBitmask
{
    static unsigned long long muNameHash = 0x719D093BDEC85E0D;
    static unsigned long long muTemplateHash = 0xB947F0E8EA6C4333;

    cGcInteractionType InteractionType;
    int miOverrideIndex;
    TkID<128> mStat;
}
