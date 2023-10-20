#pragma once
#include <metadata/metadata_common.h>
enum eAIShipWeapon
{
    EAIShipWeapon_Projectile = 0,
    EAIShipWeapon_Laser = 1,
    EAIShipWeapon_MiningLaser = 2,
}

class cGcAIShipWeapons
{
    static unsigned long long muNameHash = 0x1C73992CC7DA5C9A;
    static unsigned long long muTemplateHash = 0xF9C5E33D19947755;

    eAIShipWeapon AIShipWeapon;
}
