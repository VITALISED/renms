/**
 * @file GcSimulation.h
 * @author VITALISED & Contributors
 * @since 2023-12-06
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

#include <simulation/environment/scanning/GcScanManager.h>
#include <simulation/player/GcPlayerRespawn.h>
#include <toolkit/core/types/TkHandle.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>
#include <toolkit/system/TkIterationState.h>
#include <toolkit/system/thread/TkLockFreeQueue.h>
#include <toolkit/system/timer/TkClock.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/string/TkString.h>

#include <reality/gcrewardjourneythroughcentre.meta.h>

SKYSCRAPER_BEGIN

class cGcSimulation
{
  public:
    struct DestructionPair
    {
        cTkRigidBodyPtr mDestroyed;
        cTkRigidBodyPtr mDestroyer;
    };

    struct sGroupNodeActivation
    {
        bool mabGroupNodeActivation[13];
    };

    cTkInplaceLockFreeQueue<cGcSimulation::DestructionPair, 1024> gDestroyedInstanceQueue;
    cTkInplaceLockFreeQueue<cGcSimulation::DestructionPair, 1024> gDestroyedCreatureQueue;
    cTkVector<TkHandle> maRemoveQueue;
    cTkFixedString<256, char> mCurrentScene;
    cGcScanManager mScanManager;
    cGcAvailableWeapons mAvailableWeapons;
    cGcSceneManager mSceneManager;
    cGcParticleManager mParticleManager;
    cGcEnvironment mEnvironment;
    cGcEcosystem mEcosystem;
    cGcProjectileManager mProjectileManager;
    cGcAISpaceshipManager mAISpaceshipManager;
    cGcNPCManager mNPCManager;
    cGcFullscreenEffectManager mFullscreenEffectManager;
    cGcSolarSystem *mpSolarSystem;
    cGcSolarSystemDirector *mpSolarSystemDirector;
    cGcSpaceshipWarp mWarp;
    cTkPhysRelVec3 mPortalMarkerPosition;
    eCentreJourneyDestination meRequestCentreJourney;
    cGcPlayerExperienceDirector mPlayerExperienceDirector;
    cGcPlayer mPlayer;
    cGcPlayerRespawn mPlayerRespawn;
    TkHandle mSimulationRootNode;
    TkHandle maGroupNodes[13];
    cTkVector<cGcSimulation::sGroupNodeActivation> mGroupNodeActivationStack;
    TkIterationState<1> mPrepareIterationState;
    bool mbTransitionFromGalacticMap;
    bool mbRequestGalaxyMap;
    bool mbSimulationPrepared;
    bool mbSimulationInLoadPhase;
    uint64_t mCurrentUA;
    uint64_t mCurrentUDA[2];
    cTkClock mMissionClock;
};
SKYSCRAPER_END