#pragma once

#include <skyscraper.h>
#include <gamestate/GcDiscoveryCommon.h>
#include <metadata/simulation/solarsystem/planet/gcplanetdata.meta.h>
#include <metadata/simulation/solarsystem/planet/gcplanetgenerationinputdata.meta.h>

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