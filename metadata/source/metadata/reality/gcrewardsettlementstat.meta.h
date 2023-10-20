#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcsettlementstatchange.meta.h>

class cGcRewardSettlementStat
{
    static unsigned long long muNameHash = 0x156A8A17D82AA9E8;
    static unsigned long long muTemplateHash = 0x2CA3D6ACB985D077;

    cGcSettlementStatChange StatToAward;
    bool mbSilent;
}
