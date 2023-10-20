#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcBaseBuildingPartNavData
{
    static unsigned long long muNameHash = 0xE1F61A258ED99443;
    static unsigned long long muTemplateHash = 0xF889885B27980DD0;

    TkID<256> mPartID;
    cTkDynamicArray<cGcBaseBuildingPartInteractionData> maSharedInteractions;
    cTkDynamicArray<cGcBaseBuildingPartNavNodeData> maNavNodeData;
}
