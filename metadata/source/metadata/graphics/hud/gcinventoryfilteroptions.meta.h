#pragma once
#include <metadata/metadata_common.h>
enum eInventoryFilter
{
    EInventoryFilter_All = 0,
    EInventoryFilter_Substance = 1,
    EInventoryFilter_HighValue = 2,
    EInventoryFilter_Consumable = 3,
    EInventoryFilter_Deployable = 4,
}

class cGcInventoryFilterOptions
{
    static unsigned long long muNameHash = 0x150B7D498E249B47;
    static unsigned long long muTemplateHash = 0x49AD1545EF62E0F9;

    eInventoryFilter InventoryFilter;
}
