#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/environment/gctiletypeset.meta.h>

class cGcTileTypeSets
{
    static unsigned long long muNameHash = 0xF99FFC7B95E84D7D;
    static unsigned long long muTemplateHash = 0x981F92335A08664E;

    cTkDynamicArray<cGcTileTypeSet> maTileTypeSets;
}
