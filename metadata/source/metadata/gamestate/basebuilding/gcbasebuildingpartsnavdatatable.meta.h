#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/basebuilding/gcbasebuildingpartnavdata.meta.h>

class cGcBaseBuildingPartsNavDataTable
{
    static unsigned long long muNameHash = 0xD12E966E50238278;
    static unsigned long long muTemplateHash = 0xA3A1BE9387392976;

    cTkDynamicArray<cGcBaseBuildingPartNavData> maParts;
}
