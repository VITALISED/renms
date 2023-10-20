#pragma once
#include <metadata/metadata_common.h>

class cGcLightShaftProperties
{
    static unsigned long long muNameHash = 0x95E6C4BF9139916C;
    static unsigned long long muTemplateHash = 0xF80054E2AA7C77FE;

    float mfLightShaftScattering;
    float mfLightShaftStrength;
    float mfLightShaftBottom;
    float mfLightShaftTop;
    cTkColour mLightShaftColourBottom;
    cTkColour mLightShaftColourTop;
}
