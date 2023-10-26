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
#include <gamestate/GcDiscoveryCommon.h>
#include <metadata/source/simulation/solarsystem/planet/gcplanetdata.meta.h>
#include <metadata/source/simulation/solarsystem/planet/gcplanetgenerationinputdata.meta.h>

SKYSCRAPER_BEGIN

class cGcPlanet
{
	std::array<bool, 7> mabActivePrimaryRegionStates;
	cGcDiscoveryData mPlanetDiscoveryData;
	unsigned __int64 muBeaconUpdateIndex;
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
	cTkCollision* mpWaterCollision;
	cTkRigidBody* mpWaterRigidBody;
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
	void* mpCachedTerrainMaterialPtr;
	void* mpCachedWaterMaterialPtr;
	void* mpCachedAtmosphereMaterial;
	void* mpCachedRingMaterial;
	cGcPlanet::sStorm mStorm;
	cGcPlanet::sClouds mClouds;
	cTkSeed mPortalStartSeed;
	eResourceLoadState maResourceLoadingRequests[2];
	cTkTimerTemplate<0> mLoadBalancingTimer;
	TkJobHandle mPlanetUniformsJobHandle;
	cGcEnvironmentProperties* mpEnvProperties;
	cGcPlanetSkyProperties* mpSkyProperties;
};

SKYSCRAPER_END