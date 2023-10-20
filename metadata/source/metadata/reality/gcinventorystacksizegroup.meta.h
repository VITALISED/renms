#pragma once
#include <metadata/metadata_common.h>
enum eInventoryStackSizeGroup
{
    EInventoryStackSizeGroup_Default = 0,
    EInventoryStackSizeGroup_Personal = 1,
    EInventoryStackSizeGroup_PersonalCargo = 2,
    EInventoryStackSizeGroup_Ship = 3,
    EInventoryStackSizeGroup_ShipCargo = 4,
    EInventoryStackSizeGroup_Freighter = 5,
    EInventoryStackSizeGroup_FreighterCargo = 6,
    EInventoryStackSizeGroup_Vehicle = 7,
    EInventoryStackSizeGroup_Chest = 8,
    EInventoryStackSizeGroup_BaseCapsule = 9,
    EInventoryStackSizeGroup_MaintenanceObject = 10,
    EInventoryStackSizeGroup_UIPopup = 11,
}

class cGcInventoryStackSizeGroup
{
    static unsigned long long muNameHash = 0x489841A427B2161E;
    static unsigned long long muTemplateHash = 0x9C754924B696DACA;

    eInventoryStackSizeGroup InventoryStackSizeGroup;
}
