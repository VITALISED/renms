#pragma once

#include <skyscraper.h>
#include <toolkit/graphics/ngui/TkNGuiInput.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <graphics/ngui/GcNGuiLayer.h>

SKYSCRAPER_BEGIN

class cGcLayerInteractControl
{
    enum eConfirmState
    {
        EConfirmState_None,
        EConfirmState_Confirming,
        EConfirmState_Confirmed,
    };

    typedef cGcPlayer::eRocketBootsDoubleTapState WhichButton;

    cTkNGuiInput *mpNGuiInput;
    cGcNGuiLayer *mpConfirm;
    float mfConfirmTime;
    cGcLayerInteractControl::eConfirmState meConfirmState;
    cGcLayerInteractControl::WhichButton meWhichButton;
    cGcNGuiLayer *mpHoverButton;
    TkAudioObject mAudioObject;
    bool mbPlayingHoldAudio;
    bool mbPlayingHoldAudioThisFrame;
    bool mbSlow;
};

SKYSCRAPER_END
