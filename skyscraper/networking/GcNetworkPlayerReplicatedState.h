/**
 * @file GcNetworkPlayerReplicatedState.h
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
#include <networking/GcNetworkConstants.h>
#include <toolkit/core/types/TkID.h>
#include <toolkit/networking/TkReplicatedVariableArray.h>
#include <toolkit/networking/TkReplicatedVariablePlayer.h>

#include <gamestate/gcsettlementstate.meta.h>
#include <user/gcdifficultysettingsreplicatedstate.meta.h>

SKYSCRAPER_BEGIN

class cGcNetworkPlayerReplicatedState
{
  public:
    union {
        struct
        {
            cTkReplicatedVariablePlayer<cTkUserIdBase<cTkFixedString<64, char>>> mSessionOwner;
            cTkReplicatedVariablePlayer<uint64_t> muiConnectionTimeUTC;
            cTkReplicatedVariablePlayer<uint64_t> muiTimeEnteredMatchmakingUA;
            cTkReplicatedVariablePlayer<unsigned char> miPlayerBannerIcon;
            cTkReplicatedVariablePlayer<unsigned char> miPlayerBannerMainColour;
            cTkReplicatedVariablePlayer<unsigned char> miPlayerBannerBackgroundColour;
            cTkReplicatedVariablePlayer<enum eInventoryClass> mePlayerBannerShipClass;
            cTkReplicatedVariablePlayer<TkID<128>> mJetpackEffect;
            std::array<cTkReplicatedVariablePlayer<unsigned int>, 32> maMaxIndices;
            cTkReplicatedVariablePlayer<cTkFixedString<128, char>> mPlayerName;
            cTkReplicatedVariablePlayer<cGcLobbyId> mOtherLobbyId;
            cTkReplicatedVariablePlayer<uint64_t> mUA;
            cTkReplicatedVariablePlayer<uint64_t> mSystemUA;
            cTkReplicatedVariablePlayer<TkID<128>> mTitleId;
            cTkReplicatedVariablePlayer<uint64_t> mMatchmakingUA;
            cTkReplicatedVariablePlayer<bool> mbBusyInAMenuOrInteraction;
            cTkReplicatedVariablePlayer<bool> mbNeedsSmallLobby;
            cTkReplicatedVariablePlayer<bool> mbCreatingOtherLobby;
            cTkReplicatedVariablePlayer<bool> mbInSmallOtherLobby;
            cTkReplicatedVariablePlayer<cTkFixedString<64, char>> mQueueName;
            cTkReplicatedVariablePlayer<cTkFixedString<64, char>> mTicketId;
            cTkReplicatedVariablePlayer<cTkFixedString<4, char>> mDevice;
            cTkReplicatedVariablePlayer<enum ePrivilegeState> meFireteamJoinability;
            cTkReplicatedVariablePlayer<cTkFixedString<64, char>> mNativeSessionId;
            cTkReplicatedVariablePlayer<cGcSettlementState> mCurrentSettlement;
            cTkReplicatedVariablePlayer<cGcDifficultySettingsReplicatedState> mDifficultySettings;
            cGcNetworkPlayer *mpOwner;
            cGcNetworkConstants::LobbyType meLobbyType;
            float mfTimeToNextMessage;
        };
        const float mfTimeBetweenMessages;
    };
    cTkReplicatedVariableArray maReplicatedVariables;

    ~cGcNetworkPlayerReplicatedState() { EMPTY_CALL_DESTRUCTOR(); }
};

SKYSCRAPER_END