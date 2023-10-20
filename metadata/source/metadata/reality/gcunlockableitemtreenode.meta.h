#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcUnlockableItemTreeNode
{
    static unsigned long long muNameHash = 0xB6094F57F9EFA01D;
    static unsigned long long muTemplateHash = 0x3DB47AF9459842C4;

    TkID<128> mUnlockable;
    cTkDynamicArray<cGcUnlockableItemTreeNode> maChildren;
}
