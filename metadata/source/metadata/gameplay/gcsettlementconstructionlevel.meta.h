#pragma once
#include <metadata/metadata_common.h>
enum eSettlementConstructionLevel
{
    ESettlementConstructionLevel_Start = 0,
    ESettlementConstructionLevel_GroundStorey = 1,
    ESettlementConstructionLevel_RegularStorey = 2,
    ESettlementConstructionLevel_Roof = 3,
    ESettlementConstructionLevel_Decoration = 4,
    ESettlementConstructionLevel_Other = 5,
}

class cGcSettlementConstructionLevel
{
    static unsigned long long muNameHash = 0x69E9FB65CE773F84;
    static unsigned long long muTemplateHash = 0xA96B50DDF3B522E4;

    eSettlementConstructionLevel SettlementConstructionLevel;
}
