#pragma once
#include <metadata/metadata_common.h>

class cTkSceneBoneRemapping
{
    static unsigned long long muNameHash = 0x8EBBD5819BF9FEBA;
    static unsigned long long muTemplateHash = 0x4303F72D523C7C23;

    cTkFixedString<128,char> macFromBone;
    cTkFixedString<128,char> macToBone;
}
