#pragma once
#include <metadata/metadata_common.h>
enum eInventorySpecialSlotType
{
    EInventorySpecialSlotType_Broken = 0,
    EInventorySpecialSlotType_TechOnly = 1,
    EInventorySpecialSlotType_Cargo = 2,
    EInventorySpecialSlotType_BlockedByBrokenTech = 3,
    EInventorySpecialSlotType_TechBonus = 4,
}

class cGcInventorySpecialSlotType
{
    static unsigned long long muNameHash = 0xA9800C505F52A54E;
    static unsigned long long muTemplateHash = 0xB249CC7F519AAE0D;

    eInventorySpecialSlotType InventorySpecialSlotType;
}
