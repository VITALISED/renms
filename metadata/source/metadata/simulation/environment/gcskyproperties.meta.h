#pragma once
#include <metadata/metadata_common.h>

class cGcSkyProperties
{
    static unsigned long long muNameHash = 0xA8207C75DBE0FE33;
    static unsigned long long muTemplateHash = 0xAA0EB553E5929CD4;

    float mfAtmosphereThickness;
    float mfHorizonMultiplier;
    float mfDuskHorizonMultiplier;
    float mfNightHorizonMultiplier;
    float mfHorizonFadeSpeed;
    float mfDayHorizonTightness;
    float mfSunSize;
    float mfSunStrength;
    float mfSunSurroundSize;
    float mfSunSurroundStrength;
    float mfUpperSkyFadeSpeed;
    float mfUpperSkyFadeOffset;
}
