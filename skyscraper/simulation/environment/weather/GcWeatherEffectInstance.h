/**
 * @file GcWeatherEffectInstance.h
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

#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/core/types/TkHandle.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/utilities/random/TkPersonalRNG.h>

#include <simulation/environment/weather/gcweathereffect.meta.h>

SKYSCRAPER_BEGIN

class cGcWeatherEffectInstance
{
  public:
    struct sWanderArc
    {
        bool mbClockwise;
        float mfArcStartTime;
        float mfArcEndTime;
        float mfRadius;
        float mfStartAngle;
        float mfArc;
        cTkVector3 mvArcCenter;
        float mfMaxWanderFromSpawn;
        cTkPersonalRNG mWanderRNG;
    };
    const cGcWeatherEffect *mpWeatherEffect;
    cGcWeatherEffectInstance::sWanderArc mWanderArc;
    TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mEffectResource;
    TkHandle mEffect;
    cTkVector<cTkSmartResHandle> maResources;
    cTkVector<TkHandle> maNodes;
    cTkVector<TkAudioObject> maAudioObjects;
    float mfTimeAlive;
    float mfLifeTime;
    float mfSpawnOffset;
    cTkSeed mSeed;
    uint64_t muiSpawnTime;
    bool mbFirstInCluster;
    bool mbAudioFadeOutInitiated;
    cTkMatrix34 mSpawnMatrix;
};

SKYSCRAPER_END