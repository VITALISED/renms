#pragma once
#include <metadata/metadata_common.h>

class cGcNPCPlacementComponentData
{
    static unsigned long long muNameHash = 0x8047BE4D11BB54C8;
    static unsigned long long muTemplateHash = 0x126EC8A5580C79E9;

    bool mbSearchPlacementFromMaster;
    bool mbPlaceInAbandonedSystems;
    cTkDynamicArray<TkID<128>> maPlacementInfosToApply;
    bool mbWaitToPlace;
}
