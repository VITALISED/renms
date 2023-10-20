#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/vehicles/gcvehicletype.meta.h>

class cGcMissionConditionPrimaryExocraft
{
    static unsigned long long muNameHash = 0x8037450FD0FA54E6;
    static unsigned long long muTemplateHash = 0xC4E8D92A6E3D6301;

    cGcVehicleType ExocraftType;
    bool mbMustBeSummonedNearby;
}
