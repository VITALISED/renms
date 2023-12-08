/**
 * @file GcAISpaceshipManager.h
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

#include <networking/GcNetworkRpcCall.h>
#include <simulation/spaceship/ai/playersquad/GcShipAISquadronData.h>
#include <toolkit/core/types/TkID.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/utilities/containers/TkBitArray.h>
#include <toolkit/utilities/containers/TkClassPool.h>
#include <toolkit/utilities/containers/TkUnorderedMap.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/random/TkPersonalRNG.h>

#include <reality/gcrealitycommonfactions.meta.h>
#include <simulation/gcspaceshipclasses.meta.h>
#include <simulation/spaceship/ai/gcaishipspawndata.meta.h>
#include <simulation/spaceship/ai/gcaispaceshipmanagerdata.meta.h>
#include <simulation/spaceship/gcshipaiattackdatatable.meta.h>
#include <simulation/spaceship/gcshipaicombatdefinition.meta.h>
#include <toolkit/tkmodelresource.meta.h>

SKYSCRAPER_BEGIN

enum ePlayerBoostCheck
{
    EPlayerBoostCheck_Allowed,
    EPlayerBoostCheck_TooCloseToStation,
    EPlayerBoostCheck_TooCloseToFreighters,
    EPlayerBoostCheck_EnemiesNearby,
    EPlayerBoostCheck_InAtmosphere,
    EPlayerBoostCheck_TooCloseToAnomaly,
    EPlayerBoostCheck_UsingComms,
    EPlayerBoostCheck_NumTypes,
};

struct cGcCachedShipResource
{
    std::array<cTkSmartResHandle, 32> mHandles;
    std::array<eShipClass, 32> mClass;
    int mCount;
    int miRefCount;
};

class cGcAIShipSpawnEvent
{
  public:
    const cGcAIShipSpawnData *mpData;
    cTkMatrix34 mMatrix;
    float mfStartTime;
    float mfStartSpeed;
    float mfFrigateTargetSpeed;
    cTkClassPoolHandle mSquad;
    eAIFaction meFaction;
    cTkSeed mSeed;
    cTkBitArray<uint64_t, 1, 64> mxShipsLaunched;
    TkID<128> mAttackDefinition;
    bool mbIgnoreWarpEffects;
    bool mbImmediatelySwitchToComplexCollision;
};

class cGcAISpaceshipManager
{
    enum eSortMethod
    {
        ESortMethod_Type,
        ESortMethod_Squad,
        ESortMethod_NumTypes,
    };

    struct sFreighterSpawnInProgress
    {
        cTkClassPoolHandle mSquadHandle;
        int miNumShipsLastUpdate;
        bool mbWarpIn;
    };

    cTkVector<cGcAISpaceshipManager::sFreighterSpawnInProgress> maFreighterSquadsBeingSpawned;
    ePlayerBoostCheck mePlayerBoostState;
    float mfPlayerBoostStateChangeTime;
    cTkUnorderedMap<TkID<128>, cGcShipAICombatDefinition *, TkIDUnorderedMap::Hash128> mCombatDefinitionMap;
    cGcAISpaceshipManagerData *mpData;
    cGcShipAIAttackDataTable *mpAttackData;
    cTkSeed mSeed;
    robin_hood::detail::Table<
        true, 80, unsigned int, cGcCachedShipResource *, robin_hood::hash<unsigned int, void>,
        std::equal_to<unsigned int>>
        mShipPairCache;
    eAIFaction meBrowseFaction;
    eAIShipRole meBrowseRole;
    cTkClassPoolHandle mDefaultSquad;
    cTkVector<cGcAIShipSpawnEvent> maSpawnEvents;
    cTkVector<cGcAIShipSpawnEvent> maChildSpawnEvents;
    bool mbChildSpawnsActive;
    int miNumShipsAttackingPlayer;
    int miNumSquadsAttackingPlayer;
    cTkClassPool<cGcAIShipSquad, 64> maSquads;
    int miSquadCounter;
    cGcAISpaceshipManager::eSortMethod meSortMethod;
    cTkSmartResHandle mFreighterControllerRes;
    cTkPersonalRNG mRNG;
    /*cGcOutpostComponent*/ uintptr_t *mpSelectedOutpost;
    /*cGcAISpaceshipComponent*/ uintptr_t *mpSelectedShip;
    bool mbShowShootables;
    bool mbHighlightSelected;
    cTkSmartResHandle mLoot;
    TkHandle mLootRootGroop;
    cTkModelResource mAIHangarResource;
    TkHandle mFrigateBeingSpawned;
    cGcAIShipSpawn *mpFrigateSpawnData;
    cGcRpcCallBase *STSH;
    cGcRpcCallBase *SSSH;
    cGcRpcCallBase *TSSH;
    cGcRpcCallBase *WNSH;
    cGcRpcCallBase *STCC;
    cGcRpcCallBase *PLSS;
};

SKYSCRAPER_END