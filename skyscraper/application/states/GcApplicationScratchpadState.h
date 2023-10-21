#pragma once

#include <skyscraper.h>
#include <application/states/GcApplicationState.h>
#include <toolkit/maths/geometry/TkSphere.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/graphics/2d/texture/TkDynamicTexture.h>
#include <simulation/solarsystem/asteroid/GcAsteroidLayout.h>
#include <simulation/GcPresetDualPMap.h>
#include <simulation/GcPresetTerrainTexture.h>
#include <metadata/simulation/solarsystem/asteroids/gcasteroidgeneratorring.meta.h>
#include <metadata/simulation/solarsystem/asteroids/gcasteroidgeneratorslab.meta.h>
#include <metadata/simulation/solarsystem/asteroids/gcasteroidgeneratorsurround.meta.h>

SKYSCRAPER_BEGIN

struct HDRConfig
{
    float mfToneMapExposure;
    float mfHDRExposure;
    float mfHDRThreshold;
    float mfHDROffset;
};

class cGcApplicationScratchpadState : public cGcApplicationState
{
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
        std::array<cTkColour,19> maTerrainColours;
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
};

SKYSCRAPER_END