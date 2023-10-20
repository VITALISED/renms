#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceScan
{
    static unsigned long long muNameHash = 0x828E03CA6A18781E;
    static unsigned long long muTemplateHash = 0x7D31AF6E63D2784E;

    cTkFixedString<128,char> macMessage;
    float mfWaitTime;
    bool mbBlockTimedScans;
    bool mbRequiresMissionActive;
    cTkFixedString<128,char> macDebugText;
}
