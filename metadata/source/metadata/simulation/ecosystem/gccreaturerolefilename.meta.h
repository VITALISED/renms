#pragma once
#include <metadata/metadata_common.h>

class cGcCreatureRoleFilename
{
    static unsigned long long muNameHash = 0x6474461C1BF89153;
    static unsigned long long muTemplateHash = 0xF6F70602F611DE61;

    cTkFixedString<128,char> macFile;
    cTkFixedArray<float> maBiomeProbability;
}
