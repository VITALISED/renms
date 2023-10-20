#pragma once
#include <metadata/metadata_common.h>

class cTkBlackboardValueId
{
    static unsigned long long muNameHash = 0x9A99DA98FF7577EC;
    static unsigned long long muTemplateHash = 0xF389D6C1037D3BC4;

    TkID<128> mKey;
    TkID<128> mValue;
}
