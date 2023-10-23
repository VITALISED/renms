#pragma once

#include <skyscraper.h>
#include <application/states/GcApplicationState.h>
#include <graphics/ngui/GcNGuiLayer.h>
#include <graphics/ngui/GcNGuiGraphic.h>
#include <graphics/ngui/GcNGuiTextSpecial.h>
#include <toolkit/graphics/ngui/TkNGuiInput.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <atlas/WinHttpTask.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/system/TkUserServiceNotifications.h>

SKYSCRAPER_BEGIN

namespace TitleScreenPhase
{
    typedef WinHttpTask::State::Enum Enum;
}


class cGcApplicationTitleScreenState : public cGcApplicationState, public ITkUserServiceNotifications
{
    struct State
    {
        TkAudioObject mAudioObject;
    };

    cGcNGuiLayer *mpTitleUIRoot;
    cGcNGuiLayer *mpUserDetails;
    cGcNGuiTextSpecial *mpPlayerName;
    cGcNGuiGraphic *mpPlayerIcon;
    cTkSmartResHandle mhPlayerIconTexture;
    cGcApplicationTitleScreenState::State mState;
    TitleScreenPhase::Enum mPhase;
    cTkNGuiInput mTitleGuiInput;
    float mfAppearFade;
    TkStrongType<int,TkStrongTypeIDs::TkResHandleID> mPipelineResource;
    cTkVector<bool> maPreviousPipelineStageState;
};

SKYSCRAPER_END