#pragma once
#include <metadata/metadata_common.h>

class cGcInventoryBaseStatEntry
{
    static unsigned long long muNameHash = 0x706BDD46AD2006F7;
    static unsigned long long muTemplateHash = 0x2056FB8796563F48;

    TkID<128> mBaseStatID;
    float mfValue;
}
