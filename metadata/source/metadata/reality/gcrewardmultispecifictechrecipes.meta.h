#pragma once
#include <metadata/metadata_common.h>

class cGcRewardMultiSpecificTechRecipes
{
    static unsigned long long muNameHash = 0x345E30DE4D2B5AAC;
    static unsigned long long muTemplateHash = 0xB2FA3A7BA33B4B6A;

    cTkDynamicArray<TkID<128>> maTechIds;
    TkID<128> mDisplayTechId;
    TkID<256> mSetName;
    bool mbSilent;
}
