/**
 * @file GcCameraBehaviourGalacticNavigation.h
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

#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/graphics/camera/behaviours/TkCameraBehaviour.h>
#include <toolkit/maths/numeric/TkSmoothCD.h>
#include <toolkit/utilities/containers/TkStackContainer.h>

SKYSCRAPER_BEGIN

class cGcCameraBehaviourGalacticNavigation : public cTkCameraBehaviour
{
  public:
    enum ControlMode
    {
        EControl_User,
        EControl_ZoomOut,
        EControl_ZoomIn,
        EControl_FlyTo,
        EControl_LookAt,
        EControl_LookAtHold,
        EControl_Disabled,
    };

    enum Event
    {
        FlyToFinished,
        LookAtFinished,
    };

    cGcCameraBehaviourGalacticNavigation::ControlMode mControlMode;
    float mfTimeStable;
    cTkSmoothCD<float> mGizmoBlend;
    cTkMatrix34 mGizmoMatrix;
    cTkVector3 mGizmoZoomOffset;
    uint8_t meGizmoState[4];
    float mfGizmoZoomAccumulator;
    float mfZoomOutT;
    float mfElev;
    float mfElevTarget;
    cTkVector2 mvPan;
    cTkVector2 mvPanTarget;
    float mfRotate;
    float mfRotateTarget;
    float mfHeight;
    float mfHeightTarget;
    TkAudioObject mHostAudioObject;
    float mfFlyRate;
    float mfTimeToSmoothToFlatHorizontalLock;
    cTkVector3 mvDrift;
    float mfDriftT;
    float mfShakeInfluence;
    float mfTravelSpeed;
    cTkVector3 mvLockedTarget;
    cTkVector3 mvLockedOrigin;
    cTkVector3 mvLockedPt;
    cTkVector3 lLockedOffset;
    float mfSpin;
    float mfPush;
    cTkStackVector<cGcCameraBehaviourGalacticNavigation::Event, 4> mEvents;
    float mfLockTransition;
    bool mbLocked;
    bool mbHandMovementActive;
    cTkMatrix34 mHandMovementStartMatrix;
    bool mbFlyingFasterToggled;
    bool mbUserPushingSelection;
    cTkVector3 mvLookAtPoint;
};

SKYSCRAPER_END