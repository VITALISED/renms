#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcPhotoModeAdjustData
{
    static unsigned long long muNameHash = 0x6F5F53519B901CD4;
    static unsigned long long muTemplateHash = 0x89656832E5D5FE94;

    float mfAdjustMin;
    cTkCurveType AdjustMinCurve;
    float mfAdjustMax;
    float mfAdjustMaxRange;
    cTkCurveType AdjustMaxCurve;
    bool mbInverted;
}
