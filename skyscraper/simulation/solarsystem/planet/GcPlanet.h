/**
 * @file GcPlanet.h
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
#include <simulation/environment/regiondata/terrain/GcTerrainRegionMap.h>
#include <simulation/solarsystem/buildings/GcBuildingList.h>
#include <simulation/solarsystem/planet/GcPlanetCommon.h>
#include <simulation/solarsystem/planet/GcPlanetControls.h>
#include <simulation/solarsystem/planet/GcPlanetLodSphere.h>
#include <toolkit/maths/numeric/TkSmoothCD.h>
#include <toolkit/simulation/physics/havok/TkCollision.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>
#include <toolkit/system/TkIterationState.h>
#include <toolkit/system/thread/TkRegionThreadManager.h>
#include <toolkit/system/timer/TkTimer.h>

#include <simulation/environment/gcenvironmentproperties.meta.h>
#include <simulation/environment/gcplanetskyproperties.meta.h>
#include <simulation/solarsystem/planet/gcplanetdata.meta.h>
#include <simulation/solarsystem/planet/gcplanetgenerationinputdata.meta.h>

SKYSCRAPER_BEGIN

enum eSentinelCrimeResponse
{
    ESentinelCrimeResponse_Respond,
    ESentinelCrimeResponse_Ignore,
};

enum ePlanetTransitionState
{
    EPlanetTransition_None,
    EPlanetTransition_InSpace,
    EPlanetTransition_InSpaceNearPlanet,
    EPlanetTransition_OnPlanet,
    EPlanetTransition_StartLeavingPlanet,
    EPlanetTransition_FinishLeavingPlanet,
    EPlanetTransition_StartEnteringPlanet,
    EPlanetTransition_FinishEnteringPlanet,
    EPlanetTransition_InTransition,
    EPlanetTransition_AerialViewTransition,
    EPlanetTransition_AmbientLoad,
    EPlanetTransition_Num,
};

enum eResourceLoadState
{
    EResourceLoad_Unloaded,
    EResourceLoad_Requested,
    EResourceLoad_Loaded,
};

class cGcPlanet
{
  public:
    struct sSentinelCrimeResponse
    {
        eSentinelCrimeResponse meCrimeResponse;
        float mfCrimeResponseResetTime;
        float mfSentinelIgnoreCrimeStartTime;
    };

    struct sStorm
    {
        uint64_t mu64StormStartTime;
        uint64_t mu64StormSeed;
        cTkSmoothCD<float> mfGravityMultiplier;
        float mfTargetGravityMultiplier;
        cTkSmoothCD<float> mfStormStrength;
        int miStormIndex;
    };

    struct sClouds
    {
        cTkSmoothCD<float> mfCloudCover;
        cTkSmoothCD<float> mfCloudRatio;
        cTkSmoothCD<float> mfStormCloudStrength;
        bool mbInstantCloudsUpdate;
    };

    std::array<bool, 7> mabActivePrimaryRegionStates;
    cGcDiscoveryData mPlanetDiscoveryData;
    uint64_t muBeaconUpdateIndex;
    int miPlanetIndex;
    cGcPlanetData mPlanetData;
    cGcPlanetGenerationInputData mPlanetGenerationInputData;
    std::unique_ptr<cGcPlanetControls> mPlanetControls;
    cGcBuildingList mBuildings;
    cGcPlanetSpawnData mSpawnData;
    cTkSeed mShipStartBuildingSeed;
    cTkSeed mSurvivalStartBuildingSeed;
    bool mbIsPrimary;
    bool mbPrimarySwitched;
    bool mbFinishedGenerating;
    bool mbIsScanned;
    cGcPlanet::sSentinelCrimeResponse mSentinelCrimeResponse;
    cGcTerrainRegionMap mRegionMap;
    TkHandle mRegionNode;
    int miRegionRadiusSet;
    TkHandle mNode;
    TkHandle mAtmosphereNode;
    TkHandle mPlanetMeshNode;
    TkHandle mRingNode;
    cTkVector3 mPosition;
    cGcPlanetLodSphere mLodSphere;
    cTkCollision *mpWaterCollision;
    cTkRigidBody *mpWaterRigidBody;
    cTkSmartResHandle mTerrainMaterial;
    cTkSmartResHandle mWaterMaterial;
    cTkSmartResHandle mAtmosphereMaterial;
    cTkSmartResHandle mTerrainDiffuseRes;
    cTkSmartResHandle mTerrainNormalMapRes;
    cTkSmartResHandle mOverlayDiffuseRes;
    cTkSmartResHandle mOverlayNormalRes;
    cTkSmartResHandle mOverlayMasksRes;
    cTkSmartResHandle mWaterHeavyAirRes;
    cTkSmartResHandle mWeatherHeavyAirRes;
    cTkSmartResHandle mRingMaterial;
    int miVertexNodePropertyIndex;
    bool mbUseSpaceAtmosphere;
    float mfIndoorLightingBlend;
    float mfIndoorFogStrength;
    float mfRingAvoidanceSphereInterpolate;
    float mfRingAvoidanceSphereRadius;
    cTkVector3 mRingAvoidanceSpherePosition;
    std::array<cTkColour, 23> maAverageColour;
    std::array<float, 26> maSpecularValue;
    cTkFixedString<256, char> mFilename;
    bool mbMetadataRegistered;
    bool mbHasRegionData;
    bool mbPendingCopyRegionVoxelData;
    bool mbPaused;
    TkHandle mPlanetSceneNode;
    ePlanetTransitionState meTransitionState;
    bool mbIsGeneratingDuringLoad;
    void *mpCachedTerrainMaterialPtr;
    void *mpCachedWaterMaterialPtr;
    void *mpCachedAtmosphereMaterial;
    void *mpCachedRingMaterial;
    cGcPlanet::sStorm mStorm;
    cGcPlanet::sClouds mClouds;
    cTkSeed mPortalStartSeed;
    eResourceLoadState maResourceLoadingRequests[2];
    cTkTimerTemplate<0> mLoadBalancingTimer;
    TkJobHandle mPlanetUniformsJobHandle;
    cGcEnvironmentProperties *mpEnvProperties;
    cGcPlanetSkyProperties *mpSkyProperties;
};

SKYSCRAPER_END