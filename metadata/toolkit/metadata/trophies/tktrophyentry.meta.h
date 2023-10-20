#pragma once
#include <metadata/metadata_common.h>

class cTkTrophyEntry
{
    static unsigned long long muNameHash = 0x51D536C649733342;
    static unsigned long long muTemplateHash = 0xA2014717593869BC;

    TkID<128> mTrophyId;
    int miPs4Id;
    cTkFixedString<64,char> macPCId;
    cTkFixedString<32,char> macXboxOneId;
}
