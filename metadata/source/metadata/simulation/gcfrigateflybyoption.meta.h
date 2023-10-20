#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcfrigateclass.meta.h>

class cGcFrigateFlybyOption
{
    static unsigned long long muNameHash = 0x7219E3FF7006060F;
    static unsigned long long muTemplateHash = 0xE8D8F0C9A4D20C4C;

    cGcFrigateClass FrigateClass;
    int miMinCount;
    int miMaxCount;
    float mfWeight;
}
