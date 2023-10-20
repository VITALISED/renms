#pragma once
#include <metadata/metadata_common.h>
enum eSettlementJudgementType
{
    ESettlementJudgementType_None = 0,
    ESettlementJudgementType_StrangerVisit = 1,
    ESettlementJudgementType_Policy = 2,
    ESettlementJudgementType_NewBuilding = 3,
    ESettlementJudgementType_BuildingChoice = 4,
    ESettlementJudgementType_Conflict = 5,
    ESettlementJudgementType_Request = 6,
}

class cGcSettlementJudgementType
{
    static unsigned long long muNameHash = 0x9B6A014776B1F8BB;
    static unsigned long long muTemplateHash = 0xBCAE176B666C6AF7;

    eSettlementJudgementType SettlementJudgementType;
}
