#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cTkLSystemLocatorEntry
{
    static unsigned long long muNameHash = 0x5FB32B8921A7FE69;
    static unsigned long long muTemplateHash = 0x800D4593B5370A32;

    cTkFixedString<128,char> macModel;
    float mfProbability;
    cTkDynamicArray<cTkLSystemRestrictionData> maRestrictions;
}
