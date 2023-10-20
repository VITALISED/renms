#pragma once
#include <metadata/metadata_common.h>

class cGcUnlockableTwitchReward
{
    static unsigned long long muNameHash = 0xE9EC3242091011CC;
    static unsigned long long muTemplateHash = 0xE7150D917844F3DF;

    TkID<128> mTwitchId;
    TkID<128> mProductId;
    TkID<128> mLinkedGroupId;
}
