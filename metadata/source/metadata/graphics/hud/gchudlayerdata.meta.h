#pragma once
#include <metadata/metadata_common.h>
#include <metadata/graphics/hud/gchudcomponent.meta.h>

class cGcHUDLayerData
{
    static unsigned long long muNameHash = 0xCA155452FD6149EC;
    static unsigned long long muTemplateHash = 0xED03E29B05715C43;

    cGcHUDComponent Data;
    cTkDynamicArray<cTkClassPointer> maChildren;
}
