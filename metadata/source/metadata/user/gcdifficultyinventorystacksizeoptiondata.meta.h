#pragma once
#include <metadata/metadata_common.h>

class cGcDifficultyInventoryStackSizeOptionData
{
    static unsigned long long muNameHash = 0xB9FD998A06AA6DE0;
    static unsigned long long muTemplateHash = 0x6B6550330B94F440;

    int miSubstanceStackLimit;
    int miProductStackLimit;
    cTkFixedArray<int> maMaxSubstanceStackSizes;
    cTkFixedArray<int> maMaxProductStackSizes;
}
