#pragma once
#include <metadata/metadata_common.h>
enum eDroneType
{
    EDroneType_Patrol = 0,
    EDroneType_Combat = 1,
    EDroneType_Corrupted = 2,
}

class cGcDroneTypes
{
    static unsigned long long muNameHash = 0x3FBE708907C655EF;
    static unsigned long long muTemplateHash = 0x889DD9771C5E2DD0;

    eDroneType DroneType;
}
