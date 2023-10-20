#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gameplay/gcsettlementjudgementtype.meta.h>

class cGcRewardSettlementJudgement
{
    static unsigned long long muNameHash = 0x7A92D278225AF4A9;
    static unsigned long long muTemplateHash = 0x68DB8B4085796014;

    cTkDynamicArray<cGcSettlementJudgementType> maJudgementTypes;
    bool mbSilent;
}
