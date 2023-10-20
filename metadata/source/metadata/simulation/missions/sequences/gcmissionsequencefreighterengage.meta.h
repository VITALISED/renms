#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceFreighterEngage
{
    static unsigned long long muNameHash = 0x5755416737105B76;
    static unsigned long long muTemplateHash = 0x58BA8A8354A7C52B;

    cTkFixedString<128,char> macMessageGetToSpace;
    cTkFixedString<128,char> macMessageEngage;
    float mfEngageDistance;
    float mfEngageTime;
    float mfTimeAfterWarp;
    TkID<128> mTimeoutMessage;
    cTkFixedString<128,char> macTimeoutOSDMessage;
    cTkFixedString<128,char> macDebugText;
}
