/**
 * @file GcPlayerHUD.h
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
#include <graphics/hud/elements/GcHUDMarker.h>
#include <graphics/hud/elements/GcHUDTrackArrow.h>
#include <graphics/ngui/GcNGuiManager.h>
#include <graphics/ngui/GcNGuiTextSpecial.h>
#include <simulation/environment/scanning/GcBinoculars.h>
#include <simulation/player/GcPlayerImpact.h>
#include <toolkit/animation/TkHitCurve.h>

#include <simulation/player/gcplayerhazardtype.meta.h>
#include <toolkit/ngui/effects/tknguirectanglepulseeffect.meta.h>

SKYSCRAPER_BEGIN

class cGcPositionMarker
{
  public:
    enum eType
    {
        EPositionMarkerType_Creature,
        EPositionMarkerType_CreatureDiscovered,
        EPositionMarkerType_CreatureOutOfRange,
        EPositionMarkerType_NumTypes,
    };

    cGcPositionMarker::eType meType;
    float mfAlpha;
    cTkSmoothCD<float> mfDistanceAlpha;
    float mfDistance;
    bool mbAnimation;
    float mfAnimationValue;
    cTkVector2 mSize;
    cTkVector2 mScreenPos;
    cTkPhysRelVec3 mPosition;
    cTkSmartResHandle mIcon;
    cTkSmartResHandle mAnimation;
    cTkColour mColour;
    cTkClassPoolHandle mScreenHandle;
};

class cGcHUDPulseEffect
{
  public:
    cGcNGuiLayer *mpLayer;
    cTkNGuiRectanglePulseEffect *mpData;
    cTkColour mColour;
    float mfStartTime;
};

class cGcHUDPulseManager
{
    cTkClassPool<cGcHUDPulseEffect, 32> mArray;
};

class cGcPlayerHUD : public cGcHUD
{
  public:
    enum eCrosshair
    {
        ECrosshair_None,
        ECrosshair_Normal,
        ECrosshair_Target,
    };

    struct DisplayNumber
    {
        const char *mpacName;
        float mfNumber;
    };

    cGcNGui mHelmetGUI;
    cGcNGui mCrosshairGui;
    cGcNGui mHelmetLines;
    bool mabHelmetLinesVisible[5];
    cGcNGuiLayer mQuickMenu;
    cTk2dLayer mHUDEffectLayer;
    float mfWeaponActiveTime;
    cGcPlayerHUD::eCrosshair meCrosshair;
    bool mbShowReload;
    cGcHUDMarker maMarkers[128];
    cTk2dImageEx mLeadTargetInner;
    cTkHitCurve mLeadTargetHitCurve;
    float mfLeadTargetLastHit;
    cTk2dLayer mDroneNearLayer;
    cTk2dImageEx mDroneNearIndicator;
    cTk2dLayer mPainLayer;
    cTk2dImageEx mPainIndicator;
    float mfPainTime;
    cTkVector2 mShieldPanelBasePos;
    cTkVector2 mHazardPanelBasePos;
    cTkVector2 mWeaponPanelBasePos;
    cTkVector2 mIndicatorPanelBasePos;
    cTkVector2 mBuildInfoPanelBasePos;
    cTkVector2 mOSDMessagePanelBasePos;
    cTkVector2 mMissionMessagePanelBasePos;
    cTkVector2 mMissionDetailMessageBasePos;
    float mfLastEnergyDischargeTime;
    cTkVector2 mQuickMenuPos;
    cTkVector2 mTextChatLayerPos;
    cTkVector2 mPlayerListPos;
    cTkSmoothCD<cTkVector2> mShieldPanelPos;
    cTkSmoothCD<cTkVector2> mHazardPanelPos;
    cTkSmoothCD<cTkVector2> mWeaponPanelPos;
    cTkSmoothCD<cTkVector2> mIndicatorPanelPos;
    cTkSmoothCD<cTkVector2> mBuildInfoPanelPos;
    cTkSmoothCD<cTkVector2> mOSDMessagePanelPos;
    cTkSmoothCD<cTkVector2> mMissionMessagePanelPos;
    cTkSmoothCD<cTkVector2> mMissionDetailMessagePos;
    cTkSmoothCD<float> mZoomFadeFactor;
    cTkSmoothCD<cTkVector3> mAimTargetInterceptOffset;
    cTkVector2 mAimTargetInterceptPos;
    cTkSmoothCD<float> mfLeadTargetOverTargetFactor;
    float mfLeadTargetLockFactor;
    bool mbLeadTargetLocked;
    bool mbLeadTargetActive;
    bool mbLeadTargetIsThreat;
    float mfLeadTargetLockTime;
    float mfAimTargetAngle;
    cTkDynamicTexture *mpActiveUITexture;
    cTkDynamicTexture mUITexture;
    cTkDynamicTexture mUIMaskTexture;
    cTkSmartResHandle mWeaponScreenTextureRes;
    cTkSmartResHandle mUITextureRes;
    cTkSmartResHandle mUIMaskTextureRes;
    cTkSmartResHandle maHazardFullscreenTextures[6];
    cTkSmartResHandle maHazardFullscreenNormals[6];
    cTkSmartResHandle maHazardFullscreenRefractionTextures[6];
    cTkSmartResHandle mCamoFullscreenTexture;
    cTkSmartResHandle mCamoFullscreenNormalTexture;
    cTkFixedArray<cGcHUDTrackArrow, 8> maTrackArrows;
    cTkFixedArray<cGcPositionMarker, 500> maPositionMarkers;
    int miPositionMarkersNum;
    float mfHazardRestoreTime;
    int miHazardFullscreenSamplerIndex;
    int miHazardFullscreenNormalSamplerIndex;
    int miHazardFullscreenRefractionSamplerIndex;
    cTkSmartResHandle mHazardFullscreenActiveTexture;
    cTkSmartResHandle mHazardFullscreenActiveNormalTexture;
    cTkSmartResHandle mHazardFullscreenActiveRefractionTexture;
    cTkSmoothCD<float> mfHazardEffect;
    cTkSmoothCD<float> mfLowShieldFullscreenEffect;
    float mfShieldDownScanLine;
    cTkSmoothCD<cTkVector4> mFinalLowHealthVignetteUniform;
    cTkSmoothCD<cTkVector4> mFinalCriticalHitUniform;
    cTkSmoothCD<cTkVector3> mFinalGeneralVignetteUniform;
    cTkSmoothCD<float> mfFinalZoomVignetteUniform;
    float mfLastPlayerDamageTime;
    float mfLastFlashTime;
    float mfFlashDuration;
    float mfFlashDelay;
    float mfFlashIntensity;
    float mfExtraWarningTimer;
    cTkSmoothCD<float> mfShieldBar;
    float mfHeatBar;
    float mfCooldownBar;
    cTkSmoothCD<float> mfAimAmount;
    float mfLastShieldHitTime;
    int miLastWeaponModeIndex;
    int miLastWeaponAltModeIndex;
    int miLastTerrainEditMode;
    bool mbRechargeShield;
    float mfTimeSentinelsLastSearchedForPlayer;
    cGcHUDPulseManager mPulseEffects;
    float mfShowHUDTime;
    float mfHideHUDTime;
    float mfFreeLookAlpha;
    eHazard mePrimaryHazard;
    eHazard meSecondaryHazard;
    float mfPrimaryHazardTimer;
    float mfSecondaryHazardTimer;
    float mfPrimaryHazardStrength;
    float mfEnvironmentUpdateTimer;
    float mfAssertTimer;
    float mfOriginalMessageBoxOffset;
    float mfInitialMarkerWidth;
    float mfInitialMarkerHeight;
    cGcNGuiLayer *mpMarkerParent;
    cGcNGuiLayer *mapHelmetLinesLayer[5];
    cGcNGuiLayer *mpHelmetCompassLinesLayer;
    cGcNGuiLayer *mpReloadLayer;
    cGcNGuiLayer *mpReloadVRLayer;
    cGcNGuiLayer *mpReticleLayer;
    cGcNGuiLayer *mpShipCursorLayer;
    cGcNGuiTextSpecial *mpCrosshairControlsTextSpecial;
    cGcNGuiLayer *mpCrosshairNormalLayer;
    cGcNGuiLayer *mpCrosshairTargetLayer;
    cGcNGuiLayer *mpCrosshairDotLayer;
    cGcNGuiLayer *mpCrosshairAimLayer;
    cGcNGuiLayer *mpHitMarkerLayer;
    cGcNGuiLayer *mpNoShootLayer;
    cGcNGuiLayer *mpHUDShieldLayer;
    cGcNGuiLayer *mpShieldBarLayer;
    cGcNGuiLayer *mpShieldIconLayer;
    cGcNGuiLayer *mpShieldTechLayer;
    cGcNGuiLayer *mpHealthIconsLayer;
    cGcNGuiLayer *mpHUDWeaponLayer;
    cGcNGuiLayer *mpCombatMessageLayer;
    cGcNGuiTextSpecial *mpWeaponNameText;
    cGcNGuiTextSpecial *mpSwitchPrimaryTextSpecial;
    cGcNGuiTextSpecial *mpSwitchSecondaryTextSpecial;
    cGcNGuiTextSpecial *mpAltWeaponNameText;
    cGcNGuiGraphic *mpWeaponLabelBackgroundGraphic;
    cGcNGuiLayer *mpWeaponStatsLayer;
    cGcNGuiLayer *mpWeaponIconLayer;
    cGcNGuiLayer *mpWeaponTerrainLayer;
    cGcNGuiLayer *mpWeaponTerrainIconLayer;
    cGcNGuiTextSpecial *mpWeaponTerrainText;
    cGcNGuiLayer *mpWeaponGrenadeLayer;
    cGcNGuiLayer *mpGrenadeIconLayer;
    cGcNGuiLayer *mpWantedLayer;
    cGcNGuiLayer *mpHUDHazardLayer;
    cGcNGuiLayer *mpEnergyBarLayer;
    cGcNGuiLayer *mpHUDIndicatorsLayer;
    cGcNGuiLayer *mpStaminaLayer;
    cGcNGuiLayer *mpJetpackLayer;
    cGcNGuiLayer *mpStealthLayer;
    cGcNGuiLayer *mpScannerLayer;
    cGcNGuiLayer *mpSentinelLayer;
    cGcNGuiLayer *mpHUDInventoryLayer;
    cGcNGuiLayer *mpHUDOSDMessageLayer;
    cGcNGuiLayer *mpHUDBuildInfoLayer;
    cGcNGuiLayer *mpHUDBuildInfoLargeLayer;
    cGcNGuiTextSpecial *mpHUDBuildAvailableTextSpecial;
    cGcNGuiTextSpecial *mpHUDBuildPinTextSpecial;
    cGcNGuiTextSpecial *mpBaseOwnerTextSpecial;
    cGcNGuiLayer *mpBaseOwnerOfflineLayer;
    cGcNGuiLayer *mpBaseOwnerOnlineLayer;
    cGcNGuiLayer *mpHUDBasePowerLayer;
    cGcNGuiLayer *mpMissionMessageLayer;
    cGcNGuiLayer *mpMissionDetailMessageLayer;
    cGcNGuiLayer *mpTextChatLayer;
    cGcNGuiLayer *mpTextChatBackgroundLayer;
    cGcNGuiLayer *mpPlayerListLayer;
    cGcNGuiLayer *mpVoiceChatBackgroundLayer;
    TkID<128> mLastKnownCrosshairStyle;
    TkID<128> mNextCrosshairStyle;
    TkID<128> mRenderCrosshairStyle;
    float mfMouseLength;
    cTkVector2 mCrosshairScreen;
    cTkVector2 mCrosshairAimScreen;
    cTkVector2 mCrosshairMoveScreen;
    cTkVector2 mCrosshairLineStartScreen;
    float mfTaggedMarkerChangedTime;
    float mfTagButtonNotHeldTime;
    cGcBinoculars::eMode meBinocularsUIOverlay;
    bool mbBuildingMessageActive;
    const cGcBuilding *mpLastBuildingEntered;
    float mfLastBuildingExitTime;
    int miAbandonedFreighterRoomIndex;
    int16_t miAbandonedFreighterRoomsVisited;
    float mfPhonePulse;
    float mfSentinelPulse;
    cTkSmoothCD<float> mSentinelFade;
    bool mbShowDroneIcon;
    bool mbWantsTargetCrosshair;
    bool mbWasZoomingLastFrame;
    bool mbShowBaseDefence;
    float mfBaseDefenceActivation;
    float mfWeaponHeatWarningFactor;
    float mfWeaponHeatFactor;
    float mfWeaponAlertPoint;
    float mfWeaponCooldownFactor;
    int miCurrentMaxHealthPips;
    float mfJetpackAmount;
    float mfStealthAmount;
    float mfVehicleFuelRegen;
    cTkVector<cGcPlayerHUD::DisplayNumber> maNumbers;
    cTkVector<std::pair<int, cTkClassPoolHandle>> maDamageHandles;
    cTkVector<int> maiShootableImpactsIndices;
    cTkVector<cGcPlayerImpact> maProjectileImpacts;
};

SKYSCRAPER_END