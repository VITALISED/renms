/**
 * @file GcRegionDecoratorBuildings.h
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

#include <simulation/solarsystem/buildings/wfcbuildings/GcWFCBuildingState.h>
#include <toolkit/system/TkIterationState.h>
#include <toolkit/utilities/containers/TkListNodeStandalone.h>

SKYSCRAPER_BEGIN

class cGcRegionTerrainFar;
class cGcBuilding;

struct sRegionEdit
{
    cTkVector3 mMapPosition;
    sTerrainEditData mEditData;
    bool mbEditApplied;
};

class cGcRegionDecoratorBuildings
{
  public:
    enum eBuildingUpgradeState
    {
        EBuildingUpgradeState_None,
        EBuildingUpgradeState_NeedsUpgrade,
        EBuildingUpgradeState_InProgress,
        EBuildingUpgradeState_Upgraded,
    };

    struct sAddBuildingParams
    {
        cTkVector3 mInputPosition;
        cTkVector3 mCenterPosition;
        cTkSeed mSectorID;
        cTkVector3 mpaPositions[41];
        cTkVector3 mpaDirections[41];
        float mpafDistances[41];
        cTkSeed mpaSeeds[41];
        int mpaiBuildingIndices[41];
        bool mbaIsInitialSettlementBuilding[41];
    };

    cGcRegionTerrainFar *mpRegion;
    cTkStackVector<cGcBuilding *, 16> mBuildings;
    cTkStackVector<cGcRegionDecoratorBuildings::sAddBuildingParams, 16> maGeneratedBuildingParams;
    cTkStackVector<cGcWFCBuildingState *, 16> mWFCStates;
    TkHandle mGroupNode;
    TkHandle mCrashedShipGroupNode;
    cGcPlanet *mpPlanet;
    cGcRegionDecoratorBuildings::eBuildingUpgradeState meCurrentUpgradeState;
    bool mbBuildingsSpawned;
    TkIterationState<2> mUpgradeIterationState;
    cTkListNode<cGcRegionDecoratorBuildings *> mUpgradeNode;
    cTkVector<sRegionEdit> mBuildingTerrainEdits;
};

SKYSCRAPER_END