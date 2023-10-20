#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceWaitForStat
{
    static unsigned long long muNameHash = 0x197E91849165F7F4;
    static unsigned long long muTemplateHash = 0xB0C3876D5B99F9AB;

    cTkFixedString<128,char> macMessage;
    TkID<128> mStat;
    TkID<128> mStatGroup;
    int miAmount;
    cTkFixedString<128,char> macDebugText;
}
