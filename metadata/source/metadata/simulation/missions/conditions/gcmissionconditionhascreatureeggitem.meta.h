#pragma once
#include <metadata/metadata_common.h>
enum eEggItemType
{
    EEggItemType_Egg = 0,
    EEggItemType_ValidCatalyst = 1,
}

class cGcMissionConditionHasCreatureEggItem
{
    static unsigned long long muNameHash = 0x6FDB38E1B65AEDCB;
    static unsigned long long muTemplateHash = 0xEDFECED53D39F1A8;

    eEggItemType EggItemType;
    bool mbIncludeEggMachineInventoryInSearch;
}
