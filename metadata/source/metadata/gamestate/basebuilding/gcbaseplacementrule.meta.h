#pragma once
#include <metadata/metadata_common.h>
enum eTwinCriteria
{
    ETwinCriteria_None = 0,
    ETwinCriteria_MoveToTwin = 1,
    ETwinCriteria_StretchToTwin = 2,
    ETwinCriteria_StretchToRaycast = 3,
    ETwinCriteria_MoveToTwinRelative = 4,
}

class cGcBasePlacementRule
{
    static unsigned long long muNameHash = 0xE9F8FE2C0612C3FE;
    static unsigned long long muTemplateHash = 0x86553802E4988FA;

    cTkDynamicArray<cTkClassPointer> maConditions;
    cTkFixedString<128,char> macPositionLocator;
    TkID<256> mPartID;
    bool mbORConditions;
    eTwinCriteria TwinCriteria;
}
