#pragma once
#include <metadata/metadata_common.h>

class cGcRewardSecondarySubstance
{
    static unsigned long long muNameHash = 0x793796BDCC72805;
    static unsigned long long muTemplateHash = 0x96F79E9194CC6B99;

    TkID<128> mID;
    float mfAmountFactor;
    bool mbRewardAsBlobs;
}
