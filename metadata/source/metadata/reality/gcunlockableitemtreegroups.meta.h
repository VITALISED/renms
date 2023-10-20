#pragma once
#include <metadata/metadata_common.h>
enum eUnlockableItemTree
{
    EUnlockableItemTree_Test = 0,
    EUnlockableItemTree_BasicBaseParts = 1,
    EUnlockableItemTree_BasicTechParts = 2,
    EUnlockableItemTree_BaseParts = 3,
    EUnlockableItemTree_SpecialBaseParts = 4,
    EUnlockableItemTree_SuitTech = 5,
    EUnlockableItemTree_ShipTech = 6,
    EUnlockableItemTree_WeapTech = 7,
    EUnlockableItemTree_ExocraftTech = 8,
    EUnlockableItemTree_CraftProducts = 9,
    EUnlockableItemTree_FreighterTech = 10,
    EUnlockableItemTree_S9BaseParts = 11,
    EUnlockableItemTree_S9ExoTech = 12,
    EUnlockableItemTree_S9ShipTech = 13,
}

class cGcUnlockableItemTreeGroups
{
    static unsigned long long muNameHash = 0x8F55B25E91A470A9;
    static unsigned long long muTemplateHash = 0x48765DB963EC9AB3;

    eUnlockableItemTree UnlockableItemTree;
}
