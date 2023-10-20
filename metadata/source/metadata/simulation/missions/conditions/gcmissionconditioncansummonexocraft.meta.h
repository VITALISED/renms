#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/vehicles/gcvehicletype.meta.h>

class cGcMissionConditionCanSummonExocraft
{
    static unsigned long long muNameHash = 0x9E6CDA34B604CC21;
    static unsigned long long muTemplateHash = 0x9424DB0B12B4353;

    bool mbSpecificExocraft;
    cGcVehicleType SummonableExocraft;
}
