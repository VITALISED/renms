#pragma once
#include <metadata/metadata_common.h>
enum eGalacticPoint
{
    EGalacticPoint_Atlas = 0,
    EGalacticPoint_BlackHole = 1,
}

class cGcMissionGalacticPoint
{
    static unsigned long long muNameHash = 0xA75A686CCD91261E;
    static unsigned long long muTemplateHash = 0x216768598125DA74;

    eGalacticPoint GalacticPoint;
}
