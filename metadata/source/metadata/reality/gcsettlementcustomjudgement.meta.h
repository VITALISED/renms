#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcsettlementjudgementdata.meta.h>

class cGcSettlementCustomJudgement
{
    static unsigned long long muNameHash = 0xD0AB76328A1D707;
    static unsigned long long muTemplateHash = 0xAC60C40B229BE2E8;

    TkID<128> mID;
    cGcSettlementJudgementData Data;
    TkID<256> mCustomCostText;
}
