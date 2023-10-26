#pragma once

#include <skyscraper.h>
#include <toolkit/simulation/physics/havok/TkCollision.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>

SKYSCRAPER_BEGIN

class cGcRegionDecoratorPhysics
{
    cTkCollision **mapCollision;
    cTkRigidBody **mapRigidBody;
    __int16 miCollisionCount;
    __int16 miCollisionCapacity;
    __int16 miRigidBodyCount;
    __int16 miRigidBodyCapacity;
    bool mbInWorld;
};

SKYSCRAPER_END