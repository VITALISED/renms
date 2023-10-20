#pragma once
#include <metadata/metadata_common.h>

class cGcNPCColourGroup
{
    static unsigned long long muNameHash = 0x2E19620D3EC8F3AC;
    static unsigned long long muTemplateHash = 0x21A8E9B6B9F97971;

    float mfRarity;
    cTkColour mPrimary;
    cTkDynamicArray<cTkColour> maSecondary;
}
