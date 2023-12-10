/**
 * @file GcVoiceChat.h
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

SKYSCRAPER_BEGIN

class cGcVoiceChat : public INetworkPlayerEventsHandler
{
  public:
    bool mbMultiplayerActive;
    bool mbRunning;
    int miPlayers;

    virtual void OnMultiplayerSessionStarting(cGcNetworkConstants::LobbyType);
    virtual void OnMultiplayerSessionFinished(cGcNetworkConstants::LobbyType);
    virtual void OnNetworkPlayerStateEvent(cGcNetworkPlayer *, eGcNetworkPlayerStateEvent);
    virtual void OnConstruct();
    virtual void OnDestruct();
    virtual bool OnStartVoice();
    virtual void OnStopVoice();
    virtual void OnUpdate(float);
    virtual void OnPlayerJoined(cGcNetworkPlayer *);
    virtual void OnPlayerLeaving(cGcNetworkPlayer *);
    virtual void OnMute(const cGcNetworkPlayer *, bool);
    virtual bool IsMuted(const cGcNetworkPlayer *);
    virtual bool CanTalk(const cGcNetworkPlayer *);
    virtual bool IsTalking(const cGcNetworkPlayer *);
};

SKYSCRAPER_END