/**
 * @file TkHavokDynamicCharacterController.h
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

#include <toolkit/simulation/physics/havok/TkCollision.h>
#include <toolkit/simulation/physics/havok/TkPhysicsConstraint.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>

SKYSCRAPER_BEGIN

// TODO: fix havok stuff
class cTkHavokCharacterController /*: hknpAction*/
{
    uintptr_t __vft;
    cTkCollision mCollision;
    cTkRigidBody *mpRigidBody;
    cTkPhysicsConstraint *mpConstraint;
    hkRefPtr</*hknpConvexShape*/ uintptr_t> mpPureShape;
    hknpBodyId mBodyId;
    cTkVector3 mTargetVelocity;
    cTkVector3 mPushVelocity;
    float mfPushVelocityDecay;
    bool mbOnGround;
    float mfMaxSlopeAngle;
    float mfMaxWalkableSlopeAngle;
    float mfClimbableStickinessAngle;
    float mfGravity;
    float mfMaxFallSpeed;
    bool mbInWorld;
    bool mbStepping;
    bool mbClingToTerrain;
};

SKYSCRAPER_END