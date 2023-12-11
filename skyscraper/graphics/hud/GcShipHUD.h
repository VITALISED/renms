/**
 * @file GcShipHUD.h
 * @author VITALISED & Contributors
 * @since 2023-12-10
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

#include <graphics/hud/GcHUD.h>
#include <graphics/hud/GcRenderableScreen.h>
#include <graphics/hud/elements/GcHUDTrackArrow.h>
#include <graphics/ngui/GcNGuiManager.h>
#include <simulation/particles/GcEffectList.h>
#include <simulation/spaceship/GcSpaceShipWarp.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/graphics/2d/texture/TkDynamicTexture.h>
#include <toolkit/graphics/2d/ui/layers/Tk3dLayer.h>

SKYSCRAPER_BEGIN

enum ePlanetLabelState
{
    EPlanetLabelState_None,
    EPlanetLabelState_Planet,
    EPlanetLabelState_PlanetTimingOut,
};

class cGcShipHUD : public cGcHUD
{
  public:
    class cGcVehicleScreen
    {
      public:
        cTkDynamicTexture mScreenTexture;
        cGcNGui mScreenGUI;
        bool mbValid;
    };
    cTk2dLayer mHUDLayer;
    cTk2dImageEx mCrosshairOuterCircleLarge;
    cTk3dLayer mCrosshairOuterCircleLargeLayer;
    cTk2dImageEx mCrosshairOuterCircleSmall;
    cTk3dLayer mCrosshairOuterCircleSmallLayer;
    cTk2dLayer mMouseArrowLayer;
    cTk2dImageEx mMouseArrowIcon;
    cTkVector3 mShipForwardScreenPos;
    float mfShipAngle;
    float mfShipPitch;
    EffectInstance mLandingEffect;
    cTkFixedArray<cGcHUDTrackArrow, 8> maTrackArrows;
    cTkVector<cTkAttachmentPtr> maShootList;
    int miSelectedPlanet;
    ePlanetLabelState meSelectedPlanetLabelState;
    float mfSelectedPlanetPanelTime;
    float mfSelectedPlanetPanelFadeTime;
    bool mbSelectedPlanetPanelVisible;
    bool mbSelectedPlanetIsTargeted;
    float mfLastKnownScanTime;
    float mfScanRevealTimer;
    ePulseDriveState meMiniJumpState;
    bool mbHasPulseEncounterOnHUD;
    cGcRenderableScreen *mapScreens[2];
    int miCurrentScreen;
    cTkDynamicTexture maSideScreenTextures[4];
    cGcNGui maSideScreenGUI[4];
    cTkVector2 maSideScreenCursor[4];
    bool mbSideScreenActive;
    TkHandle maSideScreenMeshes[4];
    TkHandle mCurrentCockpit;
    cGcShipHUD::cGcVehicleScreen maVehicleScreens[7];
    TkHandle mSpeedoReverseMesh;
    TkHandle mSpeedoPulseMesh;
    TkHandle maSpeedoBarsMeshes[5];
    int miCurrentSpeedoBar;
    int miFinalSpeedReadout;
    cTkDynamicTexture mMainScreenTexture;
    cGcNGui mMainScreenGUI;
    cTkFixedString<127, char> mTargetProcName;
    cTkVector3 maPlanetWorldPositions[6];
    cTkVector3 maPlanetScreenPositions[6];
    cGcNGui mHeadsUpGUI;
    cTkClassPoolHandle mHeadsUpScreenHandle;
    cTkSmartResHandle mEnemyTargetSceneRes;
    float mfBoostMultiplier;
};

SKYSCRAPER_END