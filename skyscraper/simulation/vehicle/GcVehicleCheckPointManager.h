/**
 * @file GcVehicleCheckPointManager.h
 * @author VITALISED & Contributors
 * @since 2023-12-07
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

#include <basebuilding/GcBaseBuildingManagerTypes.h>
#include <networking/GcNetworkRpcCall.h>
#include <toolkit/attachments/TkAttachment.h>

#include <simulation/vehicle/gcvehiclecheckpointcomponentdata.meta.h>

SKYSCRAPER_BEGIN

struct MultiplayerSplits
{
    cTkUserIdBase<cTkFixedString<64, char>> mPlayerID;
    float mfTime;
};

struct RaceSection
{
    sBaseObjectHandle mBaseObjectHandle;
    float mfTime;
    cTkVector<MultiplayerSplits> maOtherPlayerTimes;
};

class cGcVehicleCheckpointManager
{
  public:
    enum eRaceMessage
    {
        ERaceMessage_None,
        ERaceMessage_NearbyOnFoot,
        ERaceMessage_Nearby,
        ERaceMessage_RaceCountdown,
        ERaceMessage_RaceActive,
        ERaceMessage_RaceResults,
        ERaceMessage_Edit,
    };

    cGcRpcCallBase *VRJN;
    cGcRpcCallBase *VRST;
    cGcRpcCallBase *VRCH;
    bool mbRequestEditStart;
    bool mbRequestRestart;
    bool mbRequestReset;
    bool mbRequestRaceStart;
    bool mbRaceHost;
    float mfRequestedStartOffset;
    cTkPhysRelMat34 mPlayerTransform;
    cTkAttachmentPtr mCurrentStartCheckpointAttachment;
    cTkVector3 mCurrentStartCheckpointPos;
    cGcVehicleCheckpointComponentData mCurrentStartData;
    cTkVector3 mCurrentStartPos;
    cTkVector3 mCurrentStartDir;
    cTkAttachmentPtr mpActiveInviteAttachment;
    bool mbRequestLeaveRace;
    /*cGcVehicleCheckpointComponent*/ uintptr_t *mpRequestClearCheckpoints;
    cTkVector<RaceSection> maRaceCourse;
    int miRaceProgress;
    bool mbEditActive;
    bool mbRaceActive;
    bool mbNewTrackEdit;
    bool mbUsingBorrowedVehicle;
    bool mbRespawnedPlayer;
    bool mbRaceResultsActive;
    float mfRaceResultsActiveTime;
    cTkVector<MultiplayerSplits> maMultiplayerRaceResults;
    float mfRaceResultTime;
    bool mbRequestInviteDome;
    bool mbRequestMultiplayerRace;
    cTkSmartResHandle mInviteDome;
    TkHandle mInviteDomeNode;
    cGcVehicleCheckpointManager::eRaceMessage meRaceMessage;
    float mfRaceCooldown;
    float mfStartTimer;
    float mfRaceTime;
    int miStartCount;
    cTkVector<cTkAttachmentPtr> maRaceStarts;
};

SKYSCRAPER_END