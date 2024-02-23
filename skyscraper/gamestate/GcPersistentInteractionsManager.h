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

#include <basebuilding/GcBaseBuildingManagerTypes.h>
#include <gamestate/GcBaseBuildingGlobalBuffer.h>
#include <gamestate/GcPersistencyHandle.h>
#include <gamestate/GcPersistentInteractionBuffer.h>
#include <gamestate/GcPlayerBasePersistentBuffer.h>
#include <gamestate/GcTerrainEditsPersistentBuffer.h>
#include <gamestate/GcTradingSupplyBuffer.h>
#include <simulation/galaxy/GcGalaxyTypes.h>

#include <gamestate/basebuilding/gcpersistentbase.meta.h>
#include <gamestate/gcmaintenancecontainer.meta.h>

SKYSCRAPER_BEGIN

class cGcMaintenanceBuffer : public cGcVariablePersistentInteractionBuffer<cGcMaintenanceContainer>
{
  public:
    virtual uint16_t GenerateHashValue(int);

    void CleanUpValidSlotIndexes();

    static uint64_t GenerateChangeHash(const cGcMaintenanceContainer &lMaintenanceContainer);
};

struct sVisit
{
    cGcGalacticVoxelCoordinate mVoxel;
    int16_t miSolarSystemIndex;
    uint16_t miPlanetsVisited;
};

struct sVisitedSystem
{
    cGcGalacticVoxelCoordinate mVoxel;
    int16_t miSystemIndex;
    uint16_t miPlanetsVisited;
};

class cGcVisitedSystemsBuffer
{
  public:
    uint16_t GetVisitedData(const cGcGalacticVoxelCoordinate &lVoxel, uint32_t luiSolarSystemIndex);
    void GetVisitedSystemsAroundVoxel(cTkVector<sVisit> &lVisitsOut, cGcGalacticVoxelCoordinate &lVoxel, int);
    void VisitNewGalacticAddress(const uint64_t &lu64Address);

    cTkFixedArray<sVisitedSystem, 512> mVisitedSystems;
    int miCurrentPosition;
    int miVisitedSystemsCount;
};

class cGcPersistentInteractionsManager
{
  public:
    void Construct();
    void Update();
    BaseIndex &CreatePlayerBaseBuffer(
        ePersistentBaseTypes leBaseType, const cTkPhysRelMat34 &lBaseMatrix, uint64_t lUA,
        cTkUserIdBase<cTkFixedString<64, char>> &lOwnerId);
    cGcMaintenanceBuffer *GetInteractionBuffer(eInteractionBufferType lBuffer);
    void GetPlayerBuffersInRange(
        cTkVector<BaseIndex> &lOutBufferIndexes, ePersistentBaseTypes leType, const cTkVector3 &lPosition, uint64_t lUA,
        float lfRange);
    void InitializeFromData(
        const cTkFixedArray<cGcInteractionBuffer, 11> &lArrayData,
        const cTkDynamicArray<cGcPersistentBase> &lPlayerBaseArrayData,
        const cTkDynamicArray<cGcMaintenanceContainer> &lMaintenanceData,
        const cTkDynamicArray<cGcMaintenanceContainer> &lPersonalMaintenanceData,
        const cTkDynamicArray<uint64_t> &lVisitedSystems);
    void LoadGalacticAddressBuffers(uint64_t &lu64Address);
    void PopulateArrays(
        cTkFixedArray<cGcInteractionBuffer, 11> &lArrayData, cTkDynamicArray<cGcPersistentBase> &lPlayerBaseArrayData,
        cTkDynamicArray<cGcMaintenanceContainer> &lMaintenanceData,
        cTkDynamicArray<cGcMaintenanceContainer> &lPersonalMaintenanceData, cTkDynamicArray<uint64_t> &lVisitedSystems);

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