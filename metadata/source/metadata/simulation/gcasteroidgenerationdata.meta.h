#pragma once
#include <metadata/metadata_common.h>

class cGcAsteroidGenerationData
{
    static unsigned long long muNameHash = 0xF401654236F18FA9;
    static unsigned long long muTemplateHash = 0xA2624B0255DB35E9;

    float mfScale;
    cTkVector2 mScaleVariance;
    int miHealth;
    float mfSpacing;
    cTkVector2 mNoiseRange;
    float mfFadeRange;
    float mfNoiseScale;
}
