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
#include <simulation/CharacterPhysicsDisabledReasons.h>
#include <simulation/components/utils/GcPlayerControlComponent.h>
#include <simulation/CharacterSlopeState.h>
#include <simulation/player/GcCharacterSit.h>
#include <networking/GcNetworkConstants.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>
#include <toolkit/maths/geometry/TkPhysRelMat34.h>
#include <toolkit/attachments/TkAttachment.h>
#include <metadata/reality/gcalienrace.meta.h>
#include <metadata/simulation/projectiles/gcdamagetype.meta.h>

SKYSCRAPER_BEGIN

typedef cGcNetworkConstants::OnlinePlatformType CharacterDeathReason;

class cGcCharacterInterface
{
	virtual ~cGcCharacterInterface();
	virtual bool IsPlayer();
	virtual bool IsReady();
	virtual bool IsLocalPlayer();
	virtual bool IsVRPlayer();
	virtual bool WeaponIsActive();
	virtual bool WeaponIsLarge();
	virtual bool BinocsActive();
	virtual bool IsHitReacting();
	virtual cTkVector2* GetHitReactDir(cTkVector2* result);
	virtual bool IsOnGround();
	virtual bool IsInSpace();
	virtual bool ShouldUseAbandonedFreighterWalk();
	virtual bool IsDying();
	virtual CharacterDeathReason GetDeathReason();
	virtual float GetEnergy();
	virtual float GetHazard();
	virtual bool IsJetpacking();
	virtual bool IsJetpackBoosted();
	virtual bool IsSliding();
	virtual bool IsRiding();
	virtual cTkAttachmentPtr* GetRidingAttachment(cTkAttachmentPtr* result);
	virtual bool GetHandPose(eHand, TkID<128>*, float*);
	virtual eHand GetDominantHand();
	virtual bool IsMeleeActive(eHand);
	virtual bool IsPointing(eHand);
	virtual bool IsInteracting(eHand);
	virtual bool IsMeleeBoostActive();
	virtual bool IsWaitingForRocketBootsActivation();
	virtual bool IsRocketBootsActive();
	virtual bool GetLocalTeleportDestination(cTkPhysRelMat34*);
	virtual float GetTimeLastUsedJetpack();
	virtual bool IsRunning();
	virtual bool IsUnderwater();
	virtual bool IsAtWaterSurface();
	virtual bool IsGrabbed();
	virtual bool IsMech();
	virtual bool HasMoveForce();
	virtual bool HasFired();
	virtual bool IsPilotingShip();
	virtual bool IsInVehicle();
	virtual bool HasCustomIdle();
	virtual TkID<128>* UpdateIdle(TkID<128>* result, float);
	virtual CharacterSlopeState GetSlopeState();
	virtual bool IsHandTracking(eHand);
	virtual cTkMatrix34* GetMatrix(cTkMatrix34* result);
	virtual cTkPhysRelMat34* GetPhysicsMatrix(cTkPhysRelMat34* result);
	virtual cTkPhysRelVec3* GetFootPosition(cTkPhysRelVec3* result);
	virtual cTkVector3* GetVelocity(cTkVector3* result);
	virtual cTkVector3* GetFacingDir(cTkVector3* result);
	virtual cTkVector3* GetWorldUp(cTkVector3* result);
	virtual float GetHeight();
	virtual eAlienRace GetRace();
	virtual cTkPhysRelVec3* GetAimPosition(cTkPhysRelVec3* result);
	virtual cTkVector3* GetCurrentMoveForce(cTkVector3* result);
	virtual void SetToPosition(const cTkPhysRelVec3*, const cTkVector3*, const cTkVector3*);
	virtual void SetToPosition(const cTkVector3*, const cTkVector3*, const cTkVector3*);
	virtual void EnableCharacterPhysics(bool);
	virtual void EnableCharacterCollision(eCharacterPhysicsDisabledReasons);
	virtual void DisableCharacterCollision(eCharacterPhysicsDisabledReasons);
	virtual void AttachControlMode(cGcPlayerControlComponent*);
	virtual void EnableCharacterGravity(eCharacterPhysicsDisabledReasons);
	virtual void DisableCharacterGravity(eCharacterPhysicsDisabledReasons);
	virtual cTkRigidBody* GetRigidBody();
	virtual cGcCharacterSit* GetCharacterSit();
	virtual void TakeDamage(float, eDamageType, const TkID<128>*, const cTkVector3*, cGcOwnerConcept*);
	virtual void SetPitch(float);
	virtual void SetRoll(float);
	virtual bool CanLookAt();
	virtual bool AllowHeadMovement();
	virtual cTkVector3* GetLookAtPoint(cTkVector3* result);
};


SKYSCRAPER_END