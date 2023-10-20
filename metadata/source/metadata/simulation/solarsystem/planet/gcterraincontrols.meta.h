#pragma once
#include <metadata/metadata_common.h>

class cGcTerrainControls
{
    static unsigned long long muNameHash = 0x2AD2911065D6EA2;
    static unsigned long long muTemplateHash = 0x6E82971E628F0C68;

    cTkFixedArray<float> maNoiseLayers;
    cTkFixedArray<float> maGridLayers;
    cTkFixedArray<float> maFeatures;
    cTkFixedArray<float> maCaves;
    float mfWaterActiveFrequency;
    float mfHighWaterActiveFrequency;
    float mfRockTileFrequency;
    float mfSubstanceTileFrequency;
    bool mbForceContinentalNoise;
}
