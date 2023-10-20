#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/player/gcgrabbabledata.meta.h>

class cGcGrabbableComponentData
{
    static unsigned long long muNameHash = 0x82286E866B7201D0;
    static unsigned long long muTemplateHash = 0xEB37132AE7E00F81;

    cTkDynamicArray<cGcGrabbableData> maGrabbableDataArray;
}
