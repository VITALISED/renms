#pragma once
#include <metadata/metadata_common.h>

class cGcBiomeCloudSettings
{
    static unsigned long long muNameHash = 0x7F6183B8DF97F0B3;
    static unsigned long long muTemplateHash = 0xAA8CFAD7052E64F3;

    float mfMinCover;
    float mfMaxCover;
    float mfMinVariance;
    float mfMaxVariance;
    float mfMinRateOfChange;
    float mfMaxRateOfChange;
    float mfMinRatio;
    float mfMaxRatio;
    float mfTendencyTowardsBeingCloudy;
    cTkColour mStormCloudTopColour;
    cTkColour mStormCloudBottomColour;
}
