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

class cGcEnvironment
{
  public:
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
}

SKYSCRAPER_END