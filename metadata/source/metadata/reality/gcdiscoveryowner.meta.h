#pragma once
#include <metadata/metadata_common.h>

class cGcDiscoveryOwner
{
    static unsigned long long muNameHash = 0x59B76FD6543E9F75;
    static unsigned long long muTemplateHash = 0x43D52A16FFF4C492;

    cTkFixedString<64,char> macLocalID;
    cTkFixedString<64,char> macOnlineID;
    cTkFixedString<64,char> macUsername;
    cTkFixedString<64,char> macPlatform;
    int miTimestamp;
}
