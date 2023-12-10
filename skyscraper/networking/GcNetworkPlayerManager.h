/**
 * @file GcNetworkPlayerManager.h
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

#include <networking/GcConnection.h>
#include <networking/GcMatchmaking.h>
#include <networking/GcNetworkPlayerFireteam.h>
#include <networking/GcNetworkPlayerFullSim.h>
#include <networking/GcNetworkPlayerReplicatedState.h>
#include <networking/GcNetworkRpcCall.h>
#include <toolkit/networking/TkUserIdBase.h>
#include <toolkit/resources/TkResource.h>
#include <toolkit/system/thread/TkSpinMutex.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cGcNetworkPlayer;

class cGcNetworkPlayerManager
{
  public:
    class cGcNetworkPlayerArrayBase
    {
      public:
        robin_hood::detail::Table<
            false, 80, cTkUserIdBase<cTkFixedString<64, char>>, std::shared_ptr<cGcNetworkAddress>,
            robin_hood::hash<cTkUserIdBase<cTkFixedString<64, char>>, void>,
            std::equal_to<cTkUserIdBase<cTkFixedString<64, char>>>>
            maPendingGamePlayNetworkConnections;

        virtual ~cGcNetworkPlayerArrayBase();
        virtual void Construct();
        virtual void Update(float);
        virtual cGcNetworkPlayerReplicatedState *GetReplicatedState();
        virtual bool FreePlayer(cGcNetworkPlayer *);
    };

    template <typename T, int Length, typename U>
    class cGcNetworkPlayerArray : public cGcNetworkPlayerArrayBase
    {
      public:
        class std::array<std::unique_ptr<T>, Length> maNetworkPlayers;
        U mReplicatedPlayerState;

        virtual ~cGcNetworkPlayerArray() { EMPTY_CALL_DESTRUCTOR(); };
    };

    struct sGcEventHandlerData
    {
        INetworkPlayerEventsHandler *mpEventHandler;
        bool mbFullSimOnly;
    };

    class cGcPlayerEvent
    {
      public:
        std::shared_ptr<cGcNetworkAddress> mpAddress;
        cTkUserIdBase<cTkFixedString<64, char>> mMemberID;
        cTkUserIdBase<cTkFixedString<64, char>> mAccountID;
        cTkFixedString<64, char> msPlayerName;
        cGcNetworkConstants::LobbyType meLobbyType;
        cTkFixedString<3, char> mPlatform;
        cTkFixedString<64, char> mPlatformId;
    };

    union {
        cTkUserIdBase<cTkFixedString<64, char>> SelfHostPlayerId;
        struct
        {
            cGcRpcCallBase *PLHS;
            cGcRpcCallBase *PLWM;
            cGcRpcCallBase *PLWR;
            cGcRpcCallBase *PLWF;
            cGcRpcCallBase *PLRS;
            cGcRpcCallBase *PEFF;
            cGcRpcCallBase *PPFX;
            cGcRpcCallBase *PRDL;
        };
    };

    cGcRpcCallBase *PLTD;
    cGcRpcCallBase *PLNA;
    cGcRpcCallBase *PLCF;
    cGcRpcCallBase *PTCH;
    cGcRpcCallBase *PLSE;
    cGcRpcCallBase *PLJP;
    cGcRpcCallBase *PLSL;
    cGcRpcCallBase *PTSC;
    cGcRpcCallBase *PLTF;
    cGcNetworkPlayerArray<cGcNetworkPlayerFullSim, 32, cGcNetworkPlayerReplicatedState> maNetworkPlayers;
    cGcNetworkPlayerArray<cGcNetworkPlayerFireteam, 4, cGcNetworkPlayerReplicatedState> maFireteamNetworkPlayers;
    std::array<cGcNetworkPlayerArrayBase *, 2> maPlayerCollections;
    cTkSmartResHandle mNetworkPlayerRes;
    cTkVector<cGcNetworkPlayerManager::sGcEventHandlerData> mapPlayerEventSubscribers;
    cTkDeque<cGcNetworkPlayerManager::cGcPlayerEvent> maPlayerEventQueue;
    cTkSpinMutex mQueueMutex;
    uint8_t meLocalPlayerState[1];
    uint8_t mePendingLocalPlayerState[1];
    float mfTimeSinceLastVoiceSent;
    float mfSendUpdateTimer;
    cGcMatchmaking *mpMatchmaking;
    cGcConnection *mpConnection;
};

SKYSCRAPER_END