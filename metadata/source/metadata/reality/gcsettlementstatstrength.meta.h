#pragma once
#include <metadata/metadata_common.h>
enum eSettlementStatStrength
{
    ESettlementStatStrength_PositiveWide = 0,
    ESettlementStatStrength_PositiveLarge = 1,
    ESettlementStatStrength_PositiveMedium = 2,
    ESettlementStatStrength_PositiveSmall = 3,
    ESettlementStatStrength_NegativeSmall = 4,
    ESettlementStatStrength_NegativeMedium = 5,
    ESettlementStatStrength_NegativeLarge = 6,
}

class cGcSettlementStatStrength
{
    static unsigned long long muNameHash = 0x3B7C404C59D201EF;
    static unsigned long long muTemplateHash = 0x36C7F6656EB4C5C0;

    eSettlementStatStrength SettlementStatStrength;
}
