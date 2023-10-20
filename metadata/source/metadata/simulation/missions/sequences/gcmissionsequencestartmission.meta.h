#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceStartMission
{
    static unsigned long long muNameHash = 0x5BB6B87A77237F5E;
    static unsigned long long muTemplateHash = 0x36BCC2C1C110521;

    cTkFixedString<128,char> macMessage;
    TkID<128> mMissionID;
    bool mbMakeCurrent;
    bool mbRestart;
    bool mbForced;
    cTkFixedString<128,char> macDebugText;
}
