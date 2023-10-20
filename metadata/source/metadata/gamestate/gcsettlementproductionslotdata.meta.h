#pragma once
#include <metadata/metadata_common.h>

class cGcSettlementProductionSlotData
{
    static unsigned long long muNameHash = 0xB7360AAB256AE198;
    static unsigned long long muTemplateHash = 0x355BA0DF50A5EAA2;

    TkID<128> mElementId;
    unsigned long long mui64LastChangeTimestamp;
    int miAmount;
}
