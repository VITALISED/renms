/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <skyscraper.h>
#include <gamestate/GcPlayerState.h>
#include <gamestate/GcPlayerShipOwnership.h>
#include <gamestate/GcPlayerVehicleOwnership.h>
#include <networking/GcRpcCallBase.h>
#include <metadata/source/gamestate/gcplayerspawnstatedata.meta.h>


SKYSCRAPER_BEGIN

class cGcGameState
{
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
    unsigned char meSaveStateLastResult[4];
     __int64 miLastSaveOperationTimestamp;
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