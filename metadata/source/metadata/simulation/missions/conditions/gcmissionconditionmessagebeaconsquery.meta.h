#pragma once
#include <metadata/metadata_common.h>

class cGcMissionConditionMessageBeaconsQuery
{
    static unsigned long long muNameHash = 0x7A896811854A127F;
    static unsigned long long muTemplateHash = 0x2DAF7CC6F04E7A44;

    int miMinPartsFound;
    int miMaxPartsFound;
    float mfSearchDistanceLimit;
}
