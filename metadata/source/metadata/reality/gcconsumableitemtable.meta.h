#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcconsumableitem.meta.h>

class cGcConsumableItemTable
{
    static unsigned long long muNameHash = 0xA9AA29AB69917BF0;
    static unsigned long long muTemplateHash = 0x1F5FF21A31CFDC7D;

    cTkDynamicArray<cGcConsumableItem> maTable;
}
