#pragma once
#include <metadata/metadata_common.h>

class cGcRewardWeaponSlot
{
    static unsigned long long muNameHash = 0xC64F181FDA941A39;
    static unsigned long long muTemplateHash = 0xA3D1765B5B3C789A;

    TkID<128> mCost;
    bool mbAwardCostAndOpenWindow;
    int miNumTokens;
}
