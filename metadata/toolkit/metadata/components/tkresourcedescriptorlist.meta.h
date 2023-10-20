#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cTkResourceDescriptorList
{
    static unsigned long long muNameHash = 0x6E58FF6D49923F40;
    static unsigned long long muTemplateHash = 0x7BF6829A0ED8BCD1;

    TkID<128> mTypeId;
    cTkDynamicArray<cTkResourceDescriptorData> maDescriptors;
}
