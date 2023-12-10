/**
 * @file GcInWorldScreen.h
 * @author VITALISED & Contributors
 * @since 2023-12-11
 *
 * Copyright (C) 2023  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <skyscraper.h>

#include <graphics/ngui/GcNGuiLayer.h>
#include <toolkit/graphics/2d/ngui/TkNGuiInput.h>
#include <toolkit/graphics/2d/texture/TkDynamicTexture.h>
#include <toolkit/maths/geometry/TkPhysRelMat34.h>
#include <toolkit/maths/numeric/TkSmoothCD.h>

#include <simulation/player/gchand.meta.h>

SKYSCRAPER_BEGIN

class cGcInWorldButton
{
  public:
    enum State
    {
        Disabled,
        Initialising,
        Ready,
        Pressing,
        Pressed,
        Held,
        Released,
    };

    cTkPhysRelMat34 mTransform;
    float mfScale;
    cTkSmoothCD<float> mfPressFactor;
    float mfClickTime;
    uint8_t meType[4];
    cGcInWorldButton::State meState;
    eHand meHand;
};

class cGcInWorldScreen
{
  public:
    cTkSmartResHandle mResource;
    cTkDynamicTexture mTexture;
    TkHandle mNode;
    TkHandle mNodeNonSimulation;
    TkHandle mLocatorNode;
    int miWidth;
    int miHeight;
    cTkNGuiInput mInput;
    cGcNGuiLayer *mpNGuiRoot;
    float mfFadeTarget;
    cTkSmoothCD<float> mFader;
    bool mbUsingFader;
    cTkVector2 mScreenWorldSizeOverride;
    cTkVector2 mWorldScale;
    cTkVector2 mCustomMargin;
    cTkVector2 mCursorPos;
    cGcInWorldButton mCursorButton;
    bool mbGotHitPoint;
    eHand meInteractHand;
    bool mbWasActive;
    bool mbActive;
    cTkPhysRelMat34 mCachedMat;
    cTkMatrix34 mInitialLocatorMatrix;
};

SKYSCRAPER_END