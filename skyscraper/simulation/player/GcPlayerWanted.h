#pragma once

#include <skyscraper.h>
#include <simulation/player/GcPlayerCommon.h>
#include <simulation/GcWitness.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cGcPlayerWanted
{
    cGcPlayerCommon *mpPlayer;
    cTkVector<cGcWitness> maWitnesses;
    bool mbWitnessing;
    float mfLastWitnessTime;
    float mfLastEvadeTime;
    bool mbIsBeingInvestigated;
    bool mbIsBeingAttackedByRobots;
    cTkVector3 mLastKnownPlayerPos;
    bool mbPlayerHasBeenSeen;
    cTkSmartResHandle mWantedIcon;
    int miWanted;
    float mfWanted;
    float mfLastBadTime;
    bool mbLastPlanetOpenEnvPosValid;
    cTkVector3 mvLastPlanetOpenEnvPos;
    bool mbLastPlanetOpenEnvPosBeforeCrimeValid;
    cTkVector3 mvLastPlanetOpenEnvPosBeforeCrime;
    cTkVector3 mLastDroneCrimePos;
    float mfLastDroneScanTime;
    bool mbDroneScanning;
    float mfLastWantedEscalationTime;
    int miMajorCrimes;
    float mfTimeout;
    float mfWitnessTimer;
    float mfSightTime;
    bool mbInSight;
};

SKYSCRAPER_END