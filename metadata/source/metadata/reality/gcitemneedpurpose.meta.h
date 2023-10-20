#pragma once
#include <metadata/metadata_common.h>
enum eItemPurpose
{
    EItemPurpose_None = 0,
    EItemPurpose_Crafting = 1,
    EItemPurpose_Building = 2,
    EItemPurpose_Repairing = 3,
    EItemPurpose_Charging = 4,
    EItemPurpose_Paying = 5,
}

class cGcItemNeedPurpose
{
    static unsigned long long muNameHash = 0xE637310E185BAB51;
    static unsigned long long muTemplateHash = 0xD494B90ACEB9A99C;

    eItemPurpose ItemPurpose;
}
