#pragma once
#include <metadata/metadata_common.h>
enum eTypeOfCost
{
    ETypeOfCost_Currency = 0,
    ETypeOfCost_Substance = 1,
    ETypeOfCost_Product = 2,
}
#include <metadata/reality/gccurrency.meta.h>

class cGcUnlockableTreeCostType
{
    static unsigned long long muNameHash = 0x702F7B1A0F3F0830;
    static unsigned long long muTemplateHash = 0x35B9E521B8A19330;

    TkID<128> mCostTypeID;
    eTypeOfCost TypeOfCost;
    cGcCurrency CurrencyType;
    TkID<128> mTypeID;
    TkID<256> mCantAffordString;
}
