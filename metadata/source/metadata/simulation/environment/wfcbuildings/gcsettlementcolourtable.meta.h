#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcSettlementColourTable
{
    static unsigned long long muNameHash = 0x4EF075AF93525886;
    static unsigned long long muTemplateHash = 0xD707EED30A524683;

    cTkDynamicArray<cGcSettlementColourPalette> maSettlementColourPalettes;
    cTkDynamicArray<TkID<128>> maDecorationPartIds;
}
