#pragma once
#include <metadata/metadata_common.h>
enum eWonderCategoryComparisonType
{
    EWonderCategoryComparisonType_Max = 0,
    EWonderCategoryComparisonType_Min = 1,
}

class cGcWonderCategoryConfig
{
    static unsigned long long muNameHash = 0x77128F31CC435E5F;
    static unsigned long long muTemplateHash = 0x8BE6A0FD938188A4;

    eWonderCategoryComparisonType WonderCategoryComparisonType;
    float mfThresholdValue;
    TkID<256> mLocID;
    TkID<128> mStatID;
}
