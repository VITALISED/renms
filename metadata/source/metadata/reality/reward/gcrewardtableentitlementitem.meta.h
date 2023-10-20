#pragma once
#include <metadata/metadata_common.h>

class cGcRewardTableEntitlementItem
{
    static unsigned long long muNameHash = 0x728CF5B9DDC60AD4;
    static unsigned long long muTemplateHash = 0x66BA958712233783;

    TkID<128> mRewardId;
    TkID<128> mEntitlementId;
    cTkClassPointer mReward;
}
