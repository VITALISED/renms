#pragma once
#include <metadata/metadata_common.h>
#include <metadata/audio/gcaudiowwiseevents.meta.h>

class cGcMissionSequenceAudioEvent
{
    static unsigned long long muNameHash = 0x4B1DBAB6A4BE391D;
    static unsigned long long muTemplateHash = 0x40EED3F43C35F16B;

    cGcAudioWwiseEvents AudioEvent;
    cTkFixedString<128,char> macDebugText;
}
