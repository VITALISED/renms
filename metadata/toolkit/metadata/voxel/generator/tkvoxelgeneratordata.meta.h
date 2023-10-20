#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>

class cTkVoxelGeneratorData
{
    static unsigned long long muNameHash = 0x7A347325F1154095;
    static unsigned long long muTemplateHash = 0x3541FEC673F2CB77;

    cTkSeed mBaseSeed;
    float mfSeaLevel;
    float mfBeachHeight;
    float mfNoSeaBaseLevel;
    cTkNoiseVoxelTypeEnum BuildingVoxelType;
    cTkNoiseVoxelTypeEnum ResourceVoxelType;
    cTkFixedArray<cTkNoiseUberLayerData> maNoiseLayers;
    cTkFixedArray<cTkNoiseGridData> maGridLayers;
    cTkFixedArray<cTkNoiseFeatureData> maFeatures;
    cTkFixedArray<cTkNoiseCaveData> maCaves;
    float mfMinimumCaveDepth;
    float mfCaveRoofSmoothingDist;
    float mfMaximumSeaLevelCaveDepth;
    float mfBuildingTextureRadius;
    float mfBuildingSmoothingRadius;
    float mfBuildingSmoothingHeight;
    float mfWaterFadeInDistance;
}
