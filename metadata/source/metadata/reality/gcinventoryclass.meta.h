#pragma once
#include <metadata/metadata_common.h>
enum eInventoryClass
{
    EInventoryClass_C = 0,
    EInventoryClass_B = 1,
    EInventoryClass_A = 2,
    EInventoryClass_S = 3,
}

class cGcInventoryClass
{
    static unsigned long long muNameHash = 0x5C2C30D664D4775B;
    static unsigned long long muTemplateHash = 0xC92DACAD69EBE5B6;

    eInventoryClass InventoryClass;
}
