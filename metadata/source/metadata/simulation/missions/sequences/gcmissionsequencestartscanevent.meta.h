#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcMissionSequenceStartScanEvent
{
    static unsigned long long muNameHash = 0x84E26BAA3B367507;
    static unsigned long long muTemplateHash = 0x42C7729718B0EBF7;

    cGcScanEventTableType Table;
    cGcPlayerMissionParticipantType Participant;
    TkID<256> mEvent;
    float mfTime;
    bool mbDoAerialScan;
    bool mbAllowOtherPlayersBase;
    cTkFixedString<128,char> macDebugText;
}
