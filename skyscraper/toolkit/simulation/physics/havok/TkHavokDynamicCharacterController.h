#pragma once

#include <skyscraper.h>
#include <toolkit/simulation/physics/havok/TkCollision.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>
#include <toolkit/simulation/physics/havok/TkPhysicsConstraint.h>

SKYSCRAPER_BEGIN

//TODO: fix havok stuff
class cTkHavokCharacterController /*: hknpAction*/
{
	uintptr_t __vft;
	cTkCollision mCollision;
	cTkRigidBody* mpRigidBody;
	cTkPhysicsConstraint* mpConstraint;
	hkRefPtr</*hknpConvexShape*/uintptr_t> mpPureShape;
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