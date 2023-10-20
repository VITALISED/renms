#pragma once
#include <metadata/metadata_common.h>

class cGcObjectSpawnDataVariant
{
    static unsigned long long muNameHash = 0xB5D7AD8F4482D8AE;
    static unsigned long long muTemplateHash = 0x338FD10AF4E1E015;

    TkID<128> mID;
    float mfCoverage;
    float mfFlatDensity;
    float mfSlopeDensity;
    float mfSlopeMultiplier;
    int miMaxRegionRadius;
    int miMaxImposterRadius;
    float mfFadeOutStartDistance;
    float mfFadeOutEndDistance;
    float mfFadeOutOffsetDistance;
    cTkFixedArray<float> maLodDistances;
}
