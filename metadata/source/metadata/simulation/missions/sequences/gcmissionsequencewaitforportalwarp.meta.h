#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceWaitForPortalWarp
{
    static unsigned long long muNameHash = 0x416E9E84AB204114;
    static unsigned long long muTemplateHash = 0x7B630FEAA5DAE67F;

    cTkFixedString<128,char> macMessage;
    cTkFixedString<128,char> macDebugText;
    bool mbWarpToSpace;
    cTkFixedString<32,char> macOverrideUA;
}
