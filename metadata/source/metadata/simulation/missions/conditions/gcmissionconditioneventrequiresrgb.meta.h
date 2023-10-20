#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/galaxy/gcgalaxystartypes.meta.h>

class cGcMissionConditionEventRequiresRGB
{
    static unsigned long long muNameHash = 0x36CE03A85A61CBFB;
    static unsigned long long muTemplateHash = 0x74AC42112C063A55;

    TkID<256> mEvent;
    bool mbIgnoreIfPlayerHasAccess;
    cGcGalaxyStarTypes StarType;
}
