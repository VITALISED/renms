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

#include <application/states/GcApplicationState.h>
#include <simulation/solarsystem/asteroid/GcAsteroidPatternGenerator.h>
#include <toolkit/graphics/2d/texture/TkDynamicTexture.h>
#include <toolkit/maths/geometry/TkSphere.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <simulation/solarsystem/asteroids/gcasteroidgeneratorring.meta.h>
#include <simulation/solarsystem/asteroids/gcasteroidgeneratorslab.meta.h>
#include <simulation/solarsystem/asteroids/gcasteroidgeneratorsurround.meta.h>
#include <simulation/solarsystem/planet/gcplanetweathercolourdata.meta.h>

SKYSCRAPER_BEGIN

struct HDRConfig
{
    float mfToneMapExposure;
    float mfHDRExposure;
    float mfHDRThreshold;
    float mfHDROffset;
};

class cGcPresetDualPMap
{
    cTkSmartResHandle mFront;
    cTkSmartResHandle mBack;
    TkStrongType<int, TkStrongTypeIDs::cTkNGuiFontHandleID> mPreview;
    cGcPlanetWeatherColourData mWeather;
    float mfIntensity;
    cTkVector3 mLightDirection;
    cTkFixedString<32, char> mName;
};

class cGcPresetTerrainTexture
{
    cTkSmartResHandle mTerrainMaterial;
    cTkSmartResHandle mTextureDiffuseRes;
    cTkSmartResHandle mTextureNormalRes;
    std::array<cTkColour, 20> maAverageColour;
    cTkFixedString<32, char> mName;
    cTkFixedString<128, char> mFilename;
};

class cGcApplicationScratchpadState : public cGcApplicationState
{
  public:
    struct CustomData
    {
        float mfAsteroidSize;
        cTkSphere mPlacement;
        cGcAsteroidLayout mLayout;
        cTkVector<cGcAsteroidGeneratorRing> mGeneratorRings;
        cTkVector<cGcAsteroidGeneratorSurround> mGeneratorSurrounds;
        cTkVector<cGcAsteroidGeneratorSlab> mGeneratorSlabs;
    };

    struct StateData
    {
        float mfTime;
        HDRConfig mHDRConfig;
        bool mPause;
        bool mbFrontend;
        cTkSmartResHandle mUberShader;
        cTkColour mBGColour;
        cTkVector<cGcPresetDualPMap> mPmaps;
        cTkVector<cGcPresetTerrainTexture> mTerrainTextures;
        std::array<cTkColour, 19> maTerrainColours;
        int miCurrentTerrainTextureSmall;
        cTkSmartResHandle mUITextureRes;
        cTkSmartResHandle mUIMaskTextureRes;
        cTkDynamicTexture mUITexture;
        cTkDynamicTexture mUIMaskTexture;
        cTkSmartResHandle mUIMaterial;
        cTkSmartResHandle mSkyMaterial;
        cTkSmartResHandle mPostProcessMaterial;
        cTkSmartResHandle mTerrainMaterial;
        cTkMatrix44 mDebugProjMatrix;
        cTkMatrix44 mDebugViewMatrix;
        cTkVector3 mvDebugRenderOffset;
    };

    std::unique_ptr<cGcApplicationScratchpadState::CustomData> mCustomData;
    std::unique_ptr<cGcApplicationScratchpadState::StateData> mStateData;

    virtual ~cGcApplicationScratchpadState() { EMPTY_CALL_DESTRUCTOR(); }
    virtual void Construct();
    virtual void Prepare(cTkFSMState *, const void *);
    virtual void Update(float);
    virtual void Event(unsigned int, const void *);
    virtual void Release(cTkFSMState *, const void *);
    virtual void Destruct();
    virtual void Render(EgRenderParity::List);
};

SKYSCRAPER_END