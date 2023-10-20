#pragma once
#include <metadata/metadata_common.h>

class cGcRewardSpecificProductRecipe
{
    static unsigned long long muNameHash = 0xD0AAAD197E826825;
    static unsigned long long muTemplateHash = 0xC5BD654EE5F4D31B;

    TkID<128> mID;
    bool mbSilent;
    bool mbHideInSeasonRewards;
    TkID<256> mSeasonRewardFormat;
}
