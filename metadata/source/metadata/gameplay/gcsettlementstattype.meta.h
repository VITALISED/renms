#pragma once
#include <metadata/metadata_common.h>
enum eSettlementStatType
{
    ESettlementStatType_Population = 0,
    ESettlementStatType_Happiness = 1,
    ESettlementStatType_Production = 2,
    ESettlementStatType_Upkeep = 3,
    ESettlementStatType_Sentinels = 4,
    ESettlementStatType_Debt = 5,
    ESettlementStatType_Alert = 6,
}

class cGcSettlementStatType
{
    static unsigned long long muNameHash = 0x9394F46EDEDBE660;
    static unsigned long long muTemplateHash = 0x7C86AE119BC952DC;

    eSettlementStatType SettlementStatType;
}
