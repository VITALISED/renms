#pragma once
#include <metadata/metadata_common.h>
#include <metadata/audio/gcaudiowwiseevents.meta.h>

class cGcAudioAreaTriggerComponentData
{
    static unsigned long long muNameHash = 0xD1618D63DA15668C;
    static unsigned long long muTemplateHash = 0x42B90A58987CD1A4;

    cGcAudioWwiseEvents EventEnter;
    cGcAudioWwiseEvents EventExit;
    float mfEnterDistance;
    float mfExitDistance;
}
