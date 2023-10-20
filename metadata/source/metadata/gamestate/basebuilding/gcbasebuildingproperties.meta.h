#pragma once
#include <metadata/metadata_common.h>

class cGcBaseBuildingProperties
{
    static unsigned long long muNameHash = 0x8A61B341C43F08CE;
    static unsigned long long muTemplateHash = 0x7CEFD7C337BEB1A6;

    TkID<128> mDefaultInBaseObject;
    TkID<128> mDefaultOnTerrainObject;
    TkID<128> mDefaultInFreighterObject;
}
