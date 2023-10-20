#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcinventorylayoutgenerationbounds.meta.h>
#include <metadata/gamestate/gcinventoryindex.meta.h>

class cGcInventoryLayoutGenerationDataEntry
{
    static unsigned long long muNameHash = 0x15DCF5F4B3591EDB;
    static unsigned long long muTemplateHash = 0xF4143974B3CF4098;

    int miMinSlots;
    int miMaxSlots;
    int miMinTechSlots;
    int miMaxTechSlots;
    int miMinCargoSlots;
    int miMaxCargoSlots;
    cGcInventoryLayoutGenerationBounds Bounds;
    cGcInventoryLayoutGenerationBounds TechBounds;
    int miMaxNumSpecialTechSlots;
    cGcInventoryIndex SpecialTechSlotMaxIndex;
}
