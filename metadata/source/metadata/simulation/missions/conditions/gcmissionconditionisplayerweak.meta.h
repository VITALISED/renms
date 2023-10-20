#pragma once
#include <metadata/metadata_common.h>
enum eProgressType
{
    EProgressType_ShipOrWeapon = 0,
    EProgressType_Ship = 1,
    EProgressType_Weapon = 2,
}

class cGcMissionConditionIsPlayerWeak
{
    static unsigned long long muNameHash = 0x1B69E5D9C1463621;
    static unsigned long long muTemplateHash = 0x67C14B3B9661443F;

    eProgressType ProgressType;
}
