#pragma once
#include <metadata/metadata_common.h>

class cGcWordKnowledge
{
    static unsigned long long muNameHash = 0x30324FBB2A97B16E;
    static unsigned long long muTemplateHash = 0x83B984F88079F831;

    TkID<128> mWord;
    cTkFixedArray<bool> maRaces;
}
