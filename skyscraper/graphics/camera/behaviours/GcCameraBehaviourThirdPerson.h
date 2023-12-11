/**
 * @file GcCameraBehaviourThirdPerson.h
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
#include <toolkit/simulation/physics/TkRaycastJob.h>

#include <graphics/camera/follow/gccamerafollowsettings.meta.h>

SKYSCRAPER_BEGIN

class cGcCameraBehaviourThirdPerson : public cGcGameCamera
{
  public:
    struct DisplayNumber
    {
        const char *mpacName;
        float mfNumber;
    };

    cGcPlayerStick mFollowLookStick;
    cTkSmoothCD<float> mfFovFixedDist;
    cTkPhysRelVec3 mvFollowPosWorld;
    cTkPhysRelVec3 mvFollowPrevCenter;
    cTkPhysRelVec3 mvFollowPrevActCenter;
    cTkVector3 mFollowPrevAt;
    cTkVector3 mvFollowCenterVel;
    cTkVector3 mvVelAnticipateVector;
    cTkVector3 mvVelAnticipateVectorVel;
    float mfFollowRotation;
    float mfFollowVertRotation;
    float mfFollowRotationVel;
    float mfFollowVertRotationVel;
    float mfFollowDistance;
    float mfFollowStickDist;
    float mfFollowCollisionPush;
    float mfOffsetXCollisionPush;
    float mfSlopeFollowAdjustFactor;
    float mfSlopeFollowAdjustFactorVel;
    float mfSlopeRotationAdjustFactor;
    float mfSlopeRotationAdjustFactorVel;
    cTkSmoothCD<float> mfCloseFactor;
    cTkSmoothCD<float> mfVertRotationWaterClamp;
    float mfFollowCenterTouchedTime;
    float mfFollowVertTouchedTime;
    float mfFollowZoomTouchedTime;
    cTkRaycastJob mCameraCollisionJob;
    float mfPrevProbeExtraDistance;
    cGcPlayerCameraLook mCameraLook;
    cTkSmoothCD<float> mFoVSpring;
    cTkSmoothCD<float> mDistMulSpring;
    cTkSmoothCD<float> mYawOffsetSpring;
    cTkSmoothCD<float> mPitchAroundCamOffsetSpring;
    cTkSmoothCD<float> mSmoothCreatureHeight;
    float mfCreatureFollowVertRotationVel;
    bool mbWasInCreatureInteraction;
    cTkVector<cGcCameraBehaviourThirdPerson::DisplayNumber> maNumbers;
    cGcCameraFollowSettings mCurrentFollowSettings;
    cGcCameraFollowSettings mTargetFollowSettings;
    cGcCameraFollowSettings mLastTargetFollowSettings;
    float mfFollowSettingsBlendTimer;
    bool mbSnapIntoPosition;
    /*cGcOutpostComponent*/ uintptr_t *mpOldDockNode;
};

SKYSCRAPER_END