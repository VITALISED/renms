/**
 * @file GcMPMissionTracker.h
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

#include <gamestate/GcDiscoveryManager.h>
#include <networking/GcLobbyId.h>
#include <networking/GcNetworkPlayerEventsHandler.h>
#include <simulation/environment/scanning/GcScanEvenManager.h>
#include <toolkit/networking/TkUserIdBase.h>
#include <toolkit/utilities/containers/TkBitArray.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <gamestate/gcinventoryelement.meta.h>

SKYSCRAPER_BEGIN

class cGcMPMissionSelectionHelper
{
  public:
    struct sGcOfferedMPMissionParticipant;

    void Construct();
    cTkVector<cGcMPMissionSelectionHelper::sGcOfferedMPMissionParticipant> &GetAllParticipants(
        const TkID<128> &lMissionId, const cTkSeed &lSeed);
    cGcScanEventManager::InterstellarSearchResult &GetMissionTargetUA(
        const TkID<128> &lMissionId, const cTkSeed &lMissionSeed, const cTkSeed &lTargetSeed, bool lbIsWeekendEvent);
    bool HasMissionBeenHandedIn(const TkID<128> &lMissionId, const cTkSeed &lSeed);
    bool HasMissionOffer(
        const cTkUserIdBase<cTkFixedString<64, char>> &lParticipant, TkID<128> *lpMissionId, cTkSeed *lpSeed);
    bool HasMissionStarted(const TkID<128> &lMissionId, const cTkSeed &lSeed);
    bool HasMissionStarted(const cTkUserIdBase<cTkFixedString<64, char>> &lParticipant);
    bool IsAvailableToCurrentPlayer(const TkID<128> &lMissionId, const cTkSeed &lSeed);
    void JoinMission(const TkID<128> &lMissionId, const cTkSeed &lSeed, bool lbIsWeekend);
    void LeaveMission();
    void OnMissionHandedIn(const cTkUserIdBase<cTkFixedString<64, char>> &lParticipant);
    void OnMissionStarted(const cTkUserIdBase<cTkFixedString<64, char>> &lParticipant);
    void Ready(bool lbReady, const TkID<128> &lMissionId, const cTkSeed &lSeed);
    void RemoveParticipant(const cTkUserIdBase<cTkFixedString<64, char>> &lParticipant);
    bool StartMission(const TkID<128> &lMissionId, const cTkSeed &lSeed);

    static void RPCOnMissionOfferRescinded(cGcNetworkPlayer *lpLeader);
    static void RPCOnMissionOffered(
        cGcNetworkPlayer *lpPlayer, uint64_t lParticipantUA, bool lbUAIsFallback, uint64_t luiJoinTime,
        bool lbParticipantReady, TkID<128> lMissionId, cTkSeed lSeed, bool lbStarted, bool lbIsWeekend);
    static void RPCOnMissionStartedProper(cGcNetworkPlayer *lpPlayer);
    static void RPCOnParticipantReadyStatus(
        cGcNetworkPlayer *lpPlayer, TkID<128> lMissionId, cTkSeed lSeed, bool lbReady);
    static void RPCOnRemotePlayerLeftMission(cGcNetworkPlayer *lpPlayer);

    struct sGcOfferedMPMissionParticipant
    {
        cTkUserIdBase<cTkFixedString<64, char>> mParticipant;
        uint64_t mParticipantUA;
        bool mbUAIsFallback;
        uint64_t mParticipantJoinTime;
        bool mbReady;
    };

    struct sGcOfferedMPMission
    {
        void AddUniqueParticipant(
            const cTkUserIdBase<cTkFixedString<64, char>> &lParticipant, uint64_t lParticipantUA, bool lbUAIsFallback,
            uint64_t lJoinTime, bool lbParticipantReady);

        cTkSeed mSeed;
        TkID<128> mMissionId;
        bool mbHasStarted;
        bool mbHandedIn;
        bool mbIsWeekendEvent;
        cGcLobbyId mFireteamId;
        cTkVector<cGcMPMissionSelectionHelper::sGcOfferedMPMissionParticipant> maAllParticipants;
    };

    cTkVector<cGcMPMissionSelectionHelper::sGcOfferedMPMission> maAvailableMissions;
    cGcRpcCallBase *MPMO;
    cGcRpcCallBase *MPMR;
    cGcRpcCallBase *MPML;
    cGcRpcCallBase *MPRS;
    cGcRpcCallBase *MPMB;
};

class cGcMPMissionTracker : public INetworkPlayerEventsHandler, public IDiscoveryManagerEventHandler
{
  public:
    struct sGcSyncedMPMissionPlayerData
    {
        cTkUserIdBase<cTkFixedString<64, char>> mPlayer;
        cTkVector<cGcInventoryElement> maInventory;
        robin_hood::detail::Table<
            false, 80, TkID<128>,
            robin_hood::detail::Table<
                false, 80, TkID<128>,
                robin_hood::detail::Table<true, 80, int, int, robin_hood::hash<int, void>, std::equal_to<int>>,
                robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128>>>,
            robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128>>>
            mStats;
        cTkBitArray<unsigned int, true, 32> mDiscoveredCreatures;
        cTkBitArray<unsigned int, true, 32> mDiscoveredMinerals;
        cTkBitArray<unsigned int, true, 32> mDiscoveredFlora;
    };

    cGcMPMissionSelectionHelper mMissionSelectionHelper;
    cTkVector<cGcMPMissionTracker::sGcSyncedMPMissionPlayerData> maPlayerData;
    TkID<128> mMissionId;
    cTkSeed mMissionSeed;
    bool mbMissionRewardsQuicksilver;
    bool mbMissionIsWeekendEvent;
    cGcUniverseAddressData mPreMissionUA;
    uint64_t mNexusExitUA;
    uint8_t meInventoryBeingCounted[4];
    int miElementBeingCounted;
    int miElementRunningTotal;
    float mfTimeUntilNextSync;
    uint64_t mSyncedDiscoveryPlanet;
    cGcDiscoveryData mSyncedPlanetDiscoveryData;
    cGcDiscoverySearch *mpDiscoverySearch;
    cTkVector<eDiscoveryType> maeDiscoveryTypesToRefresh;
    bool mbWantToSyncWhenInventoryIsCounted;
    cGcRpcCallBase *SMPM;
    cGcRpcCallBase *SMPS;
    cGcRpcCallBase *SMPD;
    cGcRpcCallBase *REMO;
    cGcRpcCallBase *OMMS;
    cGcRpcCallBase *PLLM;
};

SKYSCRAPER_END