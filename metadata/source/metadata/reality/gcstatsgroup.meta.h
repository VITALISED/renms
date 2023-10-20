#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tktextureresource.meta.h>
#include <metadata/reality/gcstatsentry.meta.h>

class cGcStatsGroup
{
    static unsigned long long muNameHash = 0xEB5E59FB895AFF06;
    static unsigned long long muTemplateHash = 0x749E211290DC4EA9;

    TkID<128> mId;
    cTkTextureResource Icon;
    cTkDynamicArray<cGcStatsEntry> maStatIds;
}
