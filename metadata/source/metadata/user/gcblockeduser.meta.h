#pragma once
#include <metadata/metadata_common.h>

class cGcBlockedUser
{
    static unsigned long long muNameHash = 0x3317FE9999913ADE;
    static unsigned long long muTemplateHash = 0x7072D0794DC08252;

    cTkFixedString<64,char> macUserId;
    cTkFixedString<64,char> macUsername;
    cTkFixedString<32,char> macPlatform;
}
