#pragma once
#include <metadata/metadata_common.h>

class cGcFreighterBaseOption
{
    static unsigned long long muNameHash = 0x27F9FF00242DF25A;
    static unsigned long long muTemplateHash = 0x27012A46D9BE0F1C;

    cTkFixedString<128,char> macBaseDataFile;
    float mfProbabilityWeighting;
}
