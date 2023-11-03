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
#include <atlas/WinHttpTask.h>
#include <atlas/GcAtlasBrokerAuth.h>
#include <toolkit/utilities/TkString.h>
#include <toolkit/networking/TkUserIdBase.h>
#include <gamestate/EnvironmentLocation.h>
#include <simulation/player/GcPlayerCommon.h>
#include <networking/GcNetworkConstants.h>
#include <networking/GcNetworkMessage.h>
#include <networking/GcNetworkAddress.h>
#include <networking/GcNetworkPlayerReplicatedState.h>

SKYSCRAPER_BEGIN

class cGcNetworkPlayer : public cGcPlayerCommon
{
    typedef WinHttpTask::State::Enum ePlayerStatus;

    class IVoiceConnection
    {
        virtual unsigned int GetOutgoingVoiceData(unsigned __int8 *, unsigned int, bool *);
        virtual void SetIncomingVoiceData(unsigned __int8 *, unsigned int, const bool);
    };

    cTkFixedString<64,char> mName;
    cGcNetworkConstants::PlayerMovementState mePlayerMovementState;
    EnvironmentLocation::Enum meEnvironmentLocation;
    bool mbIsInPlayerFreighter;
    unsigned __int64 mCurrentUA;
    cGcNetworkConstants::LobbyType mePlayerType;
    cGcNetworkPlayerReplicatedState mReplicatedState;
    cGcNetworkPlayer::IVoiceConnection *mpVoiceConnection;
    std::shared_ptr<cGcNetworkAddress> mNetworkAddress;
    cTkFixedString<3,char> mPlatform;
    cGcNetworkPlayer::ePlayerStatus meStatus;
    cGcNetworkPlayer::ePlayerStatus mePendingStatus;
    float mfTimeSinceLastUpdateSent;
    cTkUserIdBase<cTkFixedString<64,char> > mPlayerId;
    cTkUserIdBase<cTkFixedString<64,char> > mAccountId;
    bool mbVoiceChatSuppressed;
    bool mbFriendOfLocal;
    cTkFixedString<64,char> mPlatformId;
    std::list<std::shared_ptr<cGcNetworkMessage>> mPendingMessages;
};

SKYSCRAPER_END