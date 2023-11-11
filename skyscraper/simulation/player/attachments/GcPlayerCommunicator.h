#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

class cGcPlayerCommunicator
{
    typedef cGcFrontendManager::eState cGcPlayerCommunicator::eState;

    class cGcPlayerCommunicatorSignal
    {
        cGcPlayerCommunicatorMessage mMessage;
        std::pair<TkID<128>, cTkSeed> mIDSeed;
        cTkAttachment *mpAttachment;
    };

    cGcPlayerCommunicatorSignal mSignal;
    TkHandle mActiveNode;
    cGcInteractionComponent *mpActiveInteraction;
    cGcNPCComponent *mpActiveNPC;
    cGcPlayerCommunicator::eState meState;
    float mfActiveTime;
    bool mbAutoOpen;
    cGcPlayerCommunicatorMessage mDebugMessage;
    cGcPlayerCommunicatorSignal mTakeOffCommunicatorSignal;
};

SKYSCRAPER_END