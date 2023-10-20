#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceWaitForFreighterPods
{
    static unsigned long long muNameHash = 0x779C608FD9761375;
    static unsigned long long muTemplateHash = 0x41556C893A6A3E2;

    cTkFixedString<128,char> macMessage;
    int miAmount;
    bool mbTakeAmountFromPulseEncounter;
    cTkFixedString<128,char> macDebugText;
}
