#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcexpeditioncategory.meta.h>
#include <metadata/reality/gcnumberedtextlist.meta.h>

class cGcExpeditionInterventionEventData
{
    static unsigned long long muNameHash = 0x1920DA0CB7B61986;
    static unsigned long long muTemplateHash = 0x243622A7FB6C6BCB;

    TkID<256> mID;
    int miSelectionWeight;
    cGcExpeditionCategory ExpeditionCategory;
    cGcNumberedTextList InteractionID;
    cTkFixedString<32,char> macSuccessLogEntry;
    cTkFixedString<32,char> macAvoidanceLogEntry;
    cTkFixedString<32,char> macFailureLogEntry;
    TkID<128> mSuccessReward;
    TkID<128> mFailureReward;
    int miFailureDamageChance;
}
