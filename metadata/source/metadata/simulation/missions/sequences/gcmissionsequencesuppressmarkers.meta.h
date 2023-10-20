#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceSuppressMarkers
{
    static unsigned long long muNameHash = 0x18AA3675C5404DBD;
    static unsigned long long muTemplateHash = 0x76DE5B0C8C8C5A15;

    bool mbSuppressed;
    bool mbSuppressedAfterNextWarp;
}
