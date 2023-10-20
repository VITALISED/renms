#pragma once
#include <metadata/metadata_common.h>

class cTkResourceFilterData
{
    static unsigned long long muNameHash = 0xB015A154CC664705;
    static unsigned long long muTemplateHash = 0x5E1C7F3BA587A759;

    TkID<128> mFilterName;
    cTkDynamicArray<TkID<256>> maFilteredResources;
}
