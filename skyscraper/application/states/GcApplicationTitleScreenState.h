/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

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