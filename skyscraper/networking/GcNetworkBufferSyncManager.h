/**
 * @file GcNetworkBufferSyncManager.h
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

#include <networking/GcNetworkPlayerEventsHandler.h>
#include <networking/GcNetworkSynchronisedBuffer.h>
#include <networking/messages/GcNetworkSyncMessage.h>
#include <toolkit/networking/TkUserIdBase.h>
#include <toolkit/utilities/containers/TkDeque.h>
#include <toolkit/utilities/random/TkPersonalRNG.h>

SKYSCRAPER_BEGIN

class cGcNetworkBufferSyncManager : public INetworkPlayerEventsHandler
{
  public:
    struct sPlayerHandle
    {
        cGcNetworkPlayer *mpPlayer;
        float mfReceivedMessageScore;
    };

    struct sPendingRequest
    {
        cGcNetworkSynchronisedBuffer *mpBuffer;
        std::shared_ptr<cGcNetworkSyncMessage> mpMessage;
        cTkUserIdBase<cTkFixedString<64, char>> mPlayerId;
    };

    uint8_t meHashMessageType[1];
    uint8_t meSyncMessageType[1];
    float mfHashMessageInterval;
    float mfSyncMessageInterval;
    float mfHashMessageTimer;
    float mfSyncMessageTimer;
    float mfBufferSyncBackOffTimer;
    cGcNetworkBufferSyncManager::sPlayerHandle mPlayers[31];
    cTkPersonalRNG mRNG;
    cTkDeque<cGcNetworkBufferSyncManager::sPendingRequest> mPendingSyncRequests;
};

SKYSCRAPER_END