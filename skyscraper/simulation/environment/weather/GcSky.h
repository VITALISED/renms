/**
 * @file GcSky.h
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

#include <simulation/environment/weather/GcWeatherEffectInstance.h>
#include <simulation/environment/weather/GcWeatherHazardGiftManager.h>
#include <toolkit/maths/numeric/TkSmoothCD.h>
#include <toolkit/system/timer/TkTimeManager.h>
#include <toolkit/system/timer/TkTimer.h>

#include <simulation/environment/gcfogproperties.meta.h>
#include <simulation/environment/gclightshaftproperties.meta.h>
#include <simulation/environment/gcskyproperties.meta.h>
#include <simulation/environment/weather/gcweathereffect.meta.h>
#include <simulation/environment/weather/gcweatheroptions.meta.h>
#include <simulation/solarsystem/planet/gcplanetheavyairdata.meta.h>
#include <simulation/solarsystem/planet/gcplanetweathercolourdata.meta.h>

SKYSCRAPER_BEGIN

class cGcSky
{
  public:
    enum eStormState
    {
        EStormState_Inactive,
        EStormState_Warning,
        EStormState_TransitionIn,
        EStormState_Active,
        EStormState_TransitionOut,
        EStormState_NumStates,
    };

    enum eFlightFogState
    {
        EFlightFogState_FadeToFoot,
        EFlightFogState_OnFoot,
        EFlightFogState_FadeToFlight,
        EFlightFogState_InFlight,
    };

    enum ePhotoModeSunLock
    {
        EPhotoModeSunLock_None,
        EPhotoModeSunLock_Direction,
        EPhotoModeSunLock_TimeOfDay,
    };

    struct ClusterSpawn
    {
        const cGcWeatherEffect *mpWeatherEffect;
        int miEffectTypeIndex;
        int miResourceIndexOffset;
        float mfTimeLeft;
        bool mbFirstInCluster;
    };

    cGcWeatherHazardGiftManager mWeatherHazardGiftManager;
    cGcPlanetWeatherColourData mWeatherColours;
    cGcSkyProperties mSkyProperties;
    cGcFogProperties mFogProperties;
    cGcPlanetHeavyAirData mHeavyAirProperties;
    cGcLightShaftProperties mLightShaftProperties;
    cTkTimeManager::UTCFractional mLastWeatherUpdateTime;
    cTkSmartResHandle mCloudMaterial;
    cTkSmartResHandle mRainbowMaterial;
    cTkSmartResHandle mSkyMaterial;
    cTkSmartResHandle mStarsMaterial;
    cTkSmartResHandle mSkyDomeModel;
    cTkSmartResHandle mRainbowPlaneRes;
    TkHandle mSkyNode;
    TkHandle mStarfieldNode;
    TkHandle mRainbowPlaneNode;
    cTkFixedString<32, char> mFormattedTimeOfDay;
    uint64_t mu64SunTimeOffset;
    float mfSolarSunAngle;
    cTkVector3 mSunDirection;
    cTkVector3 mLightDirection;
    cTkVector3 mSunAxis;
    cTkVector3 mRelativeUp;
    float mfAudioLevel;
    float mfWeatherStrength;
    float mfWeatherFilterStrength;
    eWeather meLastKnownWeatherType;
    float mfScreenFilterTimer;
    float mafStormHazardModifiers[5];
    cGcSky::eStormState meStormState;
    float mfForceStormLength;
    uint64_t mu64ForceStormStart;
    cTkTimerTemplate<0> mRainFadeTimer;
    cTkTimerTemplate<0> mWetCaveFadeTimer;
    bool mbIsRaining;
    float mfWetness;
    cTkSmartResHandle mRainCylinderRes;
    TkHandle mRainCyclinderNode;
    TkHandle mRainCyclinderNode2;
    cTkSmoothCD<float> mfWeatherBloomInterpFactorGain;
    cTkSmoothCD<float> mfWeatherBloomInterpFactorThresh;
    float mfWeatherBloomImpulseDelay;
    bool mbIsInFlight;
    cGcSky::eFlightFogState meFlightFogState;
    float mfFlightTimer;
    float mfFlightFogStrength;
    float mfFlightHeightStrength;
    cTkSmoothCD<float> mfStormSpaceStrength;
    float mfSunsetBlend;
    float mfHorizonBlend;
    float mfSunColourBlend;
    float mfSunLightBlend;
    float mfLightColourBlend;
    cGcSky::ePhotoModeSunLock mePhotoModeSunLock;
    cTkVector3 mPhotoModeSunDirection;
    uint64_t mu64SunLockStartTime;
    float mCachedForwardScatter;
    float mCachedBackwardScatter;
    float mHenyeyBalancePoint;
    int muiTemporalCloudStep;
    float mfLightInterpolationTimer;
    uint64_t muiLastWeatherEffectUpdateTime;
    float mfMaxWeatherEffectDuration;
    cTkVector<cGcWeatherEffect const *> mapWeatherEffects;
    cTkVector<cGcWeatherEffect const *> mapWeatherHazards;
    cTkVector<cTkSmartResHandle> maWeatherEffectResources;
    cTkVector<cTkSmartResHandle> maWeatherHazardResources;
    cTkVector<cGcWeatherEffectInstance *> maActiveWeatherEffects;
    cTkVector<cGcSky::ClusterSpawn> maWeatherEffectClusterSpawns;
    cTkVector<cGcSky::ClusterSpawn> maWeatherHazardClusterSpawns;
    cGcRegionTerrain *mpCurrentPlayerRegion;
    float mfApproxRegionSize;
    std::vector<cGcSky::RegionUpdate> maUpdateRegions;
    int miFirstUpdateCounter;
    TkID<128> mDebugForceWeatherID;
    TkID<128> mLastDebugForceWeatherID;
    int miDebugForceWeatherCount;
};

SKYSCRAPER_END