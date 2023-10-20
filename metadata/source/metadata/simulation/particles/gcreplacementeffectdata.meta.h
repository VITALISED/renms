#pragma once
#include <metadata/metadata_common.h>

class cGcReplacementEffectData
{
    static unsigned long long muNameHash = 0x7C3FC7921ED5983A;
    static unsigned long long muTemplateHash = 0xC9DAD52BAE1B52A0;

    TkID<128> mId;
    TkID<128> mReplaceWith;
}
