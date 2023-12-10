/**
 * @file GcCameraBehaviourAerialView.h
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

#include <toolkit/core/types/TkHandle.h>
#include <toolkit/graphics/camera/behaviours/TkCameraBehaviour.h>

#include <graphics/camera/effects/gccameraaerialviewdata.meta.h>

SKYSCRAPER_BEGIN

class cGcCameraBehaviourAerialView : public cTkCameraBehaviour
{
  public:
    enum eViewTransition
    {
        EViewTransition_Inactive,
        EViewTransition_TransOut,
        EViewTransition_Pause,
        EViewTransition_TransBack,
    };

    cGcCameraBehaviourAerialView::eViewTransition meTransitionMode;
    int miTransitionStage;
    int miTransitionStages;
    int miWayBackStage;
    cTkMatrix34 mTransitionTarget;
    float mfTimer;
    TkHandle mSpeedLines;
    cGcCameraAerialViewData mData;
    cTkPhysRelMat34 mStartTransform;
};

SKYSCRAPER_END