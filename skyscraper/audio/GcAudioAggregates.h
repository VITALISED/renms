/**
 * @file GcAudioAggregates.h
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

#include <toolkit/audio/TkAudioManager.h>
#include <toolkit/maths/geometry/TkSphere.h>
#include <toolkit/simulation/physics/TkRaycastJob.h>
#include <toolkit/utilities/containers/TkStackContainer.h>
#include <toolkit/utilities/random/TkPersonalRNG.h>

SKYSCRAPER_BEGIN

class ShorelineAudio
{
  public:
    void Update(float lfTimeStep);

    struct ShorelinePoint
    {
        cTkVector3 mPos;
        float mfObstruction;
        float mfValidity;
        bool mbValid;
    };

    cTkPersonalRNG mRNG;
    int miRayIndexLast;
    int miRayIndexNext;
    float mfSmoothedRTPC;
    float mfSmoothedObstruction;
    float mfVolumeRate;
    float mfObstructionRate;
    std::array<ShorelineAudio::ShorelinePoint, 12> mPoints;
    cTkRaycastJob mRaycastJob;
    TkAudioObject mAudioObject;
    unsigned int mUID;
};

class cGcDopplerRequest
{
  public:
    cTkVector3 mSourceCurrentPosition;
    cTkVector3 mSourcePreviousPosition;
    TkAudioObject mAudioObject;
    TkAudioID mDopplerRTPC;
    float mDopplerFactor;
};

class cGcAudioObstructionRequest
{
  public:
    uint64_t mu64Tag;
    cTkFixedString<32, char> mDebugName;
    float mfEffectDistanceCutout;
    cTkSphere mProbeEmissionVolume;
    cTkStackVector<TkAudioObject, 4> mAudioObjects;
    float mObstructionValue;
    float mObstructionRate;
    bool mbFirstUse;
    bool mbUseAuxSend;
};

SKYSCRAPER_END