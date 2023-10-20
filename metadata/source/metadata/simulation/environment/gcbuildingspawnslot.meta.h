#pragma once
#include <metadata/metadata_common.h>

class cGcBuildingSpawnSlot
{
    static unsigned long long muNameHash = 0x9C1F12F64375236D;
    static unsigned long long muTemplateHash = 0x7B0E6131C007BCD;

    bool mbHasBuilding;
    int miBuildingDataIndex;
    float mfProbability;
}
