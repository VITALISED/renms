/**
 * @file GcPlayerSquadronOwnership.h
 * @author VITALISED & Contributors
 * @since 2023-12-09
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

#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/graphics/utilities/TkModelResourceRenderer.h>
#include <toolkit/utilities/containers/TkClassPool.h>
#include <toolkit/utilities/random/TkPersonalRNG.h>

#include <reality/gcalienrace.meta.h>
#include <utilities/data/gcresourceelement.meta.h>

SKYSCRAPER_BEGIN

enum ePlayerSquadronSummonState
{
    EPlayerSquadronSummonState_None,
    EPlayerSquadronSummonState_Incoming,
    EPlayerSquadronSummonState_Active,
    EPlayerSquadronSummonState_Leaving,
};

class cGcShipAISquadronSharedData
{
  public:
    bool mbLeaving;
    float mfLastFormationBreakTime;
    int miNumShipsInFormation;
};

class cGcSquadronPilotInfo
{
  public:
    enum eLoadState
    {
        ELoadState_None,
        ELoadState_RequestLoadResource,
        ELoadState_LoadResource,
        ELoadState_WaitForResource,
        ELoadState_GetStats,
        ELoadState_Complete,
    };

    enum eShipSpawnState
    {
        EShipSpawnState_None,
        EShipSpawnState_SpawnRequested,
        EShipSpawnState_LoadingResources,
        EShipSpawnState_AttemptingSpawn,
        EShipSpawnState_Spawned,
        EShipSpawnState_DespawnRequested,
    };

    cGcSquadronPilotInfo::eLoadState mePilotLoadState;
    cGcResourceElement mPilotNPCResource;
    eAlienRace mePilotRace;
    uint16_t muPilotRank;
    cTkFixedString<127, char> msPilotName;
    cTkFixedString<127, char> msPilotNameLoc;
    uint64_t muPilotTraitsSeed;
    cGcSquadronPilotInfo::eLoadState meSpaceshipLoadState;
    cGcResourceElement mSpaceshipResource;
    cTkModelResourceRenderer mSpaceshipThumbnailRenderer;
    cTkFixedString<127, char> mSpaceshipName;
    cTkAttachmentPtr mpSpaceshipAttachment;
    cGcSquadronPilotInfo::eShipSpawnState meShipSpawnState;
    float mfShipSpawnStateTime;
};

class cGcPlayerSquadronOwnership
{
  public:
    enum eCombatSummonState
    {
        OutOfCombat,
        InCombat_AutoSummoned,
        InCombat_AlreadySummoned,
        InCombat_Dismissed,
    };

    struct sDismissRequest
    {
        bool mbRequested;
        bool mbWarpOut;
    };

    bool mbIsPrepared;
    cTkPersonalRNG mRNG;
    cTkClassPoolHandle mSquadHandle;
    cGcShipAISquadronSharedData mSquadronSharedBehaviourData;
    ePlayerSquadronSummonState meSquadronSummonState;
    float mfSquadronSummonStateTime;
    cGcSquadronPilotInfo maPilots[4];
    bool mabUnlockedSlots[4];
    cGcPlayerSquadronOwnership::eCombatSummonState meSquadronCombatSummonState;
    TkHandle mThumbnailsGroup;
    cGcPlayerSquadronOwnership::sDismissRequest mDismissRequest;
};

SKYSCRAPER_END