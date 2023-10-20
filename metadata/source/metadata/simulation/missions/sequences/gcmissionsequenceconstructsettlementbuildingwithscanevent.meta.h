#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceConstructSettlementBuildingWithScanEvent
{
    static unsigned long long muNameHash = 0x9DC327D85EF1681E;
    static unsigned long long muTemplateHash = 0x994472AEF21AC74F;

    cTkFixedString<128,char> macMessage;
    cTkFixedString<128,char> macMessageWhileBuilding;
    cTkFixedString<128,char> macMessageWithItemsGathered;
    cTkFixedString<128,char> macMessageWhenDistant;
    TkID<256> mScanEvent;
    float mfForceCompleteSequenceAtStagePercentage;
    cTkFixedString<128,char> macDebugText;
}
