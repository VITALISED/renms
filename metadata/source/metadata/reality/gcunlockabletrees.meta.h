#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcunlockableitemtrees.meta.h>
#include <metadata/reality/gcunlockabletreecosttype.meta.h>

class cGcUnlockableTrees
{
    static unsigned long long muNameHash = 0xDDC3AC505BDF81E2;
    static unsigned long long muTemplateHash = 0xAEF5D3ABB082A3D3;

    cTkFixedArray<cGcUnlockableItemTrees> maTrees;
    cTkDynamicArray<cGcUnlockableTreeCostType> maCostTypes;
}
