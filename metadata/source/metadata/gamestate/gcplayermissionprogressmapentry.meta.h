#pragma once
#include <metadata/metadata_common.h>

class cGcPlayerMissionProgressMapEntry
{
    static unsigned long long muNameHash = 0x7D5B5172D2A5F9E5;
    static unsigned long long muTemplateHash = 0x5807E42B53C65688;

    TkID<128> mMission;
    int miMinProgress;
    int miMaxProgress;
    int miNewProgress;
}
