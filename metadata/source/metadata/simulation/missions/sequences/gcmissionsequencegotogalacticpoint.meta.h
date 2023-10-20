#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/missions/types/gcmissiongalacticpoint.meta.h>

class cGcMissionSequenceGoToGalacticPoint
{
    static unsigned long long muNameHash = 0xDC7A747D3350B89B;
    static unsigned long long muTemplateHash = 0xBF69424E7FAC4765;

    cTkFixedString<128,char> macMessage;
    cGcMissionGalacticPoint Target;
    cTkFixedString<128,char> macDebugText;
}
