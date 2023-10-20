#pragma once
#include <metadata/metadata_common.h>

class cGcStatGroupData
{
    static unsigned long long muNameHash = 0xDB9BCAEA43E96FA6;
    static unsigned long long muTemplateHash = 0x781BDBA6D5335B6A;

    TkID<128> mGroupName;
    cTkDynamicArray<TkID<128>> maTrackedStats;
}
