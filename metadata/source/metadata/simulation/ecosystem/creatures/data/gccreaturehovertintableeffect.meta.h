#pragma once
#include <metadata/metadata_common.h>

class cGcCreatureHoverTintableEffect
{
    static unsigned long long muNameHash = 0xFE54641DFEAF51F;
    static unsigned long long muTemplateHash = 0xDE224BE025A4ECB8;

    cTkFixedString<256,char> macEffectNode;
    float mfLightStrength;
    float mfTintStrength;
    cTkColour mTintColour;
}
