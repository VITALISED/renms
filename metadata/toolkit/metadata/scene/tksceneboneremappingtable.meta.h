#pragma once
#include <metadata/metadata_common.h>
#include <metadata/scene/tksceneboneremapping.meta.h>

class cTkSceneBoneRemappingTable
{
    static unsigned long long muNameHash = 0xAF2831AAF7DE1710;
    static unsigned long long muTemplateHash = 0xF4BF89FC3D6D6F02;

    cTkDynamicArray<cTkSceneBoneRemapping> maBoneMappings;
}
