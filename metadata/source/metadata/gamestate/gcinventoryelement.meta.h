#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcInventoryElement
{
    static unsigned long long muNameHash = 0xF6B3A96F7D4F7967;
    static unsigned long long muTemplateHash = 0x1E74CFC329DC906E;

    cGcInventoryType Type;
    TkID<128> mId;
    int miAmount;
    int miMaxAmount;
    float mfDamageFactor;
    bool mbFullyInstalled;
    cGcInventoryIndex Index;
}
