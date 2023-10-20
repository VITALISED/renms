#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcinventorytype.meta.h>

class cGcMaintenanceGroupEntry
{
    static unsigned long long muNameHash = 0x63D04F17E4BE7335;
    static unsigned long long muTemplateHash = 0xBD08DD3954719012;

    cGcInventoryType Type;
    TkID<128> mId;
    float mfProbabilityWeighting;
}
