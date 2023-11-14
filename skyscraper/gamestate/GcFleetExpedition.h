#pragma once

#include <skyscraper.h>

#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cGcFleetExpedition
{
    cTkVector<cGcFleetFrigate *> mapAllFrigates;
    cTkVector<cGcFleetFrigate *> mapActiveFrigates;
    cTkVector<cGcFleetFrigate *> mapDamagedFrigates;
    cTkVector<cGcFleetFrigate *> mapDestroyedFrigates;
    cTkVector<cGcExpeditionEventResult> maExpeditionEventResults;
    TkID<128> maPowerups[3];
    cTkSeed mSeed;
    TkID<128> mInterventionEventMissionID;
    unsigned __int64 mu64ExpeditionStartTime;
    unsigned __int64 mu64ExpeditionPauseTime;
    unsigned __int64 mu64TimeOfLastUAChange;
    int miNextEventToTrigger;
    int miChosenNumberOfEvents;
    eExpeditionCategory meExpeditionCategory;
    float mfSpeedMultiplier;
    unsigned __int64 mUA;
    cTkVector3 mSpawnPosition;
    cTkVector3 mTerminalPosition;
    int miNumberOfSuccessfulEventsThisExpedition;
    int miNumberOfFailedEventsThisExpedition;
    bool mbWaitingForCommunicatorResponse;
    bool mbLoadedEventResults;
    bool mbHaveGivenRewards;
};

SKYSCRAPER_END