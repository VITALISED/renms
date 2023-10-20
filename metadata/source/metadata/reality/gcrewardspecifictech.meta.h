#pragma once
#include <metadata/metadata_common.h>

class cGcRewardSpecificTech
{
    static unsigned long long muNameHash = 0xDABE4D9A95799081;
    static unsigned long long muTemplateHash = 0xEF6C5F7CE276AFA;

    TkID<128> mTechId;
    bool mbAutoPin;
    bool mbSilent;
    bool mbHideInSeasonRewards;
}
