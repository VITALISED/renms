#pragma once
#include <metadata/metadata_common.h>
#include <metadata/voxel/generator/tknoisevoxeltypeenum.meta.h>
enum eNoiseGridType
{
    ENoiseGridType_Cube = 0,
    ENoiseGridType_Cone = 1,
    ENoiseGridType_Torus = 2,
    ENoiseGridType_Sphere = 3,
    ENoiseGridType_Cylinder = 4,
    ENoiseGridType_Capsule = 5,
    ENoiseGridType_Corridor = 6,
    ENoiseGridType_Pipe = 7,
    ENoiseGridType_Puck = 8,
    ENoiseGridType_SuperPrimitiveRandom = 9,
    ENoiseGridType_SuperFormula_01 = 10,
    ENoiseGridType_SuperFormula_02 = 11,
    ENoiseGridType_SuperFormula_03 = 12,
    ENoiseGridType_SuperFormula_04 = 13,
    ENoiseGridType_SuperFormula_05 = 14,
    ENoiseGridType_SuperFormula_06 = 15,
    ENoiseGridType_SuperFormula_07 = 16,
    ENoiseGridType_SuperFormula_08 = 17,
    ENoiseGridType_SuperFormulaRandom = 18,
    ENoiseGridType_SuperFormula = 19,
    ENoiseGridType_SuperPrimitive = 20,
    ENoiseGridType_File = 21,
}
#include <metadata/voxel/generator/tknoiseoffsetenum.meta.h>
#include <metadata/voxel/generator/tknoiseuberlayerdata.meta.h>
#include <metadata/voxel/generator/tknoisesuperformuladata.meta.h>
#include <metadata/voxel/generator/tknoisesuperprimitivedata.meta.h>

class cTkNoiseGridData
{
    static unsigned long long muNameHash = 0xA45052EB66E281C7;
    static unsigned long long muTemplateHash = 0x4C8832CFE3785F00;

    bool mbActive;
    int miMaximumLOD;
    bool mbSubtract;
    bool mbSwapZY;
    bool mbHemisphere;
    cTkNoiseVoxelTypeEnum VoxelType;
    eNoiseGridType NoiseGridType;
    cTkFixedString<128,char> macFilename;
    float mfMinWidth;
    float mfMaxWidth;
    float mfMinHeight;
    float mfMaxHeight;
    float mfMinHeightOffset;
    float mfMaxHeightOffset;
    float mfHeightOffset;
    cTkNoiseOffsetEnum Offset;
    float mfRegionRatio;
    float mfRegionScale;
    cTkNoiseUberLayerData TurbulenceNoiseLayer;
    float mfYaw;
    float mfPitch;
    float mfRoll;
    float mfVaryYaw;
    float mfVaryPitch;
    float mfVaryRoll;
    float mfSmoothRadius;
    int miSeedOffset;
    float mfRandomPrimitive;
    cTkNoiseSuperFormulaData SuperFormula1;
    cTkNoiseSuperFormulaData SuperFormula2;
    cTkNoiseSuperPrimitiveData SuperPrimitive;
    float mfTileBlendMeters;
}
