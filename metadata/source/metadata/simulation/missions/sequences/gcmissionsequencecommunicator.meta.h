#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/player/gcplayercommunicatormessage.meta.h>

class cGcMissionSequenceCommunicator
{
    static unsigned long long muNameHash = 0xD14F8D38E31CAB20;
    static unsigned long long muTemplateHash = 0xDD46519927037100;

    cTkFixedString<128,char> macMessage;
    cTkFixedString<128,char> macVRMessage;
    cTkFixedString<128,char> macOSDMessage;
    cGcPlayerCommunicatorMessage Comms;
    bool mbAutoOpen;
    cTkFixedString<128,char> macDebugText;
}
