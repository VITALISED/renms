#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/environment/gcbuildingfilenamelist.meta.h>
#include <metadata/simulation/environment/gcbuildingdefinitiondata.meta.h>
#include <metadata/simulation/environment/gcbuildingclusterlayout.meta.h>

class cGcBuildingDefinitionTable
{
    static unsigned long long muNameHash = 0x9808AB95D152F880;
    static unsigned long long muTemplateHash = 0x8CDE09C9AD3FE42E;

    cTkFixedArray<cGcBuildingFilenameList> maBuildingFiles;
    cTkFixedArray<cGcBuildingDefinitionData> maBuildingPlacement;
    cTkDynamicArray<cGcBuildingClusterLayout> maClusterLayouts;
}
