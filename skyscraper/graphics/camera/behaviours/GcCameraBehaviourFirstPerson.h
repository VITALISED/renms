/**
 * @file GcCameraBehaviourFirstPerson.h
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

#include <graphics/camera/GcGameCamera.h>
#include <toolkit/core/types/TkHandle.h>

#include <simulation/player/gczoomdata.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayer;

class cGcCameraBehaviourFirstPerson : public cGcGameCamera
{
  public:
    cGcPlayer *mpPlayer;
    cTkPhysRelMat34 mPrevMatrix;
    cGcPlayerCameraLook mCameraLook;
    cTkMatrix34 mMotionMatrix;
    float mfTime;
    bool mbInstantSwitchFov;
    eZoomType meZoomLevel;
    float mfFovSpringSpeed;
    cTkSmoothCD<float> mfHeadRunTuck;
    float mfBobFactor;
    float mfBobStrength;
    float mfBobAmount;
    float mfPostVehicleExitTimer;
    bool mbInVehicle;
    bool mbShipFreeLook;
    cTkSmoothCD<float> mfFovFixedDist;
    TkHandle mCockpitNode;
};

SKYSCRAPER_END