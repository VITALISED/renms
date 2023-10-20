#pragma once
#include <metadata/metadata_common.h>

class cTkFoliageData
{
    static unsigned long long muNameHash = 0x678F6A0ACE397B4;
    static unsigned long long muTemplateHash = 0xCF5018310EDBC8A2;

    cTkFixedString<128,char> macMaterial;
    float mfScale;
    float mfDensity;
    float mfDensityVariance;
    float mfAngleMultiplier;
    bool mbAngleExponentially;
    cTkColour mColour;
}
