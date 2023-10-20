#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/missions/defaultmissionitems/gcdefaultmissionsubstanceenum.meta.h>
#include <metadata/reality/gcitemneedpurpose.meta.h>

class cGcMissionSequenceCollectSubstance
{
    static unsigned long long muNameHash = 0x84D6228673F661A6;
    static unsigned long long muTemplateHash = 0x719B3F025CECFCC;

    cTkFixedString<128,char> macMessage;
    cGcDefaultMissionSubstanceEnum Default;
    TkID<128> mSubstance;
    int miAmountMin;
    int miAmountMax;
    bool mbWaitForSelected;
    TkID<128> mForBuild;
    TkID<128> mForRepair;
    cGcItemNeedPurpose Purpose;
    bool mbFromNow;
    bool mbTakeAmountFromSeasonData;
    bool mbSearchCookingIngredients;
    cTkFixedString<128,char> macDebugText;
}
