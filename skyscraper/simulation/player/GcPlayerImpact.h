#pragma once

#include <skyscraper.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>
#include <metadata/messages/gcmessageprojectileimpact.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerImpact
{
	cGcMessageProjectileImpact mData;
	cTkVector3 mScreenPos;
	int miDamage;
	float mfTime;
	cTkRigidBodyPtr mpPhysics;
	cTkVector3 mPhysicsOffset;
};

SKYSCRAPER_END