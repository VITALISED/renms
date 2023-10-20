#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>

class cGcBuildingSpawnData
{
    static unsigned long long muNameHash = 0x2FE28DE7841506AF;
    static unsigned long long muTemplateHash = 0xFFDC604437C8CD16;

    float mfDensity;
    cGcResourceElement Resource;
    int miLSystemID;
    int miWFCModuleSet;
    int miWFCBuildingPreset;
    bool mbAutoCollision;
    cTkSeed mSeed;
    cGcBuildingClassification Classification;
    cTkFixedArray<int> maClusterLayouts;
    int miClusterLayoutCount;
    float mfClusterSpacing;
    cTkNoiseFlattenOptions FlattenType;
    bool mbGivesShelter;
    bool mbAlignToNormal;
    bool mbLowerIntoGround;
    float mfScale;
    float mfMaxXZRotation;
    float mfRadius;
    float mfMinHeight;
    float mfMaxHeight;
    int miInstanceID;
    cTkVector3 mAABBMin;
    cTkVector3 mAABBMax;
    bool mbBuildingSizeCalculated;
    bool mbIgnoreParticlesAABB;
}
