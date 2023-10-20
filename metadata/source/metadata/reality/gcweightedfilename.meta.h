#pragma once
#include <metadata/metadata_common.h>

class cGcWeightedFilename
{
    static unsigned long long muNameHash = 0x7AC84D51C8490F18;
    static unsigned long long muTemplateHash = 0x5696276A0988F187;

    cTkFixedString<128,char> macFilename;
    float mfWeight;
}
