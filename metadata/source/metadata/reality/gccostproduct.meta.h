#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/missions/defaultmissionitems/gcdefaultmissionproductenum.meta.h>

class cGcCostProduct
{
    static unsigned long long muNameHash = 0xE90BC34FB3DEA4D7;
    static unsigned long long muTemplateHash = 0x2748250647D75225;

    cGcDefaultMissionProductEnum Default;
    TkID<128> mId;
    int miAmount;
}
