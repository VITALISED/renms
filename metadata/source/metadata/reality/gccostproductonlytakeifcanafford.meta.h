#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/missions/defaultmissionitems/gcdefaultmissionproductenum.meta.h>

class cGcCostProductOnlyTakeIfCanAfford
{
    static unsigned long long muNameHash = 0xDEF97AA1BA31BC2A;
    static unsigned long long muTemplateHash = 0x6375DE27340DF292;

    cGcDefaultMissionProductEnum Default;
    TkID<128> mId;
    int miAmount;
    TkID<256> mAltCostLocID;
}
