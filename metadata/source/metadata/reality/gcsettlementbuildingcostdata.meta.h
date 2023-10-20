#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gccurrency.meta.h>

class cGcSettlementBuildingCostData
{
    static unsigned long long muNameHash = 0x1746DC1EE79AD525;
    static unsigned long long muTemplateHash = 0xB4313B57BEE95EF8;

    cTkDynamicArray<TkID<128>> maProducts;
    cTkDynamicArray<TkID<128>> maSubstances;
    int miAmountMin;
    int miAmountMax;
    cGcCurrency Currency;
}
