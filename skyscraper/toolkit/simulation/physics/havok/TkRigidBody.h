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
#include <toolkit/utilities/TkArray.h>

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
    __int64 miUniqueID;
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
        __int8 mbTransformDirty : 1;
        __int8 mbLinVelDirty : 1;
        __int8 mbAngVelDirty : 1;
        __int8 mbActivate : 1;
        __int8 mbRebuildCaches : 1;
        __int8 mbConvertToKeyframed : 1;
        __int8 mbUpdatePrePhysics : 1;
        __int8 mbUpdateContact : 1;
        __int8 mbReintegrateMotion : 1;
        __int8 mbDisableContactResponse : 1;
        __int8 mbEnableContactResponse : 1;
        __int8 mbStatic : 1;
        __int8 mbKeyframed : 1;
        __int8 mbInWorld : 1;
    } mFlags;
};

class cTkRigidBody
{
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
    unsigned __int64 miUniqueID;
    TkHandle mNode;
    unsigned int miIndex;
    float mfMaxClimbableSlopeDegrees;
    float mfMaxLinearSpeed;
    unsigned __int16 miFilterGroup;
    unsigned __int16 miFilterMask;
    cTkBitArray<unsigned int, 32> mKinematicFlags;

    struct
    {
        __int8 mbIsTerrain : 1;
        __int8 mbHasContacts : 1;
        __int8 mbUseCharacterPhysics : 1;
        __int8 mbFlipBackfacingCollisions : 1;
        __int8 mbHasForcedMassProps : 1;
        __int8 mbIsTriggerVolume : 1;
        __int8 mbIsTriggered : 1;
        __int8 mbCollidesWithPlayerVehicle : 1;
        __int8 mbDestroyedByPlayerVehicle : 1;
        __int8 mbDestroyedByPlayerShip : 1;
        __int8 mbDisableContactCaching : 1;
        __int8 mbCameraInvisible : 1;
        __int8 mbMarkedAsPlayerShip : 1;
        __int8 mbMarkedAsNoShipCollide : 1;
        __int8 mbMarkedAsPlayerVehicle : 1;
        __int8 mbClimbable : 1;
        __int8 mbRagdoll : 1;
    } mFlags;

    eBodyOwnerType mBodyOwnerType;
};

SKYSCRAPER_END