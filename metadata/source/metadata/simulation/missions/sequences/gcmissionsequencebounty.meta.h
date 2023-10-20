#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceBounty
{
    static unsigned long long muNameHash = 0xB91599B59D30BF64;
    static unsigned long long muTemplateHash = 0xA6010DAF1B8A8D15;

    cTkFixedString<128,char> macMessageGetToSpace;
    cTkFixedString<128,char> macMessageEngage;
    cTkFixedString<128,char> macMessageDestroy;
    TkID<128> mBounty;
    cTkFixedString<128,char> macDebugText;
}
