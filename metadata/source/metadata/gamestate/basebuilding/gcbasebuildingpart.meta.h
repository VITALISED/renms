#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcBaseBuildingPart
{
    static unsigned long long muNameHash = 0xB219FB318ABC12CF;
    static unsigned long long muTemplateHash = 0xD4D71B061933C6D3;

    TkID<256> mID;
    cTkDynamicArray<cGcBaseBuildingPartStyleModel> maStyleModels;
}
