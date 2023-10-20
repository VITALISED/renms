#pragma once
#include <metadata/metadata_common.h>

class cTkPlatformButtonPair
{
    static unsigned long long muNameHash = 0xC728D4342BAC4AC8;
    static unsigned long long muTemplateHash = 0x58E4F308E63BA84A;

    TkID<128> mPlatformId;
    TkID<128> mButtonId;
    cTkVector2 mSize;
}
