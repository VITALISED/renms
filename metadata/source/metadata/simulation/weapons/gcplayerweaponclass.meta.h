#pragma once
#include <metadata/metadata_common.h>
enum eWeaponClass
{
    EWeaponClass_None = 0,
    EWeaponClass_Projectile = 1,
    EWeaponClass_ChargedProjectile = 2,
    EWeaponClass_Laser = 3,
    EWeaponClass_Grenade = 4,
    EWeaponClass_Utility = 5,
    EWeaponClass_TerrainEditor = 6,
    EWeaponClass_Spawner = 7,
    EWeaponClass_SpawnerAlt = 8,
}

class cGcPlayerWeaponClass
{
    static unsigned long long muNameHash = 0x83ECCC918AB076A1;
    static unsigned long long muTemplateHash = 0x61187D71A7849AFA;

    eWeaponClass WeaponClass;
}
