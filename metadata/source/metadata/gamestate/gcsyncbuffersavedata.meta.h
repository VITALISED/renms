#pragma once
#include <metadata/metadata_common.h>

class cGcSyncBufferSaveData
{
    static unsigned long long muNameHash = 0xEFA8947B437770B8;
    static unsigned long long muTemplateHash = 0x42BCA060447AA539;

    unsigned long long mui64SpaceAddress;
    cTkFixedString<64,char> macOwnerOnlineId;
    cTkFixedString<32,char> macOwnerPlatformId;
    unsigned int muiBufferVersion;
    unsigned int muiItemsCount;
}
