#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gctradingclassdata.meta.h>
#include <metadata/reality/gctradingcategorydata.meta.h>

class cGcTradingClassTable
{
    static unsigned long long muNameHash = 0x8CBF7A7EE4372A7F;
    static unsigned long long muTemplateHash = 0x12960A97D242887;

    cTkFixedArray<cGcTradingClassData> maTradingClassesData;
    cTkFixedArray<cGcTradingCategoryData> maCategoryData;
    float mfMaxTradingMultiplier;
    float mfMinTradingMultiplier;
}
