#pragma once

#include <skyscraper.h>
#include <toolkit/maths/geometry/TkPhysRelMat34.h>

SKYSCRAPER_BEGIN

class cTkPhysicsProperties
{
    cTkPhysRelMat34 mStartTransform;
    float mfMass;
    float mfDensity;
    float mfFriction;
    float mfRollingFriction;
    float mfAngularDamping;
    float mfLinearDamping;
    float mfGravity;
    bool mbKeyframed;
};

SKYSCRAPER_END