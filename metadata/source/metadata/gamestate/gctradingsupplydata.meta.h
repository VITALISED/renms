#pragma once
#include <metadata/metadata_common.h>

class cGcTradingSupplyData
{
    static unsigned long long muNameHash = 0x5D0FDAEE020A4D6C;
    static unsigned long long muTemplateHash = 0x6102D55E9E0BE76A;

    unsigned long long mui64GalacticAddress;
    float mfSupply;
    float mfDemand;
    TkID<128> mProduct;
    unsigned long long mui64Timestamp;
}
