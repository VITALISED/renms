#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcMissionSequenceCompleteSettlementJudgement
{
    static unsigned long long muNameHash = 0x35FB9E28116A4F2A;
    static unsigned long long muTemplateHash = 0xEC55DBADBB2207F2;

    cTkFixedArray<cGcJudgementMessageOptions> maMessageOptions;
    cGcJudgementMessageOptions MessageNoOffice;
    cTkFixedString<128,char> macDebugText;
}
