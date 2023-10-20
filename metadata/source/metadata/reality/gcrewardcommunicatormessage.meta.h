#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/player/gcplayercommunicatormessage.meta.h>

class cGcRewardCommunicatorMessage
{
    static unsigned long long muNameHash = 0x382AC51563627203;
    static unsigned long long muTemplateHash = 0x9BEFA4E32B0C31DE;

    cTkFixedString<128,char> macMessage;
    cTkFixedString<128,char> macVRMessage;
    cTkFixedString<128,char> macOSDMessage;
    cGcPlayerCommunicatorMessage Comms;
    bool mbAutoOpen;
}
