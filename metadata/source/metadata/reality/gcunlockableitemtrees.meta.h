#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcunlockableitemtree.meta.h>

class cGcUnlockableItemTrees
{
    static unsigned long long muNameHash = 0x2B87D92751133C6D;
    static unsigned long long muTemplateHash = 0x7427D4FE1C1DF652;

    TkID<256> mTitle;
    cTkDynamicArray<cGcUnlockableItemTree> maTrees;
}
