#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceGatherForBuild
{
    static unsigned long long muNameHash = 0xB85371DB04FCCA0;
    static unsigned long long muTemplateHash = 0xC5B34FA6047A48EA;

    cTkFixedString<128,char> macMessage;
    TkID<128> mTargetTech;
    TkID<128> mGatherResource;
    cTkFixedString<128,char> macDebugText;
}
