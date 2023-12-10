/**
 * @file GcPlayerThirdPerson.h
 * @author VITALISED & Contributors
 * @since 2023-12-06
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

#include <graphics/camera/behaviours/GcCameraBehaviourCharacter.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/maths/geometry/TkAABB.h>
#include <toolkit/maths/numeric/TkSmoothCD.h>

SKYSCRAPER_BEGIN

class cGcPlayer;

class cGcPlayerThirdPerson
{
  public:
    enum eCharacterVisibility
    {
        InvisibleOnAllClients,
        ShowOnlyLocally,
        ShowOnlyOnRemotes,
        ShowOnlyOnRemotesShowShadowLocally,
        ShowLocallyAndRemotes,
    };

    enum eMeshRefreshState
    {
        ReadyForRefresh,
        Generating,
        SwapMesh,
    };

    float mTimeInCurrentState;
    cGcPlayer *mpPlayer;
    cGcCameraBehaviourCharacter *mpThirdPersonCamera;
    /*cGcPlayerCharacterComponent*/ uintptr_t *mpCharacterComponent;
    cTkPhysicsComponent *mpPhysicsComponent;
    cTkSmartResHandle mThirdPersonModelRes;
    cTkSmartResHandle mBackpackModelRes;
    TkHandle mBackpackNode;
    TkHandle mThirdPersonNode;
    TkHandle mThirdPersonMeshNode;
    TkHandle mThirdPersonHeadMeshNode;
    TkHandle mThirdPersonHeadJointNode;
    TkHandle mWeaponNode;
    cTkVector<TkID<128>> maForcingMeshHidden;
    cTkVector<TkID<128>> maForcingMeshShown;
    cTkAABB mBackpackAABB;
    TkHandle maCharacterHoldingPoint[2];
    TkHandle maHandsNode[2];
    TkHandle maWristStumpNode[2];
    TkHandle maFingerPointNode[2];
    cTkMatrix34 maWristToController[2];
    cTkVector3 maWristToHoldingPoint[2];
    bool mabIsHandTracking[2];
    bool mbUsingHandControls;
    bool mbVRGhostMode;
    bool mbVRGhostModeChanged;
    bool mbForceMeshVisibilityUpdate;
    cGcPlayerThirdPerson::eCharacterVisibility mCurrentVisibility;
    bool mbShouldRefreshMesh;
    cGcPlayerThirdPerson::eMeshRefreshState mMeshRefreshState;
    cTkSmartResHandle mThirdPersonModelSwapRes;
    cGcPlayerThirdPerson::eMeshRefreshState mBackpackRefreshState;
    cTkSmartResHandle mBackpackSwapRes;
    cTkAttachment *mpAttachment;
    cTkVector3 mvLookAtPoint;
    float mfRoll;
    float mfPitch;
    float mfLookAtRunTimer;
    float mfLookAtGlanceTime;
    float mfLookAtTargetTimer;
    float mfLookAtTargetTime;
    cTkSmoothCD<float> mCameraNearFade;
    float mfVRCameraOffset;
    float mfNoBobVRCameraOffset;
    cTkSmoothCD<float> mfNoBobCameraBlend;
    /*cGcPlayerEffectsComponent*/ uintptr_t *mpPlayerEffectsComponent;
    /*cGcCombatEffectsComponent*/ uintptr_t *mpCombatEffectsComponent;
    TkHandle maControllerHandNodes[2];
};

SKYSCRAPER_END