#pragma once
#include <metadata/metadata_common.h>
enum eMultiItemRewardType
{
    EMultiItemRewardType_Product = 0,
    EMultiItemRewardType_Substance = 1,
    EMultiItemRewardType_ProcTech = 2,
    EMultiItemRewardType_ProcProduct = 3,
    EMultiItemRewardType_InventorySlot = 4,
    EMultiItemRewardType_CommunityTierProduct = 5,
}
#include <metadata/reality/gcproceduralproductcategory.meta.h>
#include <metadata/reality/gcrarity.meta.h>

class cGcMultiSpecificItemEntry
{
    static unsigned long long muNameHash = 0x7439D28A897F0ACC;
    static unsigned long long muTemplateHash = 0xE83D9C2444D3380;

    eMultiItemRewardType MultiItemRewardType;
    TkID<128> mId;
    int miAmount;
    TkID<256> mProcTechGroup;
    int miProcTechQuality;
    bool mbIllegalProcTech;
    bool mbSentinelProcTech;
    bool mbAlsoTeachTechBoxRecipe;
    cGcProceduralProductCategory ProcProdType;
    cGcRarity ProcProdRarity;
    cTkDynamicArray<TkID<128>> maCommunityTierProductList;
    bool mbHideInSeasonRewards;
    TkID<128> mSeasonRewardListFormat;
    TkID<256> mCustomRewardLocID;
}
