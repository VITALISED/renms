#pragma once
#include <metadata/metadata_common.h>

class cTkAttachmentData
{
    static unsigned long long muNameHash = 0x9756E001A603A3B1;
    static unsigned long long muTemplateHash = 0x6F7B6FDB3A0572E9;

    cTkDynamicArray<cTkClassPointer> maComponents;
    cTkFixedArray<float> maLodDistances;
}
