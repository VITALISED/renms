#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcRewardDisguisedProduct
{
    static unsigned long long muNameHash = 0xDBFECF3462D8A0FB;
    static unsigned long long muTemplateHash = 0x3069E357752DF95D;

    cGcDefaultMissionProductEnum Default;
    TkID<128> mID;
    TkID<128> mDisplayAs;
    TkID<128> mAwardDisplayIDDuringMission;
    int miAmountMin;
    int miAmountMax;
}
