#pragma once
#include <metadata/metadata_common.h>
enum eInventoryToRepair
{
    EInventoryToRepair_Personal = 0,
    EInventoryToRepair_PersonalTech = 1,
    EInventoryToRepair_Ship = 2,
    EInventoryToRepair_ShipTech = 3,
    EInventoryToRepair_Freighter = 4,
    EInventoryToRepair_Vehicle = 5,
    EInventoryToRepair_AttachedAbandonedShip = 6,
    EInventoryToRepair_Weapon = 7,
}

class cGcRewardRepairWholeInventory
{
    static unsigned long long muNameHash = 0xB0C58666F58DF1C;
    static unsigned long long muTemplateHash = 0x8B12A7765BF54C2D;

    eInventoryToRepair InventoryToRepair;
}
