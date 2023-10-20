#pragma once
#include <metadata/metadata_common.h>

class cGcDifficultyCurrencyCostOptionData
{
    static unsigned long long muNameHash = 0x9061069311B1AB2E;
    static unsigned long long muTemplateHash = 0x66A507799BC31D19;

    cTkFixedArray<float> maMultipliers;
    cTkFixedArray<bool> maFreeCostTypes;
    float mfTradeBuyPriceMarkupMod;
    bool mbInteractionsCostsAreFree;
    bool mbCostManagerCostsAreFree;
}
