#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tktextureresource.meta.h>
#include <metadata/reality/gcrealitysubstancecategory.meta.h>
#include <metadata/reality/gctechnologycategory.meta.h>
#include <metadata/reality/gctechnologyrarity.meta.h>
#include <metadata/reality/gctechnologyrequirement.meta.h>
#include <metadata/reality/stats/gcstatstypes.meta.h>
#include <metadata/reality/stats/gcstatsbonus.meta.h>
#include <metadata/reality/gcitempricemodifiers.meta.h>
#include <metadata/reality/gcalienrace.meta.h>

class cGcTechnology
{
    static unsigned long long muNameHash = 0x9F1CE8466638E767;
    static unsigned long long muTemplateHash = 0x7DCC8C19A5C03C43;

    TkID<128> mID;
    TkID<256> mGroup;
    cTkFixedString<128,char> macName;
    cTkFixedString<128,char> macNameLower;
    cTkDynamicString macSubtitle;
    cTkDynamicString macDescription;
    bool mbTeach;
    TkID<256> mHintStart;
    TkID<256> mHintEnd;
    cTkTextureResource Icon;
    cTkColour mColour;
    int miLevel;
    bool mbChargeable;
    int miChargeAmount;
    cGcRealitySubstanceCategory ChargeType;
    cTkDynamicArray<TkID<128>> maChargeBy;
    float mfChargeMultiplier;
    bool mbBuildFullyCharged;
    bool mbUsesAmmo;
    TkID<128> mAmmoId;
    bool mbPrimaryItem;
    bool mbUpgrade;
    bool mbCore;
    bool mbRepairTech;
    bool mbProcedural;
    cGcTechnologyCategory Category;
    cGcTechnologyRarity Rarity;
    float mfValue;
    cTkDynamicArray<cGcTechnologyRequirement> maRequirements;
    cGcStatsTypes BaseStat;
    cTkDynamicArray<cGcStatsBonus> maStatBonuses;
    TkID<128> mRequiredTech;
    int miRequiredLevel;
    TkID<256> mFocusLocator;
    cTkColour mUpgradeColour;
    cTkColour mLinkColour;
    TkID<128> mRewardGroup;
    int miBaseValue;
    cGcItemPriceModifiers Cost;
    int miRequiredRank;
    cGcAlienRace DispensingRace;
    int miFragmentCost;
    cGcTechnologyRarity TechShopRarity;
    bool mbWikiEnabled;
    cTkDynamicString macDamagedDescription;
    TkID<128> mParentTechId;
    bool mbIsTemplate;
}
