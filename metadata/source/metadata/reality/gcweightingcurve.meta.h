#pragma once
#include <metadata/metadata_common.h>
enum eWeightingCurve
{
    EWeightingCurve_NoWeighting = 0,
    EWeightingCurve_MaxIsUncommon = 1,
    EWeightingCurve_MaxIsRare = 2,
    EWeightingCurve_MaxIsSuperRare = 3,
    EWeightingCurve_MinIsUncommon = 4,
    EWeightingCurve_MinIsRare = 5,
    EWeightingCurve_MinIsSuperRare = 6,
}

class cGcWeightingCurve
{
    static unsigned long long muNameHash = 0xB33B21B3131CD08D;
    static unsigned long long muTemplateHash = 0x8A2194B184BA1590;

    eWeightingCurve WeightingCurve;
}
