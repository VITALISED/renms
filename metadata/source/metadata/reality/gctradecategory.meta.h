#pragma once
#include <metadata/metadata_common.h>
enum eTradeCategory
{
    ETradeCategory_Mineral = 0,
    ETradeCategory_Tech = 1,
    ETradeCategory_Commodity = 2,
    ETradeCategory_Component = 3,
    ETradeCategory_Alloy = 4,
    ETradeCategory_Exotic = 5,
    ETradeCategory_Energy = 6,
    ETradeCategory_None = 7,
    ETradeCategory_SpecialShop = 8,
}

class cGcTradeCategory
{
    static unsigned long long muNameHash = 0xABEDBCE191703616;
    static unsigned long long muTemplateHash = 0xFA160E0C402E2DCA;

    eTradeCategory TradeCategory;
}
