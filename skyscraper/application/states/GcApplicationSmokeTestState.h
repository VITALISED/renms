/**
 * @file GcApplicationSmokeTestState.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
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

#include <application/states/GcApplicationSimulationState.h>
#include <toolkit/graphics/TkColour.h>
#include <toolkit/maths/geometry/TkPhysRelMat34.h>
#include <toolkit/maths/numeric/TkSmoothCD.h>

SKYSCRAPER_BEGIN

class cGcApplicationSmokeTestState : public cGcApplicationSimulationState
{
  public:
    cTkPhysRelMat34 mTransformForMovement;
    cTkPhysRelMat34 mTransformForLookAt;
    int miCurrentPlanet;
    int miNumPlanetsVisited;
    bool mbSpaceTravel;
    float mfSpaceTravelTimer;
    cTkSmoothCD<float> mfHeightSpring;
    bool mbHeightSpringSet;
    float mfInitialPauseLeft;
    float mfSmokeTestFlashTimeLeft;
    float mfGifTimeBetweenKeyframesLeft;
    int miFrames;
    float mfRightSunPosRandom;
    float mfUpSunPosRandom;
    float mfAtSunPosRandom;
    float mfPlanetFlightTimer;
    float mfPlanetFlightTimeoutTimer;
    cTkColour mFlashColour;
    float mfFullScreenFlashTimer;
    bool mbRenderFullScreenFlash;
    bool mbFinished;
    bool mbIsCompleted;
    bool mbIsExiting;
    cTkVector<float> mafLowMemoryWatermarks;

    virtual ~cGcApplicationSmokeTestState() { EMPTY_CALL_DESTRUCTOR(); }
    virtual void Construct();
    virtual void Prepare(cTkFSMState *, const void *);
    virtual void Update(float);
    virtual void Render(EgRenderParity::List);
    virtual void ThreadedUpdate();
    virtual bool ThreadSyncPoint();
};

SKYSCRAPER_END