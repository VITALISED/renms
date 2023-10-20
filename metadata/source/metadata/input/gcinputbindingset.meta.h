#pragma once
#include <metadata/metadata_common.h>
#include <metadata/input/gcactionsettype.meta.h>
#include <metadata/input/gcinputbinding.meta.h>

class cGcInputBindingSet
{
    static unsigned long long muNameHash = 0x52AAFE72AAC465AE;
    static unsigned long long muTemplateHash = 0x92F0F711498404A4;

    cGcActionSetType Type;
    cTkDynamicArray<cGcInputBinding> maInputBindings;
}
