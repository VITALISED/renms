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
#include <simulation/galaxy/GcGalaxyAttributeGenerator.h>
#include <simulation/galaxy/GcGalaxyMapUI.h>
#include <simulation/solarsystem/planet/GcPlanetMappingManager.h>
#include <toolkit/data/TkDocumentReaderJSON.h>
#include <toolkit/system/pc/TkStoragePersistent.h>

#include <gamestate/gcdefaultsavedata.meta.h>
#include <gamestate/gcinventorystorebalance.meta.h>

SKYSCRAPER_BEGIN

class cGcGameState
{
  public:
    void CleanupSuitInventory(cGcDefaultSaveData *lpInitData, cGcPlayerStateData &lLoadedPlayerStateData);
    WarpCapabilityResult &ComputeWarpCapability(
        float lfLightyearDistance, bool lbIsCenter, uint64_t lStarDara,
        const cGcGalaxyAttributeGenerator::StarSystemKeyAttributes &);
    float ComputeWarpEngineJumpDistanceInLightyears(ItemLookupType leItemLookupType);
    void Construct();
    void CopyNewElements(
        cTkDynamicArray<TkID<128>> &lStore, const cTkDynamicArray<TkID<128>> &lFrom, bool lbDoNotCopyBannedSeasonItems);
    void Destruct();
    TkID<128> *GetAtlasPathProgress();
    cTkFixedString<128, char> &GetDefaultSaveDataFilename();
    cGcMPMissionTracker *GetMPMissionTracker();
    const cTkMatrix34 &GetPlayerDeathRespawnMatrix();
    const cGcPlayerFleetManager *GetPlayerFleetManager(const cTkUserIdBase<cTkFixedString<64, char>> &lUserId);
    cGcPlayerFleetManager *GetPlayerFleetManagerWritable(
        const cTkUserIdBase<cTkFixedString<64, char>> &lUserId, bool lbAllowConstruction);
    cGcPlayerFleetManager *GetPlayerFleetManagerWritable(int liIndex);
    cGcPlayerFreighterOwnership *GetPlayerFreighterOwnership(const cTkUserIdBase<cTkFixedString<64, char>> &lOwnerId);
    cGcPlayerFreighterOwnership *GetPlayerFreighterOwnership(int liIndex);
    cGcPlayerFreighterOwnership *GetPlayerFreighterOwnershipForCurrentSystem();
    const cTkMatrix34 &GetPlayerSpawnMatrix();
    const cTkMatrix34 &GetShipSpawnMatrix();
    bool LoadFromPersistentStorage(cTkStoragePersistent::Slot leSlot, bool lbNetworkClientLoad);
    bool LoadSpecificSave(GcGameStatePersistence::SpecificSave::Type leSpecificSave);
    bool LoadState();
    bool OnReceiveRemoteByteBeatSong(cGcNetworkPlayer *lpPlayer, cGcByteBeatSong lSong);
    bool OnReceiveRemoteCreatureEgg(cGcNetworkPlayer *lpPlayer, sOwnedCreatureInfo *lEggInfo);
    void OnSaveProgressCompleted(
        bool lbShowMessage, bool lbFullSave, GcGameStatePersistence::SpecificSave::Type leSaveReason);
    bool OverwriteDataFromJSON(
        cGcPlayerStateData &lPlayerStateData, cGcPlayerSpawnStateData &lPlayerSpawnData, cTkDocumentReaderJSON &lJSON,
        uint32_t leOverwriteMask);
    bool Prepare();
    void SaveProgress(
        GcGameStatePersistence::SpecificSave::Type leSaveReason, bool lbShowMessage, bool,
        cGcPlayerSpawnStateData *lpOverrideSavedSpawnState, uint32_t luiSaveMaskFlagsToRemove,
        bool lbForceUpdateDeathSpawn);
    void SendRemoteEgg(
        cGcNetworkPlayer *lpPlayer, cTkUserIdBase<cTkFixedString<64, char>> &lPlayerId,
        cGcInventoryStore *lpFromInventoryStore, const cGcInventoryElement *, cGcInventoryIndex lIndex, int liAmount,
        const cGcProductData *lpEggProduct);
    /**
     * @fn SetFreshStartSpwanData (sic)
     */
    void SetFreshStartSpwanData(cGcDefaultSaveData *lpInitData);
    void Update(float lfTimeStep);
    void UpdateSummary();
    bool WriteStateToJSON(
        cTkStoragePersistent::Slot leSlotToSave, cGcPlayerStateData &lPlayerStateDataToSave,
        cGcPlayerSpawnStateData &lPlayerSpawnDataToSave);

