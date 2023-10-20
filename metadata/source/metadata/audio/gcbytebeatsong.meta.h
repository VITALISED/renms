#pragma once
#include <metadata/metadata_common.h>

class cGcByteBeatSong
{
    static unsigned long long muNameHash = 0xDC95ACD037A3B77;
    static unsigned long long muTemplateHash = 0x7A1695EC46335BC8;

    TkID<128> mId;
    TkID<128> mRequiredSpecialId;
    cTkFixedString<32,char> macName;
    TkID<256> mLocID;
    cTkFixedString<64,char> macAuthorOnlineID;
    cTkFixedString<64,char> macAuthorUsername;
    cTkFixedString<64,char> macAuthorPlatform;
    cTkFixedArray<cTkFixedString<64,char>> maData;
}
