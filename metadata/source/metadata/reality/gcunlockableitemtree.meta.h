#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcUnlockableItemTree
{
    static unsigned long long muNameHash = 0x6B3A62EF81161171;
    static unsigned long long muTemplateHash = 0x82DD1A0F7255A793;

    TkID<256> mTitle;
    TkID<128> mCostTypeID;
    cGcUnlockableItemTreeNode Root;
}
