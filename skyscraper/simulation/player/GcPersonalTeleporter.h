/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <skyscraper.h>
#include <atlas/WinHttpTask.h>
#include <toolkit/maths/geometry/TkPhysRelMat34.h>
#include <toolkit/attachments/TkHandle.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>
#include <toolkit/simulation/physics/TkRaycastJob.h>
#include <metadata/simulation/player/gchand.meta.h>

SKYSCRAPER_BEGIN

// i honestly dont even want this to be here, but here we are
class cGcPlacementArc
{
    typedef WinHttpTask::State::Enum TargetStatus;

    cGcPlacementArc::TargetStatus meTargetStatus;
    cTkPhysRelMat34 mPrevAimMatrix;
    cTkPhysRelMat34 mAimMatrix;
    cTkPhysRelVec3 mTargetPosition;
    TkHandle mLadderNode;
    cTkVector3 mTargetNormal;
    cTkRigidBody *mpTargetBody;
    eHand meHand;
    float mfRange;
    cTkRaycastJob mRayJob;
};

class cGcPersonalTeleporter
{
    enum eTeleporterState
    {
        ETeleporterState_Ready,
        ETeleporterState_Charging,
        ETeleporterState_Charged,
        ETeleporterState_Teleporting,
        ETeleporterState_Canceling,
    };

    cGcPlacementArc mPlacementArc;
    TkHandle mEndEffectNode;
    TkHandle mEndEffectDirection;
    TkHandle mTravelEffect;
    TkHandle mTravelEffectActive;
    TkHandle mTravelEffectBlocked;
    TkHandle mTravelEffectBehind;
    TkHandle mTravelEffectComplete;
    TkHandle mEndEffectActive;
    TkHandle mEndEffectBlocked;
    cTkPhysRelVec3 mInitialPosition;
    cTkVector2 mInitialTargetDirection;
    cTkVector2 mTargetDirection;
    cGcPersonalTeleporter::eTeleporterState meState;
    float mfMovementTime;
    float mfChargeTime;
    float mfFadeTime;
    float mfTeleportTime;
    float mfLastSnapTurnImpulse;
    bool mbWantsTeleport;
    bool mbValidLastFrame;
    bool mbTeleported;
    bool mbAdjustFacing;
    bool mbDrawArc;
    bool mbOffHandSetsDirection;
};


SKYSCRAPER_END