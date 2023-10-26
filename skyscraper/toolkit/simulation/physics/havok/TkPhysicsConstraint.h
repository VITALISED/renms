#pragma once

#include <skyscraper.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>

SKYSCRAPER_BEGIN

class cTkPhysicsConstraint
{	
	bool mbActive;
	bool mbDisableBodyCollision;
	cTkRigidBody* mpBodyA;
	cTkRigidBody* mpBodyB;
	hknpConstraintId miConstraintId;
	//hknpRagdollConstraintData* mpConstraintData;
	uintptr_t mpConstraintData; //TODO: fix havok stuff

	virtual ~cTkPhysicsConstraint();
	virtual void Activate();
	virtual void Deactivate();
};

SKYSCRAPER_END