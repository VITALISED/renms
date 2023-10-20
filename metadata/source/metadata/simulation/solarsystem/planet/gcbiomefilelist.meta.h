#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/solarsystem/planet/gcbiomefilelistoptions.meta.h>
#include <metadata/simulation/solarsystem/planet/gcbiometype.meta.h>
#include <metadata/simulation/environment/gcexternalobjectlistoptions.meta.h>
#include <metadata/simulation/solarsystem/planet/gcexternalobjectfilelist.meta.h>

class cGcBiomeFileList
{
    static unsigned long long muNameHash = 0x369AF9F4E4E055D0;
    static unsigned long long muTemplateHash = 0xCBE51C9993608260;

    cTkFixedArray<cGcBiomeFileListOptions> maBiomeFiles;
    cTkDynamicArray<cGcBiomeType> maValidStartPlanetBiome;
    cTkDynamicArray<cGcExternalObjectListOptions> maCommonExternalObjectLists;
    cTkDynamicArray<cGcExternalObjectFileList> maOptionalExternalObjectLists;
}
