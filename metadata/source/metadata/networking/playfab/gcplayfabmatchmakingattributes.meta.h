#pragma once
#include <metadata/metadata_common.h>

class cGcPlayfabMatchmakingAttributes
{
    static unsigned long long muNameHash = 0x49457F0F4ABEDEE6;
    static unsigned long long muTemplateHash = 0x7CB74261EDC1603B;

    cTkFixedString<64,char> macUA;
    cTkFixedString<128,char> macmatchmakingVersion;
    int miisBackfilling;
    int mineedsSmallLobby;
    int migameProgress;
    cTkFixedString<128,char> macplatform;
    cTkFixedString<128,char> macgamemode;
    cTkFixedString<256,char> maclobbyConnectionString;
    cTkFixedString<64,char> macseasonNumber;
}
