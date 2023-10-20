#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
enum eWikiCategory
{
    EWikiCategory_NotEnabled = 0,
    EWikiCategory_Crafting = 1,
    EWikiCategory_Tech = 2,
    EWikiCategory_Construction = 3,
    EWikiCategory_Trade = 4,
    EWikiCategory_Curio = 5,
    EWikiCategory_Cooking = 6,
}

class cGcProductData
{
    static unsigned long long muNameHash = 0xE831C8A241FD8276;
    static unsigned long long muTemplateHash = 0xC8BD0ABA9E49767F;

    TkID<128> mID;
    cTkFixedString<128,char> macName;
    cTkFixedString<128,char> macNameLower;
    cTkDynamicString macSubtitle;
    cTkDynamicString macDescription;
    TkID<256> mHint;
    TkID<128> mGroupID;
    cTkModelResource DebrisFile;
    int miBaseValue;
    int miLevel;
    cTkTextureResource Icon;
    cTkTextureResource HeroIcon;
    cTkColour mColour;
    cGcRealitySubstanceCategory Category;
    cGcProductCategory Type;
    cGcRarity Rarity;
    cGcLegality Legality;
    bool mbConsumable;
    int miChargeValue;
    int miStackMultiplier;
    int miDefaultCraftAmount;
    int miCraftAmountStepSize;
    int miCraftAmountMultiplier;
    cTkDynamicArray<cGcTechnologyRequirement> maRequirements;
    cTkDynamicArray<cGcTechnologyRequirement> maAltRequirements;
    cGcItemPriceModifiers Cost;
    int miRecipeCost;
    bool mbSpecificChargeOnly;
    float mfNormalisedValueOnWorld;
    float mfNormalisedValueOffWorld;
    cGcTradeCategory TradeCategory;
    eWikiCategory WikiCategory;
    bool mbIsCraftable;
    TkID<128> mDeploysInto;
    float mfEconomyInfluenceMultiplier;
    TkID<256> mPinObjective;
    TkID<256> mPinObjectiveTip;
    bool mbCookingIngredient;
    float mfCookingValue;
    bool mbGoodForSelling;
    TkID<128> mGiveRewardOnSpecialPurchase;
    bool mbEggModifierIngredient;
    bool mbIsTechbox;
    bool mbCanSendToOtherPlayers;
}
