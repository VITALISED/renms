#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcBiomeFileList
{
    static unsigned long long muNameHash = 0x369AF9F4E4E055D0;
    static unsigned long long muTemplateHash = 0xCBE51C9993608260;

    cTkFixedArray<cGcBiomeFileListOptions> maBiomeFiles;
    cTkDynamicArray<cGcBiomeType> maValidStartPlanetBiome;
    cTkDynamicArray<cGcExternalObjectListOptions> maCommonExternalObjectLists;
    cTkDynamicArray<cGcExternalObjectFileList> maOptionalExternalObjectLists;
}
