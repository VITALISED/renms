#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcInventoryTableEntry
{
    static unsigned long long muNameHash = 0xBA68F4D576FCF49E;
    static unsigned long long muTemplateHash = 0x65D93A0D6A50384A;

    TkID<128> mId;
    int miMinSize;
    int miMaxSize;
    cGcInventoryLayoutSizeType LayoutSizeType;
}
