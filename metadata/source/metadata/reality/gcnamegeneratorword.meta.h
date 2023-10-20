#pragma once
#include <metadata/metadata_common.h>

class cGcNameGeneratorWord
{
    static unsigned long long muNameHash = 0x814E1DAF35C8BB77;
    static unsigned long long muTemplateHash = 0x8D78C79FE61C807;

    TkID<256> mWord;
    int miNumOptions;
}
