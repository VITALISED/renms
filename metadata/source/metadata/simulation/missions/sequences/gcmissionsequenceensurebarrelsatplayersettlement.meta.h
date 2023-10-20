#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceEnsureBarrelsAtPlayerSettlement
{
    static unsigned long long muNameHash = 0x43A40CA703B36FA8;
    static unsigned long long muTemplateHash = 0xDE9730230B3623F0;

    cTkFixedString<128,char> macMessage;
    int miNumBarrels;
    int miMinBarrelsThreshold;
    cTkFixedString<128,char> macDebugText;
}
