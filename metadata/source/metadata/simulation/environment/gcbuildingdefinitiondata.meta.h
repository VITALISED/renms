#pragma once
#include <metadata/metadata_common.h>
#include <metadata/voxel/generator/tknoiseflattenoptions.meta.h>

class cGcBuildingDefinitionData
{
    static unsigned long long muNameHash = 0x59A43238181BB69F;
    static unsigned long long muTemplateHash = 0x4EB2192DB02EF8F2;

    cTkNoiseFlattenOptions FlattenType;
    TkID<128> mClusterLayout;
    float mfClusterSpacing;
    cTkFixedArray<float> maDensity;
    bool mbEnabledWhenPlanetHasNoNPCs;
    int miNumOverridesToGenerate;
    int miNumModelsToGenerate;
    TkID<256> mTextureNameHint;
    float mfOverrideRadius;
    bool mbGivesShelter;
    float mfMinHeight;
    float mfMaxHeight;
    bool mbIgnoreParticlesInAABB;
}
