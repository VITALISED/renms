#pragma once
#include <metadata/metadata_common.h>
enum eInventory
{
    EInventory_Vehicle = 0,
}

class cGcTechnologyAttachmentComponentData
{
    static unsigned long long muNameHash = 0x7CCA2E6781CC7070;
    static unsigned long long muTemplateHash = 0x7168E53F55CDAD62;

    cTkDynamicArray<TkID<128>> maTechs;
    eInventory Inventory;
    bool mbInverted;
}
