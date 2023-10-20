#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/missions/defaultmissionitems/gcdefaultmissionproductenum.meta.h>
#include <metadata/reality/gcitemneedpurpose.meta.h>

class cGcMissionSequenceCollectProduct
{
    static unsigned long long muNameHash = 0x139E6194371FE10E;
    static unsigned long long muTemplateHash = 0x5C89FDE7FA8343D4;

    cTkFixedString<128,char> macMessage;
    cGcDefaultMissionProductEnum Default;
    TkID<128> mProduct;
    int miAmountMin;
    int miAmountMax;
    bool mbWaitForSelected;
    TkID<128> mForBuild;
    TkID<128> mForRepair;
    cGcItemNeedPurpose Purpose;
    bool mbTeachIfNotKnown;
    bool mbFromNow;
    bool mbTakeAmountFromSeasonData;
    bool mbDependentOnSeasonMilestone;
    bool mbHintAtCraftTree;
    bool mbSearchCookingIngredients;
    cTkFixedString<128,char> macDebugText;
}
