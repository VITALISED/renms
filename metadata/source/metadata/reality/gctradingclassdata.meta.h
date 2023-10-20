#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gctradecategory.meta.h>
#include <metadata/tktextureresource.meta.h>

class cGcTradingClassData
{
    static unsigned long long muNameHash = 0xB0C75D0F1E252081;
    static unsigned long long muTemplateHash = 0xFE8A924B1CD0A55E;

    cGcTradeCategory Sells;
    cGcTradeCategory Needs;
    float mfMinSellingPriceMultiplier;
    float mfMaxSellingPriceMultiplier;
    float mfMinBuyingPriceMultiplier;
    float mfMaxBuyingPriceMultiplier;
    cTkTextureResource Icon;
}
