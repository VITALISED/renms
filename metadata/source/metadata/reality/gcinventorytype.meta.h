#pragma once
#include <metadata/metadata_common.h>
enum eInventoryType
{
    EInventoryType_Substance = 0,
    EInventoryType_Technology = 1,
    EInventoryType_Product = 2,
}

class cGcInventoryType
{
    static unsigned long long muNameHash = 0xE3C593A400EF084C;
    static unsigned long long muTemplateHash = 0x45119BD09851A673;

    eInventoryType InventoryType;
}
