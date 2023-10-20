#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcRewardSpecificSubstance
{
    static unsigned long long muNameHash = 0xF3F4ABE3661F3779;
    static unsigned long long muTemplateHash = 0xE57B2F997E3F6E10;

    cGcDefaultMissionSubstanceEnum Default;
    TkID<128> mID;
    int miAmountMin;
    int miAmountMax;
    bool mbDisableMultiplier;
    bool mbRewardAsBlobs;
    bool mbUseFuelMultiplier;
    bool mbSilent;
}
