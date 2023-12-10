/**
 * @file GcNetworkManager.h
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
#include <networking/GcMonumentManager.h>
#include <networking/GcNetworkBandwidthMonitor.h>
#include <networking/GcNetworkBaseBuildingManager.h>
#include <networking/GcNetworkBaseImageManager.h>
#include <networking/GcNetworkCreatureManager.h>
#include <networking/GcNetworkIdManager.h>
#include <networking/GcNetworkInteractionBufferManager.h>
#include <networking/GcNetworkInteractionManager.h>
#include <networking/GcNetworkLockManager.h>
#include <networking/GcNetworkMessageManager.h>
#include <networking/GcNetworkPlayerManager.h>
#include <networking/GcNetworkPrivilegesManager.h>
#include <networking/GcNetworkReplicatedEntityManager.h>
#include <networking/GcNetworkRpcManager.h>
#include <networking/GcNetworkSynchronizedClock.h>
#include <networking/GcNetworkTerrainEditsManager.h>
#include <networking/GcTextChatManager.h>
#include <networking/GcVoiceChat.h>

SKYSCRAPER_BEGIN

class cGcNetworkManager
{
  public:
    cGcConnection *mpConnection;
    cGcNetworkMessageManager mMessageManager;
    cGcNetworkPlayerManager mPlayerManager;
    cGcMatchmaking *mpMatchmaking;
    cGcNetworkInteractionManager mInteractionManager;
    cGcMonumentManager mMonumentManager;
    cGcVoiceChat *mpVoiceChat;
    cGcTextChatManager mTextChatManager;
    cGcNetworkTerrainEditsManager mTerrainEditsManager;
    cGcNetworkBaseBuildingManager mBaseBuildingManager;
    cGcNetworkReplicatedEntityManager mReplicatedEntityManager;
    cGcNetworkSynchronizedClock mNetworkSychronizedClock;
    cGcNetworkRpcManager mRpcManager;
    cGcNetworkInteractionBufferManager mInteractionBufferManager;
    cGcNetworkIdManager mNetworkIdManager;
    cGcNetworkCreatureManager mCreatureManager;
    cGcNetworkLockManager mNetworkLockManager;
    cGcNetworkBandwidthMonitor mBandwidthMonitor;
    cGcNetworkPrivilegesManager mPrivilegesManager;
    cGcNetworkBaseImageManager mBaseImageManager;
    bool mbPrepared;
};

SKYSCRAPER_END