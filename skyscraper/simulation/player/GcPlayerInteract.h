/**
 * @file GcPlayerInteract.h
 * @author VITALISED & Contributors
 * @since 2023-12-07
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

#include <graphics/hud/elements/GcHUDMarker.h>
#include <graphics/ngui/GcNGuiManager.h>
#include <simulation/environment/scanning/GcSimpleScanEffect.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/simulation/physics/TkRaycastJob.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>

SKYSCRAPER_BEGIN

class cGcPlayer;

enum ePlayerInteraction
{
    EPlayerInteraction_None = 0xFFFFFFFF,
    EPlayerInteraction_HoldButton,
    EPlayerInteraction_Shoot,
    EPlayerInteraction_Tap,
    EPlayerInteraction_NumTypes,
};

enum ePlayerInteractIcon
{
    EPlayerInteractIcon_Hold,
    EPlayerInteractIcon_Mine,
    EPlayerInteractIcon_Shoot,
    EPlayerInteractIcon_Deconstruct,
    EPlayerInteractIcon_Armour,
    EPlayerInteractIcon_NumTypes,
};

class cGcTargetHelper
{
  public:
    struct InteractLabelMarker
    {
        cTkRigidBodyPtr mpBody;
        /*cGcCreatureComponent*/ uintptr_t *mpCreature;
        TkHandle mLocator;
        bool mbTerrainResource;
    };
    ePlayerInteraction meTargetType;
    cTkAttachmentPtr mpCurrentTarget;
    cGcTargetHelper::InteractLabelMarker mCurrentTargetHelper;
    float mfFocusTargetTimer;
    bool mbValidInteraction;
    bool mbTargetInfoDynamic;
    ePlayerInteractIcon meIconType;
    cTkFixedString<127, char> mTargetName;
    cTkFixedString<256, char> mTargetSubtitle;
    cTkColour mTargetSubtitleColour;
    cTkFixedString<256, char> mTargetSubtitle2;
    cTkColour mTargetSubtitle2Colour;
    cTkPhysRelVec3 mLabelWorldPos;
    cTkVector4 mLabelScreenPos;
    cGcSimpleScanEffect mHighlight;
    cGcScanEffectData mHighlightData;
    TkHandle mHandInteractLight;
    float mfHandInteractLightIntensity;
    cTkSmoothCD<float> mHandInteractLightActiveFactor;
    float mfHandInteractLightActiveTarget;
    cTkVector4 mLabelScreenPosLeft;
    cTkVector4 mLabelScreenPosRight;
    cTkRaycastJob mRaycastJob;
};

class cGcPlayerInteract
{
  public:
    enum eHoldMode
    {
        EHoldMode_None,
        EHoldMode_DisplayInteraction,
        EHoldMode_Interacting,
        EHoldMode_Interacted,
        EHoldMode_Deleting,
    };

    enum eShootMode
    {
        EShootMode_None,
        EShootMode_Display,
    };

    enum eTapMode
    {
        ETapMode_None,
        ETapMode_Tapping,
        ETapMode_Done,
    };

    cGcPlayer *mpPlayer;
    cGcNGui mHoldGui;
    cGcTargetHelper mHoldHelper;
    cTkAttachmentPtr mpHoldTarget;
    cTkAttachmentPtr mpInteraction;
    TkHandle mHoldModel;
    TkHandle mHoldMasterModel;
    cGcPlayerInteract::eHoldMode meHoldMode;
    float mfHoldTimer;
    float mfErrorTimer;
    cGcMarkerRenderData mRenderData;
    cTkSmoothCD<float> mfHoldAlpha;
    cTkVector3 mNetworkLockPosition;
    bool mNetworkLockRequested;
    bool mbCanPickupHoldTarget;
    int meHoldInteractButton;
    cTkPhysRelVec3 mHandHoldStartPos;
    cTkVector3 mHandHoldDirOffset;
    bool mbHandHoldActive;
    bool mbHoldComplete;
    float mfLastGrabbableTargetTime;
    cGcSimpleScanEffect mDeconstructEffect;
    cGcNGui mShootGui;
    cGcTargetHelper mShootHelper;
    cTkRigidBodyPtr mpShootTarget;
    cGcPlayerInteract::eShootMode meShootMode;
    float mfShootHealth;
    cTkSmoothCD<float> mfShootAlpha;
    cGcTargetHelper mTapHelper;
    cGcPlayerInteract::eTapMode meTapMode;
    bool mbTapUp;
    TkAudioObject mAudioObject;
    bool mbHideOnRender;
    bool mbAllowedToInteractBasedOnVehicle;
    TkHandle mViewTarget;
    cTkRaycastJob mViewTargetRaycast;
};

SKYSCRAPER_END