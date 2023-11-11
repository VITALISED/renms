#pragma once

#include <skyscraper.h>

#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>

SKYSCRAPER_BEGIN

class cGcPlayer;

class cGcPlayerLadderClimb
{
    enum State
    {
        OffLadder,
        OnLadder,
        Exiting,
    };

    cGcPlayer *mpPlayer;
    bool mIsOnLadder;
    cTkMatrix34 mStartLocation;
    cTkMatrix34 mTargetLocation;
    cTkMatrix34 mTopEndPoint;
    cTkMatrix34 mBottomEndPoint;
    float mTimeInTransition;
    cGcPlayerLadderClimb::State meState;
};

SKYSCRAPER_END