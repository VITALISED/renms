#pragma once
#include <metadata/metadata_common.h>

class cGcId256List
{
    static unsigned long long muNameHash = 0x19E8AD6BA0D5AB9;
    static unsigned long long muTemplateHash = 0x8C39235EBFEC39E6;

    TkID<256> mId;
    cTkDynamicArray<TkID<256>> maIdList;
}
