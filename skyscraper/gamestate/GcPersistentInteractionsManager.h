/**
 * @file GcPersistentInteractionsManager.h
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

#include <gamestate/GcBaseBuildingGlobalBuffer.h>
#include <gamestate/GcPersistentInteractionBuffer.h>
#include <gamestate/GcPlayerBasePersistentBuffer.h>
#include <gamestate/GcTerrainEditsPersistentBuffer.h>
#include <gamestate/GcTradingSupplyBuffer.h>
#include <simulation/galaxy/GcGalaxyTypes.h>

#include <gamestate/gcmaintenancecontainer.meta.h>

SKYSCRAPER_BEGIN

struct GcPersistencyHandle
{
    union {
        struct
        {
            uint32_t miLookup : 21;
            uint32_t miIncrementor : 11;
        };
        uint32_t miLookupInt;
    };
};

class cGcMaintenanceBuffer : public cGcVariablePersistentInteractionBuffer<cGcMaintenanceContainer>
{};

struct sVisitedSystem
{
    cGcGalacticVoxelCoordinate mVoxel;
    int16_t miSystemIndex;
    uint16_t miPlanetsVisited;
};

class cGcVisitedSystemsBuffer
{
    cTkFixedArray<sVisitedSystem, 512> mVisitedSystems;
    int miCurrentPosition;
    int miVisitedSystemsCount;
};

class cGcPersistentInteractionsManager
{
  public:
    cGcBaseBuildingGlobalBuffer mBaseBuildingBuffer;
    cTkVector<cGcPlayerBasePersistentBuffer> maPersistentBaseBuffers;
    cGcPersistentInteractionBuffer mDistressSignalBuffer;
    cGcPersistentInteractionBuffer mCrateBuffer;
    cGcPersistentInteractionBuffer mDestructableBuffer;
    cGcPersistentInteractionBuffer mCostBuffer;
    cGcPersistentInteractionBuffer mBuildingBuffer;
    cGcPersistentInteractionBuffer mCreatureBuffer;
    cGcPersistentInteractionBuffer mPersonalBuffer;
    cGcPersistentInteractionBuffer mFireteamSyncBuffer;
    cGcTerrainEditsPersistentBuffer mTerrainEditBuffer;
    cGcTradingSupplyBuffer mTradingSupplyBuffer;
    cGcMaintenanceBuffer mMaintenanceBuffer;
    cGcMaintenanceBuffer mPersonalMaintenanceBuffer;
    cGcVisitedSystemsBuffer mVisitedSystemsBuffer;
};

SKYSCRAPER_END