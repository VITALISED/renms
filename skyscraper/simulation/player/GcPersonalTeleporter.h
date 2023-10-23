#pragma once

#include <skyscraper.h>
#include <atlas/WinHttpTask.h>
#include <toolkit/maths/geometry/TkPhysRelMat34.h>
#include <toolkit/attachments/TkHandle.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>
#include <metadata/simulation/player/gchand.meta.h>

SKYSCRAPER_BEGIN

// i honestly dont even want this to be here, but here we are
class cGcPlacementArc
{
    typedef WinHttpTask::State::Enum TargetStatus;

    cGcPlacementArc::TargetStatus meTargetStatus;
    cTkPhysRelMat34 mPrevAimMatrix;
    cTkPhysRelMat34 mAimMatrix;
    cTkPhysRelVec3 mTargetPosition;
    TkHandle mLadderNode;
    cTkVector3 mTargetNormal;
    cTkRigidBody *mpTargetBody;
    eHand meHand;
    float mfRange;
    cTkRaycastJob mRayJob;
};

SKYSCRAPER_END