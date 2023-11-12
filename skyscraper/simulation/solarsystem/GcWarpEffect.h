#pragma once

#include <skyscraper.h>

#include <simulation/player/GcPlayer.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/attachments/TkHandle.h>
#include <toolkit/maths/geometry/TkPhysRelMat34.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>

SKYSCRAPER_BEGIN

class cGcWarpEffect
{
    typedef cGcPlayer::eRocketBootsDoubleTapState eWarpState;

    enum eWarpType
    {
        WarpIn,
        WarpOut,
        FadeIn,
    };

    TkHandle mBaseNode;
    int miWarpInFrameCount;
    cTkMatrix34 mOriginOffset;
    float mfFrontOffset;
    float mfBackOffset;
    cTkPhysRelMat34 mOriginTransform;
    cGcWarpEffect::eWarpState meState;
    cGcWarpEffect::eWarpState meRequestedState;
    cTkAttachmentPtr mpAttachment;
    cTkVector3 mWarpInStart;
    float mfStartTime;
    float mfStartSpeed;
    bool mbWarpEffectPlayed;
    bool mbFlipWarpDirection;
};

SKYSCRAPER_END