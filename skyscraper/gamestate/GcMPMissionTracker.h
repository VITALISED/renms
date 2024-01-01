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
#include <toolkit/networking/TkUserIdBase.h>
#include <toolkit/utilities/containers/TkBitArray.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <gamestate/gcinventoryelement.meta.h>

SKYSCRAPER_BEGIN

class cGcMPMissionSelectionHelper
{
  public:
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