/**
 * @file GcNetworkPlayer.h
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

#include <networking/GcNetworkAddress.h>
#include <networking/GcNetworkConstants.h>
#include <networking/GcNetworkPlayerReplicatedState.h>
#include <networking/messages/GcNetworkMessage.h>
#include <simulation/player/GcPlayerCommon.h>

SKYSCRAPER_BEGIN

class cGcNetworkPlayer : public cGcPlayerCommon
{
  public:
    enum ePlayerStatus
    {
        Invalid,
        PendingConnection,
        Connected,
        PendingRelease,
    };

    class IVoiceConnection
    {
        virtual unsigned int GetOutgoingVoiceData(uint8_t *, unsigned int, bool *);
        virtual void SetIncomingVoiceData(uint8_t *, unsigned int, const bool);
    };

    cTkFixedString<64, char> mName;
    cGcNetworkConstants::PlayerMovementState mePlayerMovementState;
    EnvironmentLocation::Enum meEnvironmentLocation;
    bool mbIsInPlayerFreighter;
    uint64_t mCurrentUA;
    cGcNetworkConstants::LobbyType mePlayerType;
    cGcNetworkPlayerReplicatedState mReplicatedState;
    cGcNetworkPlayer::IVoiceConnection *mpVoiceConnection;
    std::shared_ptr<cGcNetworkAddress> mNetworkAddress;
    cTkFixedString<3, char> mPlatform;
    cGcNetworkPlayer::ePlayerStatus meStatus;
    cGcNetworkPlayer::ePlayerStatus mePendingStatus;
    float mfTimeSinceLastUpdateSent;
    cTkUserIdBase<cTkFixedString<64, char>> mPlayerId;
    cTkUserIdBase<cTkFixedString<64, char>> mAccountId;
    bool mbVoiceChatSuppressed;
    bool mbFriendOfLocal;
    cTkFixedString<64, char> mPlatformId;
    std::list<std::shared_ptr<cGcNetworkMessage>> mPendingMessages;

    ~cGcNetworkPlayer() { EMPTY_CALL_DESTRUCTOR(); }
};

SKYSCRAPER_END