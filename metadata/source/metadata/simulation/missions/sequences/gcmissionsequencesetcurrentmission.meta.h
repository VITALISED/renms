#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceSetCurrentMission
{
    static unsigned long long muNameHash = 0x48508806BFEC4731;
    static unsigned long long muTemplateHash = 0xA39B8B61E2532C5;

    TkID<128> mMissionID;
    bool mbSilent;
    cTkFixedString<128,char> macDebugText;
}
