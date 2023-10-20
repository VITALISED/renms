#pragma once
#include <metadata/metadata_common.h>
enum eMaintenanceGroup
{
    EMaintenanceGroup_Custom = 0,
    EMaintenanceGroup_Farming = 1,
    EMaintenanceGroup_Fuelling = 2,
    EMaintenanceGroup_Repairing = 3,
    EMaintenanceGroup_EasyRepairing = 4,
    EMaintenanceGroup_Cleaning = 5,
    EMaintenanceGroup_Frigate = 6,
}

class cGcMaintenanceElementGroups
{
    static unsigned long long muNameHash = 0x38F9072E9DC5078A;
    static unsigned long long muTemplateHash = 0x56884BB3E519A5CC;

    eMaintenanceGroup MaintenanceGroup;
}
