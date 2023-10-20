#pragma once
#include <metadata/metadata_common.h>

class cGcFrigateTraitStrengthValues
{
    static unsigned long long muNameHash = 0xED358CC87699CBEA;
    static unsigned long long muTemplateHash = 0x71A916A9EEA62B74;

    cTkFixedArray<int> maStatAlteration;
    TkID<256> mStatLocID;
    bool mbStatDisplaysPositive;
}
