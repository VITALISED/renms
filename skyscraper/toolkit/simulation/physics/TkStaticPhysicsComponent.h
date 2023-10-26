#pragma once

#include <skyscraper.h>
#include <toolkit/simulation/components/TkComponent.h>
#include <toolkit/simulation/physics/havok/TkCollision.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>
#include <metadata/toolkit/components/physics/tkstaticphysicscomponentdata.meta.h>

SKYSCRAPER_BEGIN

class cTkStaticPhysicsComponent : public cTkComponent
{
	cTkStaticPhysicsComponentData* mpData;
	cTkRigidBody mRigidBody;
	cTkCollision mCollision;
};

SKYSCRAPER_END