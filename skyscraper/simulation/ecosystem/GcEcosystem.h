/**
 * @file GcEcosystem.h
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

#include <simulation/ecosystem/GcCreatureGUID.h>
#include <simulation/ecosystem/GcCreatureSwarm.h>
#include <simulation/ecosystem/GcEcosystemCommon.h>
#include <simulation/scenemanager/GcFadeNode.h>
#include <toolkit/utilities/containers/TkStackContainer.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <simulation/ecosystem/creatures/gccreatureaudiotable.meta.h>
#include <simulation/ecosystem/creatures/gccreaturebehaviourtrees.meta.h>
#include <simulation/ecosystem/creatures/gccreaturedatatable.meta.h>
#include <simulation/ecosystem/creatures/gccreaturefilenametable.meta.h>

SKYSCRAPER_BEGIN

class cGcRagdollLimiter
{
  public:
    cTkStackVector</*cTkPhysicsComponent*/ uintptr_t *, 128> mRagdolls;
};

class cGcEcosystem
{
  public:
    class cGcSpawnedCreatureRecord
    {
      public:
        cGcCreatureGUID mGUID;
        cGcFadeNode *mpFade;
        TkHandle mNode;
        int miSwarmIndex;
        float mfDespawnRadius;
        bool mbEcosystemControl;
        int miEcosystemIndex;
        bool mbUnderwater;
        char macDebugID[10];
    };

    int miTotalNumCreaturesSpawned;
    int miNumEcosystemCreaturesSpawned;
    int miNumBirdsSpawned;
    cGcFadeNode maCreatureFadeNodes[256];
    cGcEcosystem::cGcSpawnedCreatureRecord maSpawnedCreatures[256];
    cTkVector<TkHandle> maDespawnNodes;
    cGcCreatureSwarm maSwarms[50];
    int miNumSwarms;
    cGcCreatureStats maCreatureStats[32];
    int miNumCreatureStats;
    int maiCreatureCounts[32];
    cGcCreatureDataTable *mapCreatureTables[32];
    int miNumCreatureTables;
    cGcCreatureFilenameTable *mpSpawnData;
    cGcCreatureAudioTable *mpCreatureAudioTable;
    cGcCreatureBehaviourTrees *mpBehaviourTrees;
    cGcRagdollLimiter mRagdollLimiter;
    bool mbImGuiShowCreatureList;
    TkID<128> mImGuiSelectedCreature;
    int miImGuiSelectedTable;
    eCreatureType meDebugBehaviour;
    int miSpawnDataIndex;
    cTkAttachment *mpDebugSelectedCreature;
    float mfPlayerUnderwaterAmount;
    float mfPlayerUnderwaterAmountVel;
};

SKYSCRAPER_END