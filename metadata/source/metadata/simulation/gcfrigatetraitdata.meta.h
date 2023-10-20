#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcFrigateTraitData
{
    static unsigned long long muNameHash = 0x3A526CC4024569BA;
    static unsigned long long muTemplateHash = 0xDBF0C9D3E8C11AFF;

    TkID<128> mID;
    TkID<256> mDisplayName;
    cGcFrigateStatType FrigateStatType;
    cGcFrigateTraitStrength Strength;
    cTkFixedArray<int> maChanceOfBeingOffered;
}
