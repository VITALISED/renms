#pragma once
#include <metadata/metadata_common.h>
enum eWeaponStatClass
{
    EWeaponStatClass_Pistol = 0,
    EWeaponStatClass_Rifle = 1,
    EWeaponStatClass_Pristine = 2,
    EWeaponStatClass_Alien = 3,
    EWeaponStatClass_Royal = 4,
}

class cGcWeaponClasses
{
    static unsigned long long muNameHash = 0xAD17D6D6D824A77D;
    static unsigned long long muTemplateHash = 0x3A51F0A05E5EB04B;

    eWeaponStatClass WeaponStatClass;
}
