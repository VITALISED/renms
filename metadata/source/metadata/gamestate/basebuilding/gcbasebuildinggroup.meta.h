#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcBaseBuildingGroup
{
    static unsigned long long muNameHash = 0xF37F133693523902;
    static unsigned long long muTemplateHash = 0x3441CC565EC3BCC0;

    TkID<128> mID;
    TkID<256> mName;
    cTkTextureResource Icon;
    int miDefaultColourIdx;
    cTkDynamicArray<cGcBaseBuildingSubGroup> maSubGroups;
}
