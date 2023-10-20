#pragma once
#include <metadata/metadata_common.h>
#include <metadata/voxel/generator/tknoisevoxeltypeenum.meta.h>
enum eFeatureType
{
    EFeatureType_Tube = 0,
    EFeatureType_Blob = 1,
}
#include <metadata/voxel/generator/tknoiseoffsetenum.meta.h>

class cTkNoiseFeatureData
{
    static unsigned long long muNameHash = 0xBC975A8E0D580FFA;
    static unsigned long long muTemplateHash = 0x11FD8C247496B7E8;

    bool mbActive;
    int miMaximumLOD;
    bool mbSubtract;
    bool mbTrench;
    cTkNoiseVoxelTypeEnum VoxelType;
    eFeatureType FeatureType;
    float mfWidth;
    float mfHeight;
    int miOctaves;
    float mfRegionSize;
    float mfRatio;
    float mfHeightVarianceAmplitude;
    float mfHeightVarianceFrequency;
    float mfHeightOffset;
    cTkNoiseOffsetEnum Offset;
    float mfSmoothRadius;
    int miSeedOffset;
    float mfTileBlendMeters;
}
