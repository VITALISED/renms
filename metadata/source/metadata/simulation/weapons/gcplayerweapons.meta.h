#pragma once
#include <metadata/metadata_common.h>
enum eWeaponMode
{
    EWeaponMode_Bolt = 0,
    EWeaponMode_Shotgun = 1,
    EWeaponMode_Burst = 2,
    EWeaponMode_Rail = 3,
    EWeaponMode_Cannon = 4,
    EWeaponMode_Laser = 5,
    EWeaponMode_Grenade = 6,
    EWeaponMode_MineGrenade = 7,
    EWeaponMode_Scope = 8,
    EWeaponMode_FrontShield = 9,
    EWeaponMode_Melee = 10,
    EWeaponMode_TerrainEdit = 11,
    EWeaponMode_SunLaser = 12,
    EWeaponMode_Spawner = 13,
    EWeaponMode_SpawnerAlt = 14,
    EWeaponMode_SoulLaser = 15,
    EWeaponMode_Flamethrower = 16,
    EWeaponMode_StunGrenade = 17,
    EWeaponMode_Stealth = 18,
}

class cGcPlayerWeapons
{
    static unsigned long long muNameHash = 0x8A17532BB2410967;
    static unsigned long long muTemplateHash = 0xBE69B1FFFEBFE9FD;

    eWeaponMode WeaponMode;
}
