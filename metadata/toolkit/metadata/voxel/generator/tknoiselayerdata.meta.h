#pragma once
#include <metadata/metadata_common.h>
enum eNoiseType
{
    ENoiseType_Plane = 0,
    ENoiseType_Check = 1,
    ENoiseType_Sine = 2,
    ENoiseType_Smooth = 3,
    ENoiseType_Fractal = 4,
    ENoiseType_Ridged = 5,
    ENoiseType_Billow = 6,
    ENoiseType_Erosion = 7,
    ENoiseType_Volcanic = 8,
    ENoiseType_Glacial = 9,
    ENoiseType_Plateau = 10,
}

class cTkNoiseLayerData
{
    static unsigned long long muNameHash = 0x474596B01166F6A6;
    static unsigned long long muTemplateHash = 0xC6E7F5301C2A5B2A;

    bool mbActive;
    bool mbInvert;
    bool mbAbsolute;
    bool mbSubtract;
    eNoiseType NoiseType;
    float mfHeight;
    float mfWidth;
    int miOctaves;
    float mfFrequencyScaleY;
    float mfRegionRatio;
    float mfRegionScale;
    float mfTurbulenceFrequency;
    float mfTurbulenceAmplitude;
    int miTurbulenceOctaves;
    int miSeedOffset;
}
