#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceWaitRealTime
{
    static unsigned long long muNameHash = 0x32B3DC82536846ED;
    static unsigned long long muTemplateHash = 0xF72C2E794801BBF0;

    cTkFixedString<128,char> macMessage;
    unsigned long long mui64Time;
    float mfRandomness;
    TkID<128> mDisplayStat;
    bool mbStatFromNow;
    cTkFixedString<128,char> macDebugText;
}
