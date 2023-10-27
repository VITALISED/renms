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
#include <networking/GcLobbyId.h>
#include <networking/GcNetworkConstants.h>
#include <toolkit/data/TkMetaData.h>
#include <toolkit/utilities/TkString.h>
#include <toolkit/networking/TkUserIdBase.h>
#include <toolkit/networking/TkReplicatedVariablePlayer.h>
#include <toolkit/networking/TkReplicatedVariableArray.h>
#include <metadata/gamestate/gcsettlementstate.meta.h>
#include <metadata/user/gcdifficultysettingsreplicatedstate.meta.h>
#include <metadata/reality/gcinventoryclass.meta.h>

SKYSCRAPER_BEGIN

class cGcNetworkPlayer;

enum ePrivilegeState
{
    EPrivilegeState_Nobody,
    EPrivilegeState_FriendsOnly,
    EPrivilegeState_FriendsOrFireTeamOnly,
    EPrivilegeState_Anybody,
    EPrivilegeState_NumTypes = 4,
};

class cGcNetworkPlayerReplicatedState
{
    cTkReplicatedVariablePlayer<cTkUserIdBase<cTkFixedString<64,char> > > mSessionOwner;
    cTkReplicatedVariablePlayer<unsigned __int64> muiConnectionTimeUTC;
    cTkReplicatedVariablePlayer<unsigned __int64> muiTimeEnteredMatchmakingUA;
    cTkReplicatedVariablePlayer<unsigned char> miPlayerBannerIcon;
    cTkReplicatedVariablePlayer<unsigned char> miPlayerBannerMainColour;
    cTkReplicatedVariablePlayer<unsigned char> miPlayerBannerBackgroundColour;
    cTkReplicatedVariablePlayer<eInventoryClass> mePlayerBannerShipClass;
    cTkReplicatedVariablePlayer<TkID<128> > mJetpackEffect;
    std::array<cTkReplicatedVariablePlayer<unsigned int>, 32> maMaxIndices;
    cTkReplicatedVariablePlayer<cTkFixedString<128,char> > mPlayerName;
    cTkReplicatedVariablePlayer<cGcLobbyId> mOtherLobbyId;
    cTkReplicatedVariablePlayer<unsigned __int64> mUA;
    cTkReplicatedVariablePlayer<unsigned __int64> mSystemUA;
    cTkReplicatedVariablePlayer<TkID<128> > mTitleId;
    cTkReplicatedVariablePlayer<unsigned __int64> mMatchmakingUA;
    cTkReplicatedVariablePlayer<bool> mbBusyInAMenuOrInteraction;
    cTkReplicatedVariablePlayer<bool> mbNeedsSmallLobby;
    cTkReplicatedVariablePlayer<bool> mbCreatingOtherLobby;
    cTkReplicatedVariablePlayer<bool> mbInSmallOtherLobby;
    cTkReplicatedVariablePlayer<cTkFixedString<64,char> > mQueueName;
    cTkReplicatedVariablePlayer<cTkFixedString<64,char> > mTicketId;
    cTkReplicatedVariablePlayer<cTkFixedString<4,char> > mDevice;
    cTkReplicatedVariablePlayer<ePrivilegeState> meFireteamJoinability;
    cTkReplicatedVariablePlayer<cTkFixedString<64,char> > mNativeSessionId;
    cTkReplicatedVariablePlayer<cGcSettlementState> mCurrentSettlement;
    cTkReplicatedVariablePlayer<cGcDifficultySettingsReplicatedState> mDifficultySettings;
    cGcNetworkPlayer *mpOwner;
    cGcNetworkConstants::LobbyType meLobbyType;
    float mfTimeToNextMessage;
    cTkReplicatedVariableArray maReplicatedVariables;
};

SKYSCRAPER_END