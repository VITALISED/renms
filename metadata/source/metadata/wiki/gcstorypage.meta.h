#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>

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
