#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcInventoryContainer
{
    static unsigned long long muNameHash = 0xAF875892F81EDE11;
    static unsigned long long muTemplateHash = 0x6B0445D97609452D;

    cTkDynamicArray<cGcInventoryElement> maSlots;
    cTkDynamicArray<cGcInventoryIndex> maValidSlotIndices;
    cGcInventoryClass Class;
    cGcInventoryStackSizeGroup StackSizeGroup;
    cTkDynamicArray<cGcInventoryBaseStatEntry> maBaseStatValues;
    cTkDynamicArray<cGcInventorySpecialSlot> maSpecialSlots;
    int miWidth;
    int miHeight;
    bool mbIsCool;
    cTkFixedString<256,char> macName;
    int miVersion;
}
