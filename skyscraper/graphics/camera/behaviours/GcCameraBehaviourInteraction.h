/**
 * @file GcCameraBehaviourInteraction.h
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

#include <graphics/camera/GcGameCamera.h>
#include <toolkit/attachments/TkAttachment.h>

SKYSCRAPER_BEGIN

class cGcCameraBehaviourInteraction : public cGcGameCamera
{
  public:
    enum eMode
    {
        EMode_NPCFocus,
        EMode_FromData,
        EMode_FrigateFocus,
        EMode_NPCFocusNoHologram,
    };

    cTkAttachmentPtr mpInteractionAttachment;
    cGcCameraBehaviourInteraction::eMode meMode;
    float mfModeTime;
    cTkPhysRelMat34 mPreviousModeTransform;
    cTkVector3 mFocusOffset;
    cTkVector3 mFocusDirection;
    bool mbValidFocus;
    float mfParallaxOffsetX;
    float mfParallaxOffsetY;
    cTkSmoothCD<float> mfSmoothPitchAdjust;
    cTkSmoothCD<float> mfLateralShift;
    cGcCameraDepthOfField mDepthOfField;
};

SKYSCRAPER_END