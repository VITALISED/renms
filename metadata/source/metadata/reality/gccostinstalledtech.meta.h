#pragma once
#include <metadata/metadata_common.h>
enum eInventoryToCheck
{
    EInventoryToCheck_All = 0,
    EInventoryToCheck_Suit = 1,
    EInventoryToCheck_Ship = 2,
    EInventoryToCheck_Weapon = 3,
    EInventoryToCheck_Freighter = 4,
    EInventoryToCheck_Buggy = 5,
}

class cGcCostInstalledTech
{
    static unsigned long long muNameHash = 0xF6CA47F9F51F553F;
    static unsigned long long muTemplateHash = 0xA1DCDC3F66BF2F2D;

    TkID<128> mId;
    eInventoryToCheck InventoryToCheck;
}
