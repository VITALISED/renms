#pragma once
#include <metadata/metadata_common.h>
enum eAtlasPathProgressType
{
    EAtlasPathProgressType_IncrementPathProgress = 0,
    EAtlasPathProgressType_FinalStoryAtlas = 1,
}

class cGcRewardAtlasPathProgress
{
    static unsigned long long muNameHash = 0x2FFD5C572426F075;
    static unsigned long long muTemplateHash = 0x29D761D8EFF76D18;

    eAtlasPathProgressType AtlasPathProgressType;
}
