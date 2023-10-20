#pragma once
#include <metadata/metadata_common.h>

class cGcLootComponentData
{
    static unsigned long long muNameHash = 0x1E85F3A419864E16;
    static unsigned long long muTemplateHash = 0x7173DCD61496ED;

    cTkVector2 mTimed;
    TkID<128> mTimeOutEffect;
    bool mbDeathPoint;
    float mfFlashPercent;
    int miNumFlashes;
    bool mbPhysicsControlled;
    bool mbKeepUpright;
    TkID<128> mReward;
}
