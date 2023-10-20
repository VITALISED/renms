#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcInventoryBaseStat
{
    static unsigned long long muNameHash = 0x88CEC164B6BD4ACC;
    static unsigned long long muTemplateHash = 0x8F941504516BA58F;

    TkID<128> mBaseStatID;
    TkID<128> mLocID;
    cTkDynamicArray<cGcInventoryBaseStatBonus> maStatBonus;
}
