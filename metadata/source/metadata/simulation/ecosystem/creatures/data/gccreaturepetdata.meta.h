#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/creatures/data/gccreaturepetaccessory.meta.h>

class cGcCreaturePetData
{
    static unsigned long long muNameHash = 0x60B2A2CE8774967D;
    static unsigned long long muTemplateHash = 0xD6DEF3B6B7B5062B;

    cTkDynamicArray<cGcCreaturePetAccessory> maAccessorySlots;
}
