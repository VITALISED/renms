#pragma once
#include <metadata/metadata_common.h>
enum eInventoryToInstallIn
{
    EInventoryToInstallIn_Personal = 0,
    EInventoryToInstallIn_PersonalTech = 1,
    EInventoryToInstallIn_Ship = 2,
    EInventoryToInstallIn_ShipTech = 3,
    EInventoryToInstallIn_Freighter = 4,
    EInventoryToInstallIn_Vehicle = 5,
    EInventoryToInstallIn_Weapon = 6,
}

class cGcRewardInstallTech
{
    static unsigned long long muNameHash = 0x75DF796697F3DB0A;
    static unsigned long long muTemplateHash = 0x21F8F59124D39327;

    TkID<128> mTechId;
    eInventoryToInstallIn InventoryToInstallIn;
    bool mbSilent;
    bool mbInstallBroken;
}
