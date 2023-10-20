#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceWaitForFriendlyDroneScanEvent
{
    static unsigned long long muNameHash = 0xD5B668729A28BD2C;
    static unsigned long long muTemplateHash = 0x7BDD2A2532E47943;

    cTkFixedString<128,char> macMessageSummoned;
    cTkFixedString<128,char> macMessageUnsummoned;
    cTkFixedString<128,char> macMessageCantSummon;
    cTkFixedString<128,char> macMessageNotAvailable;
    TkID<256> mEvent;
    cTkFixedString<128,char> macDebugText;
}
