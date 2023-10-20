#pragma once
#include <metadata/metadata_common.h>

class cGcShipInventoryMaxUpgradeCapacity
{
    static unsigned long long muNameHash = 0xC51C8A0A49F892DC;
    static unsigned long long muTemplateHash = 0xCC46D1E97F0D733C;

    cTkFixedArray<int> maMaxInventoryCapacity;
    cTkFixedArray<int> maMaxTechInventoryCapacity;
    cTkFixedArray<int> maMaxCargoInventoryCapacity;
}
