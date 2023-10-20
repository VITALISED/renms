#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/vehicles/gcvehicletype.meta.h>

class cGcMissionConditionHasExocraft
{
    static unsigned long long muNameHash = 0xF738BB4CB0090E06;
    static unsigned long long muTemplateHash = 0x8450C72D9D635E78;

    bool mbSpecificExocraft;
    cGcVehicleType ExocraftType;
}
