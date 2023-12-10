/**
 * @file GcCameraBehaviourShipWarp.h
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

#include <graphics/camera/GcGameCamera.h>
#include <toolkit/maths/geometry/TkAABB.h>

#include <graphics/camera/follow/gccamerafollowsettings.meta.h>

SKYSCRAPER_BEGIN

class cGcCameraBehaviourShipWarp : public cGcGameCamera
{
  public:
    struct sSpinData
    {
        enum eSpinType
        {
            ESpin_Left,
            ESpin_Right,
            ESpin_NumTypes,
        };

        cTkSmoothCD<float> mfAngle;
        long double mf64LastInputTime;
        long double mf64SpinStartTime;
        float mfAngleTarget;
        int miSpinInputCountdown;
        cGcCameraBehaviourShipWarp::sSpinData::eSpinType meLastSpinInput;
        bool mbPressed;
        bool mbSpinAllowed;
    };

    cTkAABB mShipAABB;
    cTkPhysRelMat34 mShipMatrix;
    cGcCameraFollowSettings mFollowSettings;
    cGcCameraBehaviourShipWarp::sSpinData mSpinData;
};

SKYSCRAPER_END