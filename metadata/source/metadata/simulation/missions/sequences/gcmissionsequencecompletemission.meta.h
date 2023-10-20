#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceCompleteMission
{
    static unsigned long long muNameHash = 0xF34AADF7CA91192B;
    static unsigned long long muTemplateHash = 0xD7A66E523D362B0B;

    TkID<128> mMission;
    bool mbUseSeed;
    cTkFixedString<128,char> macDebugText;
}
