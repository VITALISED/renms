#pragma once
#include <metadata/metadata_common.h>
enum eSentinelMechWeaponMode
{
    ESentinelMechWeaponMode_Gun = 0,
    ESentinelMechWeaponMode_Canon = 1,
    ESentinelMechWeaponMode_Flamethrower = 2,
}

class cGcSentinelMechWeaponMode
{
    static unsigned long long muNameHash = 0xF404ECE05A6AC5B7;
    static unsigned long long muTemplateHash = 0x1D77A254B2256815;

    eSentinelMechWeaponMode SentinelMechWeaponMode;
}
