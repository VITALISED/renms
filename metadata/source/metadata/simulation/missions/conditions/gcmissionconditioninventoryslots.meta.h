#pragma once
#include <metadata/metadata_common.h>
enum eInventoryTest
{
    EInventoryTest_Current = 0,
    EInventoryTest_Personal = 1,
    EInventoryTest_Ship = 2,
    EInventoryTest_Vehicle = 3,
}
#include <?>

class cGcMissionConditionInventorySlots
{
    static unsigned long long muNameHash = 0xF112AB8FC14A734A;
    static unsigned long long muTemplateHash = 0xAB070DA8379B54B1;

    eInventoryTest InventoryTest;
    int miSlotsFree;
    cTkEqualityEnum Test;
    bool mbTestAllSlotsUnlocked;
    bool mbTestOnlyMainInventory;
}
