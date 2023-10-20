#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceWaitForAbandFreighterDoorOpen
{
    static unsigned long long muNameHash = 0x3C3DF65980E5A451;
    static unsigned long long muTemplateHash = 0x73E8F75E6864E10;

    cTkFixedString<128,char> macMessage;
    cTkFixedString<128,char> macMessageOvertime;
    float mfMinTime;
    cTkFixedString<128,char> macDebugText;
}
