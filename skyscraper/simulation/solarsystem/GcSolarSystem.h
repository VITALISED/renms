/**
 * @file GcSolarSystem.h
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

#include <gamestate/GcDiscoveryCommon.h>
#include <simulation/galaxy/GcGalaxyTypes.h>
#include <simulation/particles/GcParticleManager.h>
#include <simulation/solarsystem/GcSolarSystemCommon.h>
#include <simulation/solarsystem/GcSolarSystemGenerator.h>
#include <simulation/solarsystem/asteroid/GcAsteroidManager.h>
#include <simulation/solarsystem/planet/GcPlanet.h>
#include <simulation/solarsystem/planet/GcPlanetGenerator.h>
#include <simulation/spaceship/GcSpaceShipWarp.h>
#include <toolkit/system/TkAddNodesHandle.h>
#include <toolkit/system/TkIterationState.h>

#include <gamestate/gcplayerspawnstatedata.meta.h>
#include <simulation/player/gcscaneffectdata.meta.h>
#include <simulation/solarsystem/gcsolarsystemdata.meta.h>

SKYSCRAPER_BEGIN

struct DiscoveryAutoSync
{
    bool lbActive;
    int liIntervalInSeconds;
    uint64_t lu64LastSyncTime;
};

class cGcSolarSystem
{
  public:
    cGcSolarSystemData mSolarSystemData;
    cGcSolarSystemAsteroidFields mSolarSystemInfomap;
    cGcDiscoveryData mSolarDiscoveryData;
    cGcGalaxyAttributesAtAddress mGalaxyAttributes;
    std::array<cGcPlanet, 6> maPlanets;
    int miPrimaryPlanet;
    std::array<bool, 6> mabImGuiBrowsePlanets;
    cGcAsteroidManager mAsteroidManager;
    cGcPlanetGenerator mPlanetGenerator;
    cGcSolarSystemGenerator mSolarSystemGenerator;
    TkHandle mPlanetRootNode;
    TkHandle mRootNode;
    TkHandle mSpaceStationNode;
    cTkMatrix34 mSpaceStationSpawnTM;
    cTkMatrix34 mSpaceStationInteriorTMInverse;
    cTkAABB mSpaceStationInteriorOBB;
    cTkAABB mSpaceStationOBB;
    bool mbSpaceStationSSREnabled;
    cGcScanEffectData mPreviewNexusScanData;
    cTkColour mPreviewNexusColour;
    float mfPreviewNexusFirstActiveTime;
    float mfPreviewNexusLastActiveTime;
    bool mbShowNexusExteriorPreview;
    TkHandle mPreviewNexusExteriorNode;
    TkHandle mNexusEntranceNode;
    TkHandle mNexusExteriorNode;
    TkHandle mNexusExteriorTeleportNode;
    cTkAABB mNexusExteriorOBB;
    cTkClassPoolHandle mNexusExteriorInvalidAsteroidArea;
    bool mbLoadedNexus;
    TkHandle mNexusLoadingTask;
    cGcWarpEffect mNexusExteriorWarpEffect;
    TkAddNodesHandle mAddNodesHandle;
    TkHandle mNexusNode;
    cTkMatrix34 mNexusSpawnTM;
    cTkMatrix34 mNexusEntranceTM;
    cTkMatrix34 mNexusTMInverse;
    cTkAABB mNexusOBB;
    TkHandle mSpaceStationEntranceNode;
    cTkMatrix34 mSpaceStationEntranceTM;
    float mfOrbitHeight;
    cTkSmartResHandle mSpaceStationRes;
    cTkSmartResHandle mNexusRes;
    cTkSmartResHandle mNexusExteriorRes;
    cTkSmartResHandle mAnomalyRes;
    cTkSmartResHandle mStartingSceneRes;
    cTkSmartResHandle mHeavyAirRes;
    TkHandle mAnomalyNode;
    cTkAABB mAnomalyOBB;
    cTkMatrix34 mAnomalySpawnTM;
    cTkMatrix34 mAnomalyInteriorTMInverse;
    cTkAABB mAnomalyInteriorOBB;
    eGalaxyStarAnomaly meAnomalyType;
    cGcPlayerSpawnStateData mGeneratedPlayerSpawn;
    uint64_t mu64NextSeed;
    int miSpaceStationGenerationCounter;
    eHeavyAirType meHeavyAir;
    cTkFixedString<256, char> mFilename;
    cTkMatrix34 mLastKnownPlayerTransform;
    bool mbInOrbit;
    bool mbImGuiTerrainDataMinCollpased;
    bool mbImGuiTerrainDataMaxCollpased;
    bool mbImGuiTerrainDataCollpased;
    bool mbFirstBoot;
    bool mbLoadedFromSettings;
    bool mbAnomalyWarpingActive;
    TkIterationState<2> mPrepareIterationState;
    DiscoveryAutoSync mDiscoveryAutoSync;
    cTkVector3 mNGuiCameraPosition;
    cTkVector3 mNGuiPlanetPosition;
    cGcAsteroidLayout mDebugAsteroidGeneratorLayout;
    cGcGalacticSolarSystemAddress mRequestedQuickJump;
    int miPrevLoadBalancingTimeout;
    float mfPlanetPrepareTime;
};

SKYSCRAPER_END