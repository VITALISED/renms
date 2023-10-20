#pragma once
#include <metadata/metadata_common.h>

class cGcPlanetRingData
{
    static unsigned long long muNameHash = 0x458BD6BED0D5C445;
    static unsigned long long muTemplateHash = 0x9DC3BCA8345F0164;

    bool mbHasRings;
    cTkVector3 mUp;
    cTkColour mColour1;
    cTkColour mColour2;
    float mfLargeScale1;
    float mfLargeScale2;
    float mfMidScale;
    float mfSmallScale;
    float mfMidStrength;
    float mfOffset;
    float mfDepth;
    float mfAlphaMultiplier;
}
