#pragma once
#include <metadata/metadata_common.h>
#include <metadata/audio/gcbasepartaudiolocation.meta.h>

class cGcBaseBuildingPartAudioLocationEntry
{
    static unsigned long long muNameHash = 0xD7DAD354CC760BEE;
    static unsigned long long muTemplateHash = 0xF59BD607E75A9055;

    TkID<128> mPartId;
    cGcBasePartAudioLocation AudioLocation;
}
