#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcRealitySubstanceData
{
    static unsigned long long muNameHash = 0xD811F4C9E014843E;
    static unsigned long long muTemplateHash = 0x68D2368BE2F08CB5;

    cTkFixedString<32,char> macName;
    cTkFixedString<32,char> macNameLower;
    TkID<128> mID;
    cTkFixedString<32,char> macSymbol;
    cTkTextureResource Icon;
    cTkModelResource DebrisFile;
    cTkDynamicString macSubtitle;
    cTkDynamicString macDescription;
    cTkColour mColour;
    cTkColour mWorldColour;
    int miBaseValue;
    cGcRealitySubstanceCategory Category;
    cGcRarity Rarity;
    cGcLegality Legality;
    int miChargeValue;
    int miStackMultiplier;
    cGcItemPriceModifiers Cost;
    float mfNormalisedValueOnWorld;
    float mfNormalisedValueOffWorld;
    cGcTradeCategory TradeCategory;
    bool mbWikiEnabled;
    float mfEconomyInfluenceMultiplier;
    TkID<256> mPinObjective;
    TkID<256> mPinObjectiveTip;
    TkID<128> mWikiMissionID;
    bool mbCookingIngredient;
    bool mbGoodForSelling;
    bool mbEggModifierIngredient;
}
