#pragma once
#include <metadata/metadata_common.h>

class cGcExactResource
{
    static unsigned long long muNameHash = 0xBC849663458378CD;
    static unsigned long long muTemplateHash = 0xFA9C048067CD89F4;

    cTkFixedString<128,char> macFilename;
    cTkSeed mGenerationSeed;
}
