#pragma once
#include <metadata/metadata_common.h>
enum eDebugNoiseType
{
    EDebugNoiseType_Plane = 0,
    EDebugNoiseType_Check = 1,
    EDebugNoiseType_Sine = 2,
    EDebugNoiseType_Uber = 3,
}

class cTkNoiseUberData
{
    static unsigned long long muNameHash = 0xA720068E4459862;
    static unsigned long long muTemplateHash = 0x8ABC1ABB8765470E;

    int miOctaves;
    float mfSlopeGain;
    float mfSlopeBias;
    float mfSharpToRoundFeatures;
    float mfAmplifyFeatures;
    float mfPerturbFeatures;
    float mfAltitudeErosion;
    float mfRidgeErosion;
    float mfSlopeErosion;
    float mfLacunarity;
    float mfGain;
    float mfRemapFromMin;
    float mfRemapFromMax;
    float mfRemapToMin;
    float mfRemapToMax;
    eDebugNoiseType DebugNoiseType;
}
