#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/components/gameplay/gcinteractiontype.meta.h>
#include <metadata/tktextureresource.meta.h>
#include <metadata/wiki/gcstoryentry.meta.h>
#include <metadata/wiki/gcwikitopictype.meta.h>

class cGcStoryPage
{
    static unsigned long long muNameHash = 0xDA4CC10DF6E92F8C;
    static unsigned long long muTemplateHash = 0xE8EF7AE92F0F264;

    cGcInteractionType InteractionType;
    TkID<128> mStat;
    bool mbStatIsBitmask;
    cTkTextureResource Icon;
    TkID<256> mID;
    cTkDynamicArray<cGcStoryEntry> maEntries;
    bool mbUseGridType;
    cGcWikiTopicType WikiGridType;
}
