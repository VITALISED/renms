/**
 * @file GcPlayerFleetManager.h
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

#include <gamestate/GcFleetExpedition.h>
#include <gamestate/GcFleetFrigate.h>
#include <networking/GcNetworkPlayerEventsHandler.h>
#include <toolkit/networking/TkUserIdBase.h>
#include <toolkit/utilities/containers/TkClassPool.h>

#include <simulation/player/gcplayercommunicatormessage.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerFleetManager;

class cGcFrigateOccupationTracker
{
  public:
    cTkVector<cGcFleetFrigate *> mapOccupiedFrigates;
    cTkVector<cTkUserIdBase<cTkFixedString<64, char>>> maOccupyingPlayerIds;
    const cGcPlayerFleetManager *mFleetManager;
    int miOccupationCounter;
};

class cGcPurchasableFrigateTracker
{
  public:
    TkHandle mContact;
    const cGcPlayerFleetManager *mOwner;
    cTkVector<TkHandle> maUnavailableFrigates;
};

class cGcPlayerFleetManager : public INetworkPlayerEventsHandler
{
  public:
    cGcPlayerCommunicatorMessage mDamageCommunicatorMessage;
    cGcPlayerCommunicatorMessage mInterventionCommunicatorMessage;
    std::array<cGcFleetFrigate, 30> maFrigatePool;
    std::array<cGcFleetExpedition, 20> maExpeditionPool;
    cTkVector<cTkVector3> maFrigateSpawnLocations;
    cTkVector<cGcFleetExpedition> maAvailableExpeditions;
    cTkVector<uint64_t> mau64ExpeditionSeedsSelectedToday;
    cTkVector<cGcFleetFrigate *> mapFrigates;
    cTkVector<cGcFleetFrigate *> mapFrigatesWaitingForAIShipSpawn;
    cTkVector<cGcFleetExpedition *> mapExpeditions;
    cTkVector<cGcFleetExpedition *> mapActiveExpeditions;
    cGcFrigateOccupationTracker mFrigateOccupationTracker;
    cGcPurchasableFrigateTracker mPurchasableFrigateTracker;
    cTkClassPoolHandle mAIShipSquadHandle;
    cGcFleetFrigate *mpFrigateToRemoveFromFleet;
    cGcFleetExpedition *mpExpeditionToStart;
    uint64_t mu64ExpeditionToStartStartTime;
    cTkVector<cGcFleetFrigate *> mapFrigatesToDespawn;
    cTkSeed mSeed;
    cTkSeed mLastKnownUASeed;
    uint64_t mu64LastKnownDay;
    cGcFleetExpedition *mpInterventionExpedition;
    TkID<256> mInterventionEventDialog;
    float mfTimeUntilPlayerAlertedToInterventionEvent;
    float mfTimeUntilPlayerAlertedToDamagedFrigates;
    cTkVector<cTkSmartResHandle> maCachedFrigateInteriorResources;
    cTkClassPoolHandle mInvalidAsteroidArea;
    cTkUserIdBase<cTkFixedString<64, char>> mOwnerId;
    float mfDelayUntilDespawnedFleetRespawns;
    bool mbPlayerAlertedToInterventionEvent;
    bool mbPlayerAlertedToDamagedFrigates;
    bool mbRequestShowInterventionInteraction;
    bool mbShouldAlertPlayerToPurchasableFrigates;
    bool mbPlayerHasSeenTodaysExpeditions;
};

SKYSCRAPER_END