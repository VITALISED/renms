#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcMissionSequenceStartScanEventSpecific
{
    static unsigned long long muNameHash = 0x83CCE421927A9559;
    static unsigned long long muTemplateHash = 0xC243D869B4748920;

    bool mbIMeantThisAndKnowWhatItDoes;
    cGcPlayerMissionParticipant Participant;
    TkID<256> mEvent;
    float mfTime;
    bool mbAllowOtherPlayersBase;
    cTkFixedString<128,char> macDebugText;
}
