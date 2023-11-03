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
#include <simulation/player/GcPlayer.h>
#include <simulation/environment/scanning/GcScanManager.h>
#include <toolkit/system/TkIterationState.h>

SKYSCRAPER_BEGIN

template <typename T, unsigned int size>
class cTkInplaceLockFreeQueue
{};

class cGcSimulation
{
    struct DestructionPair
    {
        cTkRigidBodyPtr mDestroyed;
        cTkRigidBodyPtr mDestroyer;
    };

    cTkInplaceLockFreeQueue<cGcSimulation::DestructionPair,1024> gDestroyedInstanceQueue;
    cTkInplaceLockFreeQueue<cGcSimulation::DestructionPair,1024> gDestroyedCreatureQueue;
    std::vector<TkHandle,TkSTLAllocatorShim<TkHandle,4,-1> > maRemoveQueue;
    
    cTkFixedString<256,char> mCurrentScene;
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
    std::vector<cGcSimulation::sGroupNodeActivation,TkSTLAllocatorShim<cGcSimulation::sGroupNodeActivation,1,-1> > mGroupNodeActivationStack;
    TkIterationState<1> mPrepareIterationState;
    bool mbTransitionFromGalacticMap;
    bool mbRequestGalaxyMap;
    bool mbSimulationPrepared;
    bool mbSimulationInLoadPhase;
    unsigned __int64 mCurrentUA;
    unsigned __int64 mCurrentUDA[2];
    cTkClock mMissionClock;
};

SKYSCRAPER_END