    /**
     * Save Upgrade Calls
     */

    bool UpgradePatch0To1(cGcPlayerStateData &lLoadedPlayerStateData);
    bool UpgradePatch1ToUpdate1(cGcPlayerStateData &lLoadedPlayerStateData);
    bool UpgradeUpdate1ToUpdate1_1(cGcPlayerStateData &lLoadedPlayerStateData);
    bool UpgradeUpdate1_2ToUpdate1_3(cGcPlayerStateData &lLoadedPlayerStateData);
    bool UpgradeUpdate1_33ToUpdate1_35(cGcPlayerStateData &lLoadedPlayerStateData);
    bool UpgradeUpdate1_39ToUpdate1_4Internal(cGcPlayerStateData &lLoadedPlayerStateData);
    bool UpgradeUpdate1_3ToUpdate1_33(cGcPlayerStateData &lLoadedPlayerStateData);
    bool UpgradeUpdate1_4InternalToUpdate1_4(cGcPlayerStateData &lLoadedPlayerStateData);
    bool UpgradeUpdate1_4ToUpdate1_5(cGcPlayerStateData &lLoadedPlayerStateData);
    bool UpgradeUpdate1_5ToUpdate1_51(cGcPlayerStateData &lLoadedPlayerStateData);
    bool UpgradeUpdate1_62ToUpdate1_8(cGcPlayerStateData &lLoadedPlayerStateData);
    bool UpgradeUpdate1_82ToUpdate1_83(const cGcDefaultSaveData *lDefaultData, cGcPlayerStateData &lData);
    bool UpgradeUpdate1_83ToUpdate1_84(cGcPlayerStateData &lLoadedPlayerStateData);
    bool UpgradeUpdate1_84ToUpdate1_85(cGcPlayerStateData &lLoadedPlayerStateData);
    bool UpgradeUpdate1_86ToUpdate1_87(cGcPlayerStateData &lLoadedPlayerStateData);
    bool UpgradeUpdate1_8ToUpdate1_81(cGcPlayerStateData &lLoadedPlayerStateData);
    bool UpgradeUpdate1_91ToUpdate3_30(cGcPlayerStateData &lLoadedPlayerStateData);
    bool UpgradeUpdate3_30ToUpdate3_32(cGcPlayerStateData &lLoadedPlayerStateData);
    bool UpgradeUpdate3_32ToUpdate3_34(cGcPlayerStateData &lLoadedPlayerStateData);
    bool UpgradeUpdate3_34ToUpdate3_35(cGcPlayerStateData &lLoadedPlayerStateData);
    bool UpgradeUpdate3_36ToUpdate3_52(cGcPlayerStateData &lLoadedPlayerStateData);
    bool UpgradeUpdate3_53ToUpdate3_80(cGcPlayerStateData &lLoadedPlayerStateData);
    bool UpgradeUpdate3_80ToUpdate3_81(cGcPlayerStateData &lLoadedPlayerStateData);
    bool UpgradeUpdate3_81ToUpdate3_85(cGcPlayerStateData &lLoadedPlayerStateData);
    bool UpgradeUpdate3_85ToUpdate3_94(cGcPlayerStateData &lLoadedPlayerStateData);
    bool UpgradeUpdate3_94ToUpdate4_00(const cGcDefaultSaveData *lDefaultData, cGcPlayerStateData &lData);
    bool UpgradeUpdate4_00ToUpdate4_04(const cGcDefaultSaveData *lDefaultData, cGcPlayerStateData &lData);
    bool UpgradeUpdate4_04ToUpdate4_05(const cGcDefaultSaveData *lDefaultData, cGcPlayerStateData &lData);
    bool UpgradeUpdate4_05ToUpdate4_09(const cGcDefaultSaveData *lDefaultData, cGcPlayerStateData &lData);

    static void SaveProgressThread(void *lpData);

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

    union {
        struct
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
        };
        uint64_t muCurrentSavePlaytime;
    };

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