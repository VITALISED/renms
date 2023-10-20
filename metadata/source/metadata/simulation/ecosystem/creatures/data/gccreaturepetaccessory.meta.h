#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/creatures/data/gccreaturepetaccessoryslot.meta.h>

class cGcCreaturePetAccessory
{
    static unsigned long long muNameHash = 0x6C44E36452D53CB2;
    static unsigned long long muTemplateHash = 0x4FE27D0C084491F4;

    TkID<256> mRequiredDescriptor;
    cTkDynamicArray<cGcCreaturePetAccessorySlot> maSlots;
    cTkDynamicArray<TkID<256>> maHideParts;
}
