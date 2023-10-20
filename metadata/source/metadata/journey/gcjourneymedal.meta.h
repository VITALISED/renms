#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcJourneyMedal
{
    static unsigned long long muNameHash = 0x33CAC73016241300;
    static unsigned long long muTemplateHash = 0x2A90662F35B374DF;

    TkID<128> mLevelledStatID;
    TkID<256> mMedalTitle;
    TkID<256> mMedalProgressText;
    TkID<256> mPinnedDescription;
    TkID<128> mPinnedMission;
    cGcStatType StatType;
    bool mbOverallJourneyDummy;
    cTkTextureResource IconNone;
    cTkTextureResource IconBronze;
    cTkTextureResource IconSilver;
    cTkTextureResource IconGold;
}
