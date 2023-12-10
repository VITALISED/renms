/**
 * @file GcTerrainEditorBeam.h
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

#include <simulation/particles/GcEffectList.h>
#include <simulation/projectiles/GcLaserBeam.h>
#include <toolkit/core/types/TkHandle.h>
#include <toolkit/maths/geometry/TkPlane.h>
#include <toolkit/resources/TkResource.h>

#include <simulation/player/gcscaneffectdata.meta.h>

SKYSCRAPER_BEGIN

class cGcWeapon;

enum eEditPlaneState
{
    EEditPlaneState_Disabled,
    EEditPlaneState_LockedOnPlane,
    EEditPlaneState_LockedInFrontOfPlane,
};

enum eTerrainEditShape
{
    ETerrainEditShape_Sphere,
    ETerrainEditShape_Cube,
    ETerrainEditShape_Num,
};

class cGcTerrainEditorBeam
{
  public:
    enum eEditMode
    {
        EEditMode_SubtractiveMode,
        EEditMode_AdditiveMode,
        EEditMode_FlatteningMode,
        EEditMode_UndoMode,
        EEditMode_NumTypes,
    };

    cGcWeapon *mpOwnerWeapon;
    cTkSmartResHandle mHologramResources[3];
    TkHandle mHologramNodes[3];
    /*cGcScanEffectComponent*/ uintptr_t *mpHologramEffects[3];
    cTkSmartResHandle mPlaneHologramResource;
    TkHandle mPlaneHologramNode;
    int miCurrentHologramIndex;
    TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mPlaneMaterial;
    cTkSmartResHandle mMuzzleEffectResources[4];
    float mfHologramLastInactiveTime;
    float mfHologramLastActiveTime;
    cGcScanEffectData mEditScanData;
    cGcBeamEffect mBeam;
    cGcBeamEffect mBeamCore;
    EffectInstance mTerrainEditorEffectHandle;
    EffectInstance mImpactEffectHandle;
    TkHandle mMuzzleEffects[4];
    cTkVector3 mLastEditAddLocation;
    bool mbLastEditWasAdd;
    bool mbActive;
    bool mbPrepared;
    TkAudioObject mAudioObject;
    float mfFiringTime;
    float mfLastFireTime;
    float mfLastEditTime;
    cTkPlane mEditPlane;
    eEditPlaneState meEditPlaneState;
    int miCurrentSizeIndex;
    eTerrainEditShape meCurrentShape;
    cTkVector3 mCurrentEditPosition;
    cTkVector3 mLastEditPosition;
    cTkVector3 mLastApplyPosition;
    bool mbRaycastHit;
    bool mbRaycastHitTerrain;
    bool mbPositionOverlapsObject;
    float mfPositionRaycastOffset;
    float mfCurrentEditPositionDistance;
    cGcTerrainEditorBeam::eEditMode meEditMode;
    float mfModeSwitchTime;
    bool mbInterpolationTrailLost;
    bool mbDisableLastEditHologram;
    bool mbShowNotificationMessage;
    float mfLastSizeChangeTime;
    TkHandle mLight;
};

SKYSCRAPER_END