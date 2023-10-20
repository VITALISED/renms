#pragma once
#include <metadata/metadata_common.h>

class cGcGeneratedBasePruningRule
{
    static unsigned long long muNameHash = 0x37476C35069E0A8F;
    static unsigned long long muTemplateHash = 0x360C266CF8B4160B;

    TkID<128> mRuleId;
    TkID<128> mNodeName;
    int miMaxPerRoom;
    int miMaxPerDungeon;
    cTkDynamicArray<TkID<128>> maRoomFilters;
}
