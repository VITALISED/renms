/**
 * @file GcRegionDecoratorCreatures.h
 * @author VITALISED & Contributors
 * @since 2023-12-11
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

#include <simulation/ecosystem/GcCreatureSwarm.h>
#include <simulation/ecosystem/GcEcosystemCommon.h>
#include <toolkit/maths/geometry/TkAABB.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/random/TkPersonalRNG.h>

#include <simulation/ecosystem/gccreaturespawndata.meta.h>

SKYSCRAPER_BEGIN

class cGcPlanet;
class cGcRegionTerrain;

class cGcRegionDecoratorCreatures
{
  public:
    class cGcCreatureNodeData
    {
      public:
        int miNumObjects;
        int miCreatureCount;
        cGcCreatureSpawnData *mpObject;
        cTkVector<cTkMatrix34> mTransforms;
        cTkVector<bool> maBabyFlags;
        char *maGroupSize;
    };
    cTkVector<cGcRegionDecoratorCreatures::cGcCreatureNodeData> mCreatureNodes;
    int miNumObjectTypes;
    cGcPlanet *mpPlanet;
    cTkVector3 mPlanetPosition;
    cTkAABB mRegionAabb;
    cTkPersonalRNG mRNG;
    cGcCreatureRoutine *mCreatureRoutines;
    int miNumCreatureRoutinesTotal;
    int miNumCreatureRoutinesGenerated;
    bool mbRoutinesCreated;
    cTkSeed mRoutinesSeed;
    cGcCreatureStats *mpCreatureStats;
    cGcRegionTerrain *mpRegion;
};

SKYSCRAPER_END