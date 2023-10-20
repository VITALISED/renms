#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/missions/types/gcbuildingpartsearchtype.meta.h>

class cGcMissionSequenceBuild
{
    static unsigned long long muNameHash = 0xB9769DB00B6A3E69;
    static unsigned long long muTemplateHash = 0x4B9BAF4E53AB1B89;

    cTkFixedString<128,char> macMessage;
    TkID<128> mPart;
    bool mbTakePartFromSeasonData;
    bool mbTeachIfNotKnown;
    cGcBuildingPartSearchType Type;
    cTkFixedString<128,char> macDebugText;
}
