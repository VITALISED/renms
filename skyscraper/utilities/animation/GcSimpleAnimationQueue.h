#pragma once

#include <skyscraper.h>

#include <toolkit/animation/engine/TkNodeAnimationControllerEngine.h>
#include <toolkit/data/TkMetaData.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cGcSimpleAnimationQueue
{
    struct SimpleAnimNode
    {
        TkID<128> mAnimName;
        float mfPlayTime;
        float mfTotalTime;
        float mfBlendInTime;
        float mfBlendOutTime;
        float mfCrossFadeTime;
        float mfSpeed;
        bool mbStartedPlaying;
        std::function<void __cdecl(float)> mProgressFunc;
    };

    cTkVector<cGcSimpleAnimationQueue::SimpleAnimNode> mAnimationQueue;
    TkID<128> mLayerName;
    cTkAnimLayerHandle mLayerHandle;
    int miLayerPriority;
};

SKYSCRAPER_END