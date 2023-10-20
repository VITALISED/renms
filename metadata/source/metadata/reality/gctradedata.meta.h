#pragma once
#include <metadata/metadata_common.h>

class cGcTradeData
{
    static unsigned long long muNameHash = 0x66FAEFAF4E8E7167;
    static unsigned long long muTemplateHash = 0x6788A16C7C9B141A;

    cTkDynamicArray<TkID<128>> maAlwaysPresentProducts;
    cTkDynamicArray<TkID<128>> maAlwaysPresentSubstances;
    cTkDynamicArray<TkID<128>> maOptionalProducts;
    cTkDynamicArray<TkID<128>> maOptionalSubstances;
    int miMinItemsForSale;
    int miMaxItemsForSale;
    float mfPercentageOfItemsAreProducts;
    float mfBuyPriceIncreaseRedThreshold;
    float mfBuyPriceDecreaseGreenThreshold;
    float mfSellPriceIncreaseGreenThreshold;
    float mfSellPriceDecreaseRedThreshold;
    bool mbShowSeasonRewards;
    cTkFixedArray<int> maMinAmountOfProductAvailable;
    cTkFixedArray<int> maMaxAmountOfProductAvailable;
    cTkFixedArray<int> maMinAmountOfSubstanceAvailable;
    cTkFixedArray<int> maMaxAmountOfSubstanceAvailable;
    cTkFixedArray<int> maMinExtraSystemProducts;
    cTkFixedArray<int> maMaxExtraSystemProducts;
    cTkFixedArray<float> maTradeProductsPriceImprovements;
}
