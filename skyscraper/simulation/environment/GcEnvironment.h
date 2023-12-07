/**
 * @file GcEnvironment.h
 * @author VITALISED & Contributors
 * @since 2023-12-06
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

#include <simulation/environment/GcReflectionProbesManager.h>
#include <simulation/environment/weather/GcSky.h>
#include <toolkit/networking/TkUserIdBase.h>
#include <toolkit/simulation/physics/TkRaycastJob.h>
#include <toolkit/system/TkIterationState.h>
#include <toolkit/utilities/containers/TkStackContainer.h>
#include <toolkit/voxel/manager/TkRegionHeightTest.h>

#include <audio/gcbasepartaudiolocation.meta.h>
#include <simulation/environment/gcbuildingclassification.meta.h>
#include <simulation/environment/weather/gchazardvaluetypes.meta.h>
#include <simulation/galaxy/gcgalaxystaranomaly.meta.h>
#include <simulation/gcphysicscollisiongroups.meta.h>
#include <simulation/solarsystem/planet/gcbiomesubtype.meta.h>
#include <simulation/solarsystem/planet/gcbiometype.meta.h>
#include <toolkit/components/physics/tkvolumetriggertype.meta.h>

SKYSCRAPER_BEGIN

namespace EnvironmentLocation
{

enum Enum
{
    Invalid,
    Space,
    Space_SpaceStation,
    Planet,
    Planet_InShip,
    Planet_InVehicle,
    Planet_Underwater,
    Planet_Underground,
    Planet_Building,
    Freighter,
    FreighterAbandoned,
    Frigate,
    Space_SpaceBase,
    Space_Nexus,
    Space_Anomaly,
    __EnumTerminator,
    Unspecified,
};

} // namespace EnvironmentLocation

enum eRegionKnowledgeInterest
{
    ERegionKnowledgeInterest_NothingInteresting,
    ERegionKnowledgeInterest_DeadEnd,
    ERegionKnowledgeInterest_Shelter,
    ERegionKnowledgeInterest_WaterEdge,
    ERegionKnowledgeInterest_WaterInlet,
    ERegionKnowledgeInterest_WaterShore,
    ERegionKnowledgeInterest_Forest,
    ERegionKnowledgeInterest_Meadow,
    ERegionKnowledgeInterest_MeadowEdge,
    ERegionKnowledgeInterest_Clearing,
    ERegionKnowledgeInterest_Building,
    ERegionKnowledgeInterest_PlayerBase,
    ERegionKnowledgeInterest_Settlement,
    ERegionKnowledgeInterest_Spaceship,
    ERegionKnowledgeInterest_Impassable,
    ERegionKnowledgeInterest_Count,
};

class cGcPlayerEnvironment
{
  public:
    struct SpaceState
    {
        float mfNearestPolice;
        float mfNearestPirate;
        float mfNearestFreighter;
        bool mbPoliceActive;
        bool mbPiratesActive;
        bool mbFreightersActive;
        bool mbFreightersBeingAttacked;
    };

    struct ActiveTriggerVolume
    {
        TkHandle mNode;
        eVolumeTriggerType meType;
    };

    cTkMatrix34 mPlayerTM;
    cTkVector3 mUp;
    uint64_t mu64UA;
    int miNearestPlanetIndex;
    float mfDistanceFromPlanet;
    float mfNearestPlanetSealevel;
    cTkVector3 mNearestPlanetPos;
    int miNearestPlanetCreatureRoles;
    eGalaxyStarAnomaly meStarAnomaly;
    float mfDistanceFromAnomaly;
    bool mbInsidePlanetAtmosphere;
    eBiome meBiome;
    eBiomeSubType meBiomeSubType;
    bool mbIsRaining;
    float mfStormLevel;
    eWeather meWeather;
    float mfTimeOfDay;
    float mfLightFactor;
    float mfNightFactor;
    bool mbIsNight;
    float mfLightShaftFactor;
    EnvironmentLocation::Enum meLocation;
    float mfTimeInLocation;
    bool mbUndergroundIsCave;
    EnvironmentLocation::Enum meCameraLocation;
    float mfTimeInCameraLocation;
    EnvironmentLocation::Enum meCameraLocationStable;
    TkHandle mInsideBuildingNode;
    eRegionKnowledgeInterest meInterest;
    float mfTimeInInterest;
    EnvironmentLocation::Enum meLocationStable;
    eRegionKnowledgeInterest meInterestStable;
    bool mbInAsteroidFieldStable;
    EnvironmentLocation::Enum meVehicleLocation;
    eBuildingClass meNearestBuildingClass;
    float mfNearestBuildingDistance;
    bool mbNearestBuildingValid;
    eBasePartAudioLocation meBasePartAudioLocation;
    bool mbPilotingShip;
    bool mbPilotingVehicle;
    bool mbFullControlOfShip;
    bool mbIsWarping;
    bool mbIsWanted;
    bool mbSpaceCombatActive;
    float mfSpaceCombatActiveTime;
    bool mbIsInPlayerFreighter;
    bool mbIsInFreighterBase;
    bool mbForceFreighterShipHidingUpdate;
    cTkUserIdBase<cTkFixedString<64, char>> mOccupiedFreighterOwner;
    bool mbBlockedFromCraftingBySeasonalBaseRequirements;
    bool mPlanetRegionQueryValid;
    cTkRegionHeightResult mPlanetRegionQuery;
    float mPlanetRegionQueryDistance;
    float mfUnderwaterDepth;
    float mfExteriorExposure;
    float mfTemperature;
    float mfTemperatureSmoothed;
    float mfTemperatureExternal;
    float mfToxicity;
    float mfToxicitySmoothed;
    float mfToxicityExternal;
    float mfRadiation;
    float mfRadiationSmoothed;
    float mfRadiationExternal;
    float mfLifeSupportDrain;
    float mafHazardFactors[6];
    float mafTargetHazardFactors[6];
    float mafNormalisedHazardFactors[6];
    eHazardValue mePrimaryHazardControl;
    float maObscuredAroundNear[2];
    float maObscuredAroundNearSlow[2];
    float maObscuredAroundFar[2];
    float maObscuredAroundFarSlow[2];
    float maObscuredOverhead[2];
    float maObscuredTowardsSun[2];
    float mfGlassSurfacesNearby;
    float mfNearestSurface;
    float mfNearestSurfaceOverhead;
    eCollisionGroup meCollisionGroupOverhead;
    eCollisionGroup meCollisionGroupDirectUnder;
    float mfDistanceDirectUnder;
    eCollisionGroup meCollisionGroupDirectUnderNA;
    float mfDistanceDirectUnderNA;
    float maGroundCoverage[2];
    float mfIndoorLightingFactor;
    float mfIndoorLightingFactorRate;
    float mfIndoorLightTransitionFactor;
    bool mbFlyingTowardsPlanet;
    int miFlyingTowardsPlanetIndex;
    bool mbSpaceStateValid;
    cGcPlayerEnvironment::SpaceState mSpaceState;
    cTkStackVector<cGcPlayerEnvironment::ActiveTriggerVolume, 16> mCurrentlyActiveTriggers;
    bool mbInteriorTriggerTypeActive;
    bool mbCoveredExteriorTriggerTypeActive;
    bool mbInsideHazardProtectionVolume;
    bool mbInsideHazardProtectionColdVolume;
    bool mbInsideSpaceStorm;
    float mfTemperatureSpringRate;
    float mfToxicitySpringRate;
    float mfRadiationSpringRate;
    float maObscuredAroundNearRate[2];
    float maObscuredAroundNearRateSlow[2];
    float maObscuredAroundFarRate[2];
    float maObscuredAroundFarRateSlow[2];
    float maObscuredOverheadRate[2];
    float maObscuredTowardsSunRate[2];
    float maGroundCoverageRate[2];
    float mfNearestSurfaceRate;
    float mfNearestSurfaceOverheadRate;
    float mfGlassSurfacesNearbyRate;
    bool mbInAsteroidField;
    float mfAsteroidFieldStateTime;
};

class cGcEnvironment
{
  public:
    enum eShadowState
    {
        EShadowState_Space,
        EShadowState_Ship,
        EShadowState_Surface,
    };

    TkIterationState<1> mTextureCreationIterationState;
    cTkSmartResHandle mWaterReflectionTextureRes;
    cTkSmartResHandle mWaterReflectionPipelineRes;
    cTkSmartResHandle mDualPMapPipelineRes;
    cTkSmartResHandle mMainPipeline;
    cTkSmartResHandle mCausticDisplacementTex;
    cTkSmartResHandle mCausticMapTex;
    cTkSmartResHandle mUberShader;
    cTkSmartResHandle mLightShader;
    cTkSmartResHandle mWaterShader;
    cTkSmartResHandle mSkyShader;
    cTkSmartResHandle mTerrainShader;
    cTkSmartResHandle mIBLShader;
    cTkSmartResHandle mParticleShader;
    cTkSmartResHandle mPStreamShader;
    cTkSmartResHandle mShaderMillParticleShader;
    cTkSmartResHandle mShaderMillUberShader;
    cTkSmartResHandle mUIScreenShader;
    cTkSmartResHandle mDualPMapResFront;
    cTkSmartResHandle mDualPMapResBack;
    cTkSmartResHandle mIBLMapResFront;
    cTkSmartResHandle mIBLMapResBack;
    cTkSmartResHandle mIBLMapIndoorResFront;
    cTkSmartResHandle mIBLMapIndoorResBack;
    cTkSmartResHandle mTerrainColourRes;
    cTkSmartResHandle mIBLPipelineRes;
    cTkSmartResHandle mDepthOfFieldMat;
    cTkSmartResHandle mIBLMaterial;
    bool mbIsUsingDynamicDualPmap;
    cGcSky mSky;
    bool mbCloudsEnabled;
    int miCloudsIndex;
    int miCloudsBlurIndex;
    int miCloudsCopyIndex;
    int miParticleIndex;
    int miReflectionWaterFromAboveIndex;
    int miReflectionWaterFromBelowIndex;
    int miMainWaterFromAboveIndex;
    int miMainWaterFromBelowIndex;
    int miDepthReprojectWFAIndex;
    int miDepthReprojectIndex;
    int miVolumetricsIndex;
    int miNumDualPMips;
    float mfShadowLength;
    cTkVector4 mShadowSplit;
    float mfShadowLengthTarget;
    float mfShadowSplit1Target;
    float mfShadowSplit2Target;
    cGcEnvironment::eShadowState meShadowState;
    cGcPlayerEnvironment mPlayerEnvironment;
    cGcPlayerEnvironment mPlayerEnvironmentPreviousFrame;
    cTkRaycastJob mGeometryProbeJob;
    float mfMinPixelCullForShadows;
    cTkVector3 mLightingOriginPosition;
    cGcReflectionProbesManager mReflectionProbesManager;
    cGcTempPortalRenderData mPortalRenderData;
};

SKYSCRAPER_END