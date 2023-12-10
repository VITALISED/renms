/**
 * @file GcFleetExpedition.h
 * @author VITALISED & Contributors
 * @since 2023-12-09
 *
 * Copyright (C) 2023  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <skyscraper.h>

#include <toolkit/utilities/containers/TkVector.h>

#include <reality/gcrewardtableitem.meta.h>
#include <simulation/gcexpeditioneventdata.meta.h>
#include <simulation/gcexpeditioninterventioneventdata.meta.h>

SKYSCRAPER_BEGIN

class cGcFleetFrigate;

class cGcDamageResponse
{
  public:
    enum eFrigateDamageResponse
    {
        EFrigateDamageResponse_Ignored,
        EFrigateDamageResponse_Destroyed,
        EFrigateDamageResponse_Continued,
        EFrigateDamageResponse_Recalled,
        EFrigateDamageResponse_RepairedByAnotherFrigate,
        EFrigateDamageResponse_NumTypes,
    };

    cTkSeed mDamagedFrigateSeed;
    cTkSeed mRepairingFrigateSeed;
    eFrigateDamageResponse meDamageResponse;
};

class cGcExpeditionEventResult
{
  public:
    cTkVector<cGcDamageResponse> maAffectedFrigates;
    cTkVector<cGcRewardTableItem const *> mapRewards;
    const cGcExpeditionEventData *mpEventData;
    const cGcExpeditionInterventionEventData *mpInterventionEventData;
    bool mbIsWhaleEvent;
    cTkFixedString<64, char> mChosenDescription;
    TkID<128> mRewardItemID;
    cTkSeed mSeed;
    uint64_t mUA;
    int miNumberOfDamagedFrigates;
    int miRewardAmount;
    bool mbSuccess;
    bool mbIsInterventionEvent;
    bool mbAvoidedIntervention;
    bool mbDescriptionOverridden;
    TkID<128> mOverrideRewardId;
};

class cGcFleetExpedition
{
  public:
    cTkVector<cGcFleetFrigate *> mapAllFrigates;
    cTkVector<cGcFleetFrigate *> mapActiveFrigates;
    cTkVector<cGcFleetFrigate *> mapDamagedFrigates;
    cTkVector<cGcFleetFrigate *> mapDestroyedFrigates;
    cTkVector<cGcExpeditionEventResult> maExpeditionEventResults;
    TkID<128> maPowerups[3];
    cTkSeed mSeed;
    TkID<128> mInterventionEventMissionID;
    uint64_t mu64ExpeditionStartTime;
    uint64_t mu64ExpeditionPauseTime;
    uint64_t mu64TimeOfLastUAChange;
    int miNextEventToTrigger;
    int miChosenNumberOfEvents;
    eExpeditionCategory meExpeditionCategory;
    float mfSpeedMultiplier;
    uint64_t mUA;
    cTkVector3 mSpawnPosition;
    cTkVector3 mTerminalPosition;
    int miNumberOfSuccessfulEventsThisExpedition;
    int miNumberOfFailedEventsThisExpedition;
    bool mbWaitingForCommunicatorResponse;
    bool mbLoadedEventResults;
    bool mbHaveGivenRewards;
};

SKYSCRAPER_END