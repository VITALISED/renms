#pragma once
#include <metadata/metadata_common.h>
enum eDamageType
{
    EDamageType_Gun = 0,
    EDamageType_Laser = 1,
    EDamageType_Shotgun = 2,
    EDamageType_Burst = 3,
    EDamageType_Rail = 4,
    EDamageType_Cannon = 5,
    EDamageType_Explosion = 6,
    EDamageType_Melee = 7,
    EDamageType_ShipGun = 8,
    EDamageType_ShipLaser = 9,
    EDamageType_ShipShotgun = 10,
    EDamageType_ShipMinigun = 11,
    EDamageType_ShipRockets = 12,
    EDamageType_ShipPlasma = 13,
    EDamageType_VehicleGun = 14,
    EDamageType_VehicleLaser = 15,
    EDamageType_SentinelLaser = 16,
    EDamageType_PlayerDamage = 17,
    EDamageType_PlayerWeapons = 18,
    EDamageType_ShipWeapons = 19,
    EDamageType_VehicleWeapons = 20,
    EDamageType_CombatEffects = 21,
    EDamageType_Fiend = 22,
}

class cGcDamageType
{
    static unsigned long long muNameHash = 0xCD0F83EA324443E1;
    static unsigned long long muTemplateHash = 0x3CC505295BDAFC43;

    eDamageType DamageType;
}
