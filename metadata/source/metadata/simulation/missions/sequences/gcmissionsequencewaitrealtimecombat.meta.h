#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceWaitRealTimeCombat
{
    static unsigned long long muNameHash = 0xB497A82E7D25F7C4;
    static unsigned long long muTemplateHash = 0x295C0C71FB3CCFD1;

    cTkFixedString<128,char> macMessage;
    cTkFixedString<128,char> macMessageCombat;
    unsigned long long mui64Time;
    float mfRandomness;
    TkID<128> mDisplayStat;
    bool mbStatFromNow;
    cTkFixedString<128,char> macDebugText;
}
