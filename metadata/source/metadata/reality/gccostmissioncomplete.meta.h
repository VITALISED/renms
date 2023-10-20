#pragma once
#include <metadata/metadata_common.h>

class cGcCostMissionComplete
{
    static unsigned long long muNameHash = 0x2AA270B1FED04EB4;
    static unsigned long long muTemplateHash = 0xB3DA1DB34521FA9D;

    TkID<128> mCost;
    TkID<256> mTextOverride;
    bool mbHideIfCompleted;
}
