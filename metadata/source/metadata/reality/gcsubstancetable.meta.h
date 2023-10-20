#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcrealitysubstancedata.meta.h>
#include <metadata/reality/gcrealitycraftingrecipedata.meta.h>

class cGcSubstanceTable
{
    static unsigned long long muNameHash = 0x390E6B7795024BAB;
    static unsigned long long muTemplateHash = 0x2FFC1ED59FABDEE1;

    cTkDynamicArray<cGcRealitySubstanceData> maTable;
    cTkDynamicArray<cGcRealityCraftingRecipeData> maCrafting;
}
