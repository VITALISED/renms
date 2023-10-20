#pragma once
#include <metadata/metadata_common.h>
enum eShipWeapon
{
    EShipWeapon_Laser = 0,
    EShipWeapon_Projectile = 1,
    EShipWeapon_Shotgun = 2,
    EShipWeapon_Minigun = 3,
    EShipWeapon_Plasma = 4,
    EShipWeapon_Missile = 5,
    EShipWeapon_Rocket = 6,
}

class cGcShipWeapons
{
    static unsigned long long muNameHash = 0xCBDFDF631D9C73E8;
    static unsigned long long muTemplateHash = 0x2F1DD25465633C5D;

    eShipWeapon ShipWeapon;
}
