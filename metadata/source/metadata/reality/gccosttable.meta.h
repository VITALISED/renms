#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcCostTable
{
    static unsigned long long muNameHash = 0x6E62CCB542C4E505;
    static unsigned long long muTemplateHash = 0xE48BA78CFF998BDE;

    cTkDynamicArray<cGcCostTableEntry> maSimpleInteractionTable;
    cTkDynamicArray<cGcCostTableEntry> maInteractionTable;
    cTkDynamicArray<cGcCostTableEntry> maItemCostsTable;
    cTkDynamicArray<cGcCostTableEntry> maAtlasPathCosts;
    cTkDynamicArray<cGcCostTableEntry> maUnusedCostsTable;
}
