#pragma once
#include <metadata/metadata_common.h>
enum eVehicleWeaponMode
{
    EVehicleWeaponMode_Laser = 0,
    EVehicleWeaponMode_Gun = 1,
    EVehicleWeaponMode_TerrainEdit = 2,
    EVehicleWeaponMode_StunGun = 3,
}

class cGcVehicleWeaponMode
{
    static unsigned long long muNameHash = 0xE3BDE57931D2177D;
    static unsigned long long muTemplateHash = 0x673C5C3351471A1C;

    eVehicleWeaponMode VehicleWeaponMode;
}
