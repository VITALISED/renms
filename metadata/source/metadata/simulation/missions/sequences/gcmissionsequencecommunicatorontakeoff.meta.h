#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcMissionSequenceCommunicatorOnTakeOff
{
    static unsigned long long muNameHash = 0x8667E548FE078CD2;
    static unsigned long long muTemplateHash = 0x379F8CD07C145925;

    cTkFixedString<128,char> macMessage;
    cGcPlayerCommunicatorMessage Comms;
    cTkFixedString<128,char> macDebugText;
}
