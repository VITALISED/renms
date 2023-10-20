#pragma once
#include <metadata/metadata_common.h>
#include <metadata/voxel/generator/tknoiseuberdata.meta.h>
#include <metadata/voxel/generator/tknoisevoxeltypeenum.meta.h>
#include <metadata/voxel/generator/tknoiseoffsetenum.meta.h>
enum eWaterFade
{
    EWaterFade_None = 0,
    EWaterFade_Above = 1,
    EWaterFade_Below = 2,
}

class cTkNoiseUberLayerData
{
    static unsigned long long muNameHash = 0x174C8C3DB33CE268;
    static unsigned long long muTemplateHash = 0x3F104057D08F304F;

    cTkNoiseUberData NoiseData;
    bool mbActive;
    int miMaximumLOD;
    bool mbSubtract;
    cTkNoiseVoxelTypeEnum VoxelType;
    float mfHeight;
    float mfWidth;
    float mfRegionRatio;
    float mfRegionScale;
    float mfRegionGain;
    float mfSmoothRadius;
    float mfHeightOffset;
    cTkNoiseOffsetEnum Offset;
    eWaterFade WaterFade;
    float mfPlateauStratas;
    int miPlateauSharpness;
    float mfPlateauRegionSize;
    int miSeedOffset;
    float mfTileBlendMeters;
}
