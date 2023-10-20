#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/missions/defaultmissionitems/gcdefaultmissionproductenum.meta.h>
#include <metadata/reality/gcitemneedpurpose.meta.h>

class cGcMissionConditionHasProduct
{
    static unsigned long long muNameHash = 0x9537448E73030512;
    static unsigned long long muTemplateHash = 0xAF0D07655CC416A5;

    cGcDefaultMissionProductEnum Default;
    TkID<128> mProduct;
    int miAmount;
    bool mbSyncWithMissionFireteam;
    bool mbForceSearchFreighterAndChests;
    bool mbSearchEveryShip;
    bool mbSearchGrave;
    bool mbSearchCookingIngredients;
    bool mbTakeAmountFromSeasonData;
    bool mbDependentOnSeasonMilestone;
    TkID<128> mUseAmountToAffordRecipe;
    bool mbTakeAffordRecipeFromSeasonData;
    bool mbUseAffordRecipeForTextFormatting;
    cGcItemNeedPurpose Purpose;
}
