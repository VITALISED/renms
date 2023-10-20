#pragma once
#include <metadata/metadata_common.h>
#include <metadata/audio/gcaudiowwiseevents.meta.h>
#include <metadata/simulation/missions/sequences/gcmissionsequencedetailmessagepoint.meta.h>

class cGcMissionSequenceDetailMessage
{
    static unsigned long long muNameHash = 0xA29EE4D703004484;
    static unsigned long long muTemplateHash = 0x660FF7F8D21AAB38;

    TkID<256> mTitle;
    TkID<256> mDescription;
    TkID<256> mImage;
    cGcAudioWwiseEvents AudioEvent;
    cTkDynamicArray<cGcMissionSequenceDetailMessagePoint> maPoints;
    cTkFixedString<128,char> macDebugText;
}
