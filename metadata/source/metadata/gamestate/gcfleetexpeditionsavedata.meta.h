#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcexpeditioncategory.meta.h>
#include <metadata/reality/gcexpeditionduration.meta.h>
#include <metadata/gamestate/gcexpeditioneventsavedata.meta.h>

class cGcFleetExpeditionSaveData
{
    static unsigned long long muNameHash = 0x1CD96DF6BD8E239C;
    static unsigned long long muTemplateHash = 0x1389AA9BBA57EE88;

    cTkSeed mSeed;
    unsigned long long mui64UA;
    cTkVector3 mSpawnPosition;
    cTkVector3 mTerminalPosition;
    float mfSpeedMultiplier;
    cTkDynamicArray<TkID<128>> maPowerups;
    cTkFixedString<256,char> macCustomName;
    TkID<128> mInterventionEventMissionID;
    unsigned long long mui64StartTime;
    unsigned long long mui64PauseTime;
    unsigned long long mui64TimeOfLastUAChange;
    int miNextEventToTrigger;
    cGcExpeditionCategory ExpeditionCategory;
    cGcExpeditionDuration ExpeditionDuration;
    cTkDynamicArray<int> maActiveFrigateIndices;
    cTkDynamicArray<int> maDamagedFrigateIndices;
    cTkDynamicArray<int> maDestroyedFrigateIndices;
    cTkDynamicArray<int> maAllFrigateIndices;
    int miNumberOfSuccessfulEventsThisExpedition;
    int miNumberOfFailedEventsThisExpedition;
    cTkDynamicArray<cGcExpeditionEventSaveData> maEvents;
    bool mbInterventionPhoneCallActivated;
}
