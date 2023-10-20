#pragma once
#include <metadata/metadata_common.h>

class cGcRewardMissionOverride
{
    static unsigned long long muNameHash = 0xCFC064FBFD501A40;
    static unsigned long long muTemplateHash = 0x7BF0D6F492F4796F;

    TkID<128> mMission;
    TkID<128> mReward;
}
