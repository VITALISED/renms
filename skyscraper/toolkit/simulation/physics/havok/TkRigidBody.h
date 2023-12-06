/**
 * @file TkRigidBody.h
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

#include <toolkit/core/types/TkHandle.h>
#include <toolkit/simulation/physics/TkPhysicsProperties.h>
#include <toolkit/simulation/physics/havok/TkCharacterRigidBody.h>
#include <toolkit/simulation/physics/havok/TkCollision.h>
#include <toolkit/simulation/physics/havok/TkRigidBodyGameplayFlags.h>
#include <toolkit/utilities/containers/TkBitArray.h>

SKYSCRAPER_BEGIN

class cTkPhysicsComponent;
class cTkStaticPhysicsComponent;

enum eBodyOwnerType
{
    HumanPlayer,
    NPC,
    Vehicle,
    Camera,
    NA,
};

class cTkRigidBodyPtr
{
    int miBodyIndex;
    int64_t miUniqueID;
};

class cTkRigidBodyProxy
{
    cTkPhysRelMat34 mTransform;
    cTkVector3 mvLinearVelocity;
    cTkVector3 mvAngularVelocity;
    cTkCharacterRigidBody *mpCharBody;
    unsigned int mBodyIdInt;
    int miIndex;

    struct
    {
        int8_t mbTransformDirty : 1;
        int8_t mbLinVelDirty : 1;
        int8_t mbAngVelDirty : 1;
        int8_t mbActivate : 1;
        int8_t mbRebuildCaches : 1;
        int8_t mbConvertToKeyframed : 1;
        int8_t mbUpdatePrePhysics : 1;
        int8_t mbUpdateContact : 1;
        int8_t mbReintegrateMotion : 1;
        int8_t mbDisableContactResponse : 1;
        int8_t mbEnableContactResponse : 1;
        int8_t mbStatic : 1;
        int8_t mbKeyframed : 1;
        int8_t mbInWorld : 1;
    } mFlags;
};

class cTkRigidBody
{
  public:
    hkVector4f mvFactor;
    hknpMassDistribution mMassDistribution;
    cTkPhysicsProperties mProperties;
    cTkRigidBodyProxy *mRigidBodyProxy;
    cTkCollision *mpCollision;
    cTkPhysicsComponent *mPhysicsComponent;
    cTkStaticPhysicsComponent *mpStaticPhysicsComponent;
    eTkRigidBodyGameplayFlags mxGameplayFlags;
    TkHandle miOrder1;
    TkHandle miOrder2;
    uint64_t miUniqueID;
    TkHandle mNode;
    unsigned int miIndex;
    float mfMaxClimbableSlopeDegrees;
    float mfMaxLinearSpeed;
    uint16_t miFilterGroup;
    uint16_t miFilterMask;
    cTkBitArray<unsigned int, true, 32> mKinematicFlags;

    struct
    {
        int8_t mbIsTerrain : 1;
        int8_t mbHasContacts : 1;
        int8_t mbUseCharacterPhysics : 1;
        int8_t mbFlipBackfacingCollisions : 1;
        int8_t mbHasForcedMassProps : 1;
        int8_t mbIsTriggerVolume : 1;
        int8_t mbIsTriggered : 1;
        int8_t mbCollidesWithPlayerVehicle : 1;
        int8_t mbDestroyedByPlayerVehicle : 1;
        int8_t mbDestroyedByPlayerShip : 1;
        int8_t mbDisableContactCaching : 1;
        int8_t mbCameraInvisible : 1;
        int8_t mbMarkedAsPlayerShip : 1;
        int8_t mbMarkedAsNoShipCollide : 1;
        int8_t mbMarkedAsPlayerVehicle : 1;
        int8_t mbClimbable : 1;
        int8_t mbRagdoll : 1;
    } mFlags;

    eBodyOwnerType mBodyOwnerType;
};

SKYSCRAPER_END