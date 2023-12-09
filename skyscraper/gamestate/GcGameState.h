/**
 * @file GcGameState.h
 * @author VITALISED & Contributors
 * @since 2023-12-08
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

#include <basebuilding/GcSettlementStateManager.h>
#include <gamestate/GcCloudSaveManager.h>
#include <gamestate/GcDifficultySettings.h>
#include <gamestate/GcDiscoveryManager.h>
#include <gamestate/GcEntitlementManager.h>
#include <gamestate/GcGameKnowledge.h>
#include <gamestate/GcGameStatePersistence.h>
#include <gamestate/GcGraveManager.h>
#include <gamestate/GcMPMissionTracker.h>
#include <gamestate/GcMsgBeaconManager.h>
#include <gamestate/GcPersistentInteractionsManager.h>
#include <gamestate/GcPlayerCreatureOwnership.h>
#include <gamestate/GcPlayerDiscoveryHelper.h>
#include <gamestate/GcPlayerFleetManager.h>
#include <gamestate/GcPlayerFreighterOwnership.h>
#include <gamestate/GcPlayerMultitoolOwnership.h>
#include <gamestate/GcPlayerShipOwnership.h>
#include <gamestate/GcPlayerSquadronOwnership.h>
#include <gamestate/GcPlayerState.h>
#include <gamestate/GcPlayerVehicleOwnership.h>
#include <gamestate/GcStatsManager.h>
#include <gamestate/GcTelemetryManager.h>
#include <gamestate/GcUserSeenItemsState.h>
#include <gamestate/GcUserSettings.h>
#include <gamestate/GcWonderManager.h>
#include <networking/GcNetworkRpcCall.h>
#include <online/GcRichPresence.h>
#include <simulation/solarsystem/planet/GcPlanetMappingManager.h>

#include <gamestate/gcinventorystorebalance.meta.h>

SKYSCRAPER_BEGIN

class cGcGameState
{
  public:
    enum LastSaveResult
    {
        Unknown,
        Successful,
        Failed,
    };

    struct SaveThreadData
    {
        cGcGameState *mpGameState;
        GcGameStatePersistence::SpecificSave::Type meSaveReason;
        bool mbShowMessage;
        bool mbFullSave;
        cGcPlayerStateData mPlayerStateDataToSave;
        unsigned int muiSaveMaskFlagsToRemove;
    };

    cGcRpcCallBase *RRIT;
    cGcRpcCallBase *RRCE;
    cGcRpcCallBase *RRBB;
    TkHandle mGameStateGroupNode;
    cGcPlayerState mPlayerState;
    cGcPlayerSpawnStateData mSavedSpawnState;
    cGcPlayerShipOwnership mPlayerShipOwnership;
    cGcPlayerVehicleOwnership mPlayerVehicleOwnership;
    cGcPlayerCreatureOwnership mPlayerCreatureOwnership;
    cGcPlayerMultitoolOwnership mPlayerMultitoolOwnership;
    cGcPlayerFreighterOwnership mPlayerFreighterOwnership[4];
    cGcPlayerFleetManager mPlayerFleetManager[4];
    cGcPlayerSquadronOwnership mPlayerSquadronOwnership;
    cGcGameKnowledge mGameKnowledge;
    cGcDiscoveryManager mDiscoveryManager;
    cGcWonderManager mWonderManager;
    cGcGraveManager mGraveManager;
    cGcMsgBeaconManager mMsgBeaconManager;
    cGcPlayerDiscoveryHelper mPlayerDiscoveryHelper;
    cGcStatsManager mStatsManager;
    cGcTelemetryManager mTelemetryManager;
    cGcUserSettings mUserSettings;
    cGcUserSeenItemsState mUserSeenItemsState;
    cGcDifficultySettings mDifficultySettings;
    cGcMPMissionTracker mMPMissionTracker;
    cGcEntitlementManager mEntitlementManager;
    cGcPlanetMappingManager mPlanetMappingManager;
    cGcSettlementStateManager mSettlementStateManager;
    float mfSaveStateDisplayTime;
    cGcGameState::LastSaveResult meSaveStateLastResult;
    uint64_t miLastSaveOperationTimestamp;
    bool mbRestoreRequested;
    GcGameStatePersistence::SpecificSave::Type meRestoreType;
    cGcPersistentInteractionsManager mSavedInteractionsManager;
    bool mbPendingProgressWrite;
    bool mbDelayedMicroSave;
    bool mbPendingDifficultySave;
    bool mbRestartAllInactiveSeasonalMissions;
    GcGameStatePersistence::eSaveVersion mePatchVersion;
    bool mbPatchAffectsLoading;
    cTkSmartResHandle mWarpTunnelRes;
    cTkSmartResHandle mTeleportTunnelRes;
    cTkSmartResHandle mBlackHoleTunnelRes;
    cTkSmartResHandle mPortalTunnelRes;
    cTkSmartResHandle mPlaceMarkerRes;
    cGcInventoryStoreBalance mInventoryStoreBalance;
    cGcRichPresence mPlayerRichPresence;
    bool mbSingleMultiPositionInSync;
    bool mbSaveCompletedThisFrame;
    float mfStartedSaveTime;
    cGcGameState::SaveThreadData *mpSaveThreadData;
    unsigned int mSaveThreadId;
    void *mSaveRequestNewEvent;
    void *mSaveThreadExitedEvent;
    bool mbSaveThreadRequestExit;
    bool mbPendingAsyncSaveRequest;
    GcGameStatePersistence::SpecificSave::Type mePendingAsyncSaveRequestReason;
    bool mbPendingAsyncSaveRequestShowMessage;
    float mfUpgradeMessageFilterTimer;
    bool mbNetworkClientLoad;
    bool mbLastDeathTriggeredSlotSelect;
    bool mbWaitingForSeasonalGameMode;
    cGcCloudSaveManager mCloudSaveManager;
};

SKYSCRAPER_END