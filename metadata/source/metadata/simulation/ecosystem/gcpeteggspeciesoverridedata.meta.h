#pragma once
#include <metadata/metadata_common.h>

class cGcPetEggSpeciesOverrideData
{
    static unsigned long long muNameHash = 0x66A7186A5DDD202A;
    static unsigned long long muTemplateHash = 0x6B85B3F076600E6D;

    TkID<128> mCreatureID;
    bool mbCanChangeGrowth;
    bool mbCanChangeAccessories;
    bool mbCanChangeColour;
    bool mbCanChangeTraits;
    float mfMinScaleOverride;
    float mfMaxScaleOverride;
}
