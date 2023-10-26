#pragma once

#include <skyscraper.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>

SKYSCRAPER_BEGIN

class cTkCharacterRigidBody
{
    uintptr_t __vft; //TODO: implement havok bullshit
    hkVector4f mvGroundNormal;
    cTkVector3 mvGroundSurfaceVelocity;
    bool mbOnGround;
    bool mbOnClimbable;
    float mfDeltaTime;
    bool mbAssertOnCheckSupport;
    bool mbClimbsClimbableSurfaces;
};

SKYSCRAPER_END