#pragma once
#include <metadata/metadata_common.h>
enum eBuildPartSearchType
{
    EBuildPartSearchType_Base = 0,
    EBuildPartSearchType_Freighter = 1,
    EBuildPartSearchType_AllPlayerOwned = 2,
    EBuildPartSearchType_OtherPlayerBase = 3,
}
#include <metadata/gamestate/basebuilding/gcpersistentbasetypes.meta.h>

class cGcBuildingPartSearchType
{
    static unsigned long long muNameHash = 0xAEBE0762190D9B2;
    static unsigned long long muTemplateHash = 0xED77BBD7595FB24A;

    eBuildPartSearchType BuildPartSearchType;
    cTkDynamicArray<cGcPersistentBaseTypes> maBaseSearchFilters;
    bool mbIncludeOnlyOverlappingBases;
    bool mbIncludeGlobalBaseObjects;
}
