#pragma once
#include <metadata/metadata_common.h>
#include <metadata/input/gcinputbindingset.meta.h>

class cGcInputBindings
{
    static unsigned long long muNameHash = 0xC710DABB91F38817;
    static unsigned long long muTemplateHash = 0x19E797FB82481381;

    cTkDynamicArray<cGcInputBindingSet> maInputBindingSets;
}
