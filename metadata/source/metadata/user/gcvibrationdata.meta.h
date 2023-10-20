#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcVibrationData
{
    static unsigned long long muNameHash = 0x1C317C9CAD203EF4;
    static unsigned long long muTemplateHash = 0xA8D7D8F0ECE4DB7B;

    float mfOutputStrength;
    cTkCurveType OutputStrengthCurve;
    float mfDecayTime;
    float mfVariance;
    float mfVarianceContrast;
    float mfSmoothTime;
}
