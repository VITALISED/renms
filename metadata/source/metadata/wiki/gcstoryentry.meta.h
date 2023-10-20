#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcStoryEntry
{
    static unsigned long long muNameHash = 0x7D4184057E24E50A;
    static unsigned long long muTemplateHash = 0x94B5A44747517D29;

    TkID<256> mTitle;
    TkID<256> mEntry;
    cTkDynamicArray<cGcStoryEntryBranch> maBranchedEntries;
    TkID<256> mAlienText;
    bool mbAutoPrefixWithAlienText;
    cGcAlienRace AlienTextForceRace;
}
