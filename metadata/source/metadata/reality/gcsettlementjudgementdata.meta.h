#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gameplay/gcsettlementjudgementtype.meta.h>
#include <metadata/reality/gcsettlementjudgementoption.meta.h>
enum eNPCs
{
    ENPCs_None = 0,
    ENPCs_One = 1,
    ENPCs_Two = 2,
}

class cGcSettlementJudgementData
{
    static unsigned long long muNameHash = 0x601CD433A66F7318;
    static unsigned long long muTemplateHash = 0xDED5B44D3B310AC9;

    cGcSettlementJudgementType JudgementType;
    float mfWeighting;
    TkID<256> mHeaderOverride;
    TkID<256> mTitle;
    TkID<256> mNPCTitle;
    TkID<256> mQuestionText;
    TkID<256> mDilemmaText;
    bool mbUseResearchLoc;
    bool mbUseAltResearchLoc;
    cGcSettlementJudgementOption Option1;
    cGcSettlementJudgementOption Option2;
    TkID<128> mNPC1CustomId;
    TkID<128> mNPC2CustomId;
    TkID<256> mNPC1CustomName;
    TkID<256> mNPC2CustomName;
    TkID<128> mNPC1HoloEffect;
    TkID<128> mNPC2HoloEffect;
    eNPCs NPCs;
}
