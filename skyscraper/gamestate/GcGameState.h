#pragma once

#include <skyscraper.h>
#include <networking/GcRpcCallBase.h>
#include <metadata/gamestate/gcplayerspawnstatedata.meta.h>


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