/**
 * @file GcPlayerStick.h
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

#include <gamestate/GcUserSettings.h>
#include <simulation/player/controllers/GcPlayerController.h>
#include <toolkit/maths/numeric/TkSmoothCD.h>

#include <simulation/player/gcplayerstickdata.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerStick
{
  public:
    cGcPlayerController *mpController;
    cGcPlayerStickData *mpData;
    int miXAxis;
    int miYAxis;
    cTkVector2 mBaseStick;
    cTkSmoothCD<cTkVector2> mLastStickDir;
    cTkVector3 mLastInput;
    float mfAcceleration;
    float mfAccelerationTimer;
    cGcUserSettings::Sensitivity meSensitivityType;
    cTkVector2 mMousePos;
    float mfAutoAimStickyFactor;
    cTkColour mNormalRateColour;
    cTkColour mAcceleratedRateColour;
    cTkVector2 mDebugScreenCircleCentre;
    float mfDebugScreenCircleRadius;
    float mfDebugScreenCircleRadiusInner;
    cTkVector2 mGyroChanges;
    int miSmoothingIndex;
    cTkVector2 maSmoothingGyroBuffer[16];
    float mfSpecialVehicleMouseRecentreTimer;
};

SKYSCRAPER_END