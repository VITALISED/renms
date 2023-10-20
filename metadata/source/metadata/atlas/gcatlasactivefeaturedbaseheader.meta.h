#pragma once
#include <metadata/metadata_common.h>

class cGcAtlasActiveFeaturedBaseHeader
{
    static unsigned long long muNameHash = 0x5CA0B64244DF6963;
    static unsigned long long muTemplateHash = 0x8DB16379E37A198F;

    bool mbDev;
    bool mbQA;
    bool mbProd;
    cTkFixedString<32,char> macPlatform;
    cTkFixedString<64,char> macUserId;
    cTkFixedString<64,char> macUserName;
    cTkFixedString<64,char> macBaseName;
    cTkFixedString<64,char> macUA;
    cTkFixedString<64,char> macBaseId;
}
