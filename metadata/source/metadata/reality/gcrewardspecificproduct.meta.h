#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcRewardSpecificProduct
{
    static unsigned long long muNameHash = 0x691B32769ECE3BC6;
    static unsigned long long muTemplateHash = 0x54DD0DBD5DAB09E9;

    cGcDefaultMissionProductEnum Default;
    TkID<128> mID;
    int miAmountMin;
    int miAmountMax;
    bool mbHideAmountInMessage;
    bool mbForceSpecialMessage;
    bool mbHideInSeasonRewards;
    bool mbSilent;
    TkID<128> mSeasonRewardListFormat;
    TkID<128> mRequiresTech;
}
