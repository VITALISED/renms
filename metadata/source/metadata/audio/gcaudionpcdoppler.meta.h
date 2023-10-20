#pragma once
#include <metadata/metadata_common.h>
#include <metadata/audio/gcaudio3pointdopplerdata.meta.h>

class cGcAudioNPCDoppler
{
    static unsigned long long muNameHash = 0xC02D1C8C9CF91C83;
    static unsigned long long muTemplateHash = 0x866658EDEE3C2AC8;

    cTkFixedArray<cGcAudio3PointDopplerData> maConfig;
}
