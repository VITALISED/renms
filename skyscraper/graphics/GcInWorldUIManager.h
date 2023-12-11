/**
 * @file GcInWorldUIManager.h
 * @author VITALISED & Contributors
 * @since 2023-12-08
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

#include <graphics/inworldui/GcInWorldScreen.h>
#include <simulation/player/GcQuickMenuTypes.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/simulation/components/TkAnimationComponent.h>
#include <toolkit/utilities/containers/TkBitArray.h>
#include <toolkit/utilities/containers/TkClassPool.h>

SKYSCRAPER_BEGIN

enum eInWorldScreens
{
    EInWorldScreen_Frontend,
    EInWorldScreen_HUD,
    EInWorldScreen_QuickMenu,
    EInWorldScreen_Compass,
    EInWorldScreen_Crosshair,
    EInWorldScreen_WeaponMenu,
    EInWorldScreen_QuickMenuLauncher,
    EInWorldScreen_HoldInteract,
    EInWorldScreen_ShootInteract,
    EInWorldScreen_GameModeSelect,
    EInWorldScreen_FaceLockedVR,
    EInWorldScreen_NumTypes,
};

enum eMenuPositioning
{
    EMenuPositioning_None,
    EMenuPositioning_Inventory,
    EMenuPositioning_QuickMenu,
    EMenuPositioning_QuickMenuLauncher,
    EMenuPositioning_WeaponMenu,
    EMenuPositioning_Frontend,
};

enum eInteractionOrigin
{
    EInteractionOrigin_Player,
    EInteractionOrigin_Camera,
};

class cGcInWorldUIManager
{
  public:
    struct LabelLine
    {
        cTkPhysRelVec3 mFrom;
        cTkPhysRelVec3 mTo;
        cTkColour mColour;
    };

    class cGcScreenProjector
    {
      public:
        enum RepositioningState
        {
            Idle,
            Hovered,
            Repositioning,
            Repositioned,
            Resetting,
        };

        TkHandle mNode;
        TkHandle mBorder;
        TkHandle mDebugNode;
        TkAudioObject mContinuousAudioObject;
        TkAudioObject mAudioObject;
        cTkPhysRelMat34 mMatrix;
        cTkMatrix34 mRepositionMatrix;
        cTkSmoothCD<float> mfActiveFactor;
        cTkSmoothCD<float> mfStartupFactor;
        cTkSmoothCD<float> mfFader;
        cTkAnimationComponent *mpAnim;
        cTkAnimInstanceHandle mStartupAnimHandle;
        cTkAnimInstanceHandle mActivateAnimHandle;
        cGcInWorldUIManager::cGcScreenProjector::RepositioningState meRepositioning;
        float mfRepositionResetTime;
        float mfAudioStrength;
    };

    cGcInWorldScreen maMainsScreens[11];
    eInWorldScreens meActiveRenderScreen;
    cTkClassPoolHandle mActiveScreenHandle;
    cGcInWorldScreen mDummyOnTopScreen;
    cTkVector<cGcInWorldUIManager::LabelLine> maLabelLines;
    cTkClassPool<cGcInWorldScreen, 256> maScreenPool;
    eInWorldScreens meActiveCursorScreen;
    eHand meActiveCursorHand;
    TkHandle mInWorldUIGroupNodeSimulation;
    TkHandle mInWorldUIGroupNodeOtherState;
    TkHandle mHeadCoherentUIGroupNode;
    TkHandle mInWorldUIQuickMenuNode;
    TkHandle mInWorldUIGameModeSelect;
    TkHandle mInWorldUIPoolNode;
    TkHandle mCrosshairParentNode;
    cTkNGuiInput mDummyInput;
    cTkSmartResHandle mProjectorRes;
    cGcInWorldUIManager::cGcScreenProjector mQuickLauncherProjector;
    cGcInWorldUIManager::cGcScreenProjector mWeaponProjector;
    cTkVector3 mRoboHandBaseDir;
    TkID<128> mLastOffsetState;
    eMenuPositioning meCurrentMenuPositioning;
    bool mbResetHeadCoherentUI;
    eInteractionOrigin meCurrentInteractionOrigin;
    bool mbActiveScreenHasGameGui;
    cTkPhysRelVec3 mLastCursorWorldPos;
    cTkBitArray<unsigned int, 1, 32> mxCursorEnabledScreens;
    float mfClearAlpha;
    cTkPhysRelVec3 mDrawPointerStart;
    cTkPhysRelVec3 mDrawPointerEnd;
    bool mbDrawPointer;
    float mfDrawPointerStrength;
    cTkSmartResHandle mPointerLineRes;
    TkHandle mPointerNode;
    bool mbRunning;
    bool mbConstructed;
    bool mbPrepared;
    bool mbInteractiveScreen;
    TkID<128> mSavedActionSet;
    bool mbBuildMenuAvailable;
    uint8_t meMenuAction[4];
    uint8_t meHoveredMenuAction[4];
    TkHandle maQuickMenuSlots[16];
    eQuickMenuSlot meSelectedQuickMenuSlot;
};

SKYSCRAPER_END