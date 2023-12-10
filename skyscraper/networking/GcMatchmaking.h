/**
 * @file GcMatchmaking.h
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

#include <networking/GcLobbyId.h>
#include <networking/GcNetworkPlayerEventsHandler.h>
#include <networking/GcNetworkRpcCall.h>
#include <toolkit/core/types/TkID.h>
#include <toolkit/networking/TkUserIdBase.h>

#include <gamestate/gcgamemode.meta.h>

SKYSCRAPER_BEGIN

class cGcMatchmaking : public INetworkPlayerEventsHandler
{
  public:
    enum State
    {
        Invalid,
        Connecting,
        Active,
        Disconnecting,
        Error,
    };

    enum eRpcStatus
    {
        Pending,
        Yes,
        No,
    };

    struct Session
    {
        enum State
        {
            Idle,
            Searching,
            CreatingRoom,
            JoiningRoom,
            InRoom,
            LeavingRoom,
            NumStates,
        };

        cGcNetworkConstants::LobbyType meLobbyType;
        cGcLobbyId mId;
        cGcLobbyId mPendingLobby;
        ePresetGameMode meGameMode;
        unsigned int miSeasonNumber;
        cGcMatchmaking::Session *mOtherSession;
        cGcMatchmaking::Session::State meState;
        cTkUserIdBase<cTkFixedString<64, char>> mOwnerId;
        cGcMatchmaking *mMatchmaking;
        std::function<void __cdecl(cGcMatchmaking::Session::State, cGcMatchmaking::Session::State)>
            mStateChangedCallback;
        RTL_CRITICAL_SECTION mDeferredFunctionLock;
        std::queue<std::function<void __cdecl(void)>> mDeferredFunctions;
    };

    bool mbAmbientMatchmakingEnabled;
    int miJoinableFriendCount;
    int miCrossplayFriendCount;
    int miNativeFriendCount;
    bool mbUpdatedUA;
    bool mbLeavingFullSim;
    bool mbShowNetErrorMsg;
    TkID<256> msNotifyMessage;
    int64_t miMatchmakingVersion;
    long double mfTimeFullSimLobbyPrivilegeChanged;
    long double mfReconnectionTime;
    cGcMatchmaking::State meState;
    std::deque<cGcLobbyId> mBadLobbies;
    cGcRpcCallBase *RAFR;
    cGcRpcCallBase *RTFR;
    cGcRpcCallBase *RPCL;
    cGcRpcCallBase *SLKR;
    cGcRpcCallBase *IFTR;
    cGcRpcCallBase *RIFT;
    uint64_t mUA;
    uint64_t mJoinUA;
    uint64_t mPlayerUA;
    float mfOnHostConnectedWait;
    bool mbQuitingToModeSelect;
    bool mbShowQuitDialog;
    bool mbInviteDialogDisplayed;
    long double mfLastFriendUpdate;
    bool mbIsPrepared;
    std::function<void __cdecl(bool)> mOnQuitFunc;
    std::unordered_map<cTkUserIdBase<cTkFixedString<64, char>>, cGcMatchmaking::eRpcStatus> maAwaitingLobbyPermission;
    std::array<cGcMatchmaking::Session *, 2> mLobbies;
};

SKYSCRAPER_END