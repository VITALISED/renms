#pragma once
#include <metadata/metadata_common.h>
enum eMechWeaponLocation
{
    EMechWeaponLocation_TurretExocraft = 0,
    EMechWeaponLocation_TurretSentinel = 1,
    EMechWeaponLocation_ArmLeft = 2,
    EMechWeaponLocation_ArmRight = 3,
}

class cGcMechWeaponLocation
{
    static unsigned long long muNameHash = 0x87D2DB7CF99E11A4;
    static unsigned long long muTemplateHash = 0x36DF5247EE372E6D;

    eMechWeaponLocation MechWeaponLocation;
}
