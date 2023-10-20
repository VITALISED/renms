#pragma once
#include <metadata/metadata_common.h>

class cGcRegionHotspotData
{
    static unsigned long long muNameHash = 0x36E137A2EA118340;
    static unsigned long long muTemplateHash = 0x2990BF8415EA9388;

    float mfProbabilityWeighting;
    float mfMinRange;
    float mfMaxRange;
    cTkFixedArray<float> maClassWeightings;
    cTkFixedArray<float> maClassStrengths;
    float mfDiscoveryDistanceThreshold;
}
