/**
 * @file GcSpaceShipWarp.h
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

#include <simulation/environment/scanning/GcMarkerPoint.h>
#include <simulation/galaxy/GcGalaxyTypes.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>

#include <gamestate/gcteleportendpoint.meta.h>
#include <simulation/solarsystem/gcsolarsystemdata.meta.h>

SKYSCRAPER_BEGIN

enum ePulseDriveState
{
    EPulseDriveState_None,
    EPulseDriveState_Charge,
    EPulseDriveState_Jumping,
    EPulseDriveState_CrashStop,
    EPulseDriveState_Cooldown,
};

class cGcWarpJumpTarget
{
    cGcGalacticSolarSystemAddress mTargetSystem;
    cTkVector3 mTargetDirInMap;
    float mfDistanceToTarget;
    int miPortalPlanetIndex;
    bool mbWarpedFromAtlas;
};

class cGcSpaceshipWarp
{
  public:
    enum eWarpState
    {
        EWarpState_None,
        EWarpState_Charge,
        EWarpState_EnterTunnel,
        EWarpState_WarpTunnel,
        EWarpState_WaitForGeneration,
        EWarpState_RespawnPlayer,
        EWarpState_ExitTunnel,
        EWarpState_WarpSlowdown,
        EWarpState_RenderDebug,
        EWarpState_NumStates,
    };

    enum BoostDoubleTap
    {
        Idle,
        BoostOn,
        BoostOff,
        BoostPulse,
    };

    enum eWarpEffectType
    {
        EWT_Normal,
        EWT_Teleport,
        EWT_ToNextGalaxy,
        EWT_BlackHole,
        EWT_GalaxyMap,
        EWT_Portal,
        EWT_PortalStorySpace,
        EWT_PortalStoryPlanet,
        EWT_PortalCommunity,
        EWT_Freighter,
        EWT_NexusExit,
        EWT_FreighterMegaWarp,
        EWT_FakePortalTeleport,
        EWT_Num,
    };

    struct NexusWarpData
    {
        bool mbValid;
        cGcUniverseAddressData mAddress;
    };

    uint8_t meWarpMode[4];
    cGcWarpJumpTarget mJumpTarget;
    cGcSolarSystemLocator mLocatorTarget;
    TkAudioObject mAudioObject;
    cGcSpaceshipWarp::eWarpState meWarpState;
    float mfWarpStageTimer;
    float mfWarpTimeTotal;
    ePulseDriveState mePulseDriveState;
    float mfPulseDriveSpeed;
    float mfPulseDriveSpeedAccel;
    float mfPulseDriveTimer;
    float mfPulseDriveFuelTimer;
    float mfPulseDriveDistance;
    float mfPulseDriveDistanceSqToTarget;
    bool mbPulseDriveWanted;
    float mfSpaceFogFadeFactor;
    cGcSpaceshipWarp::BoostDoubleTap mePulseDriveBoostTapState;
    float mfPulseDriveBoostLastTime;
    int miPulseDriveCountdown;
    bool mbHasPulseDriveTrackPos;
    cGcMarkerPoint mPulseDriveTrackMarker;
    float mfLastPulseDriveFailTime;
    float mfLastThrottleValue;
    cTkMatrix34 mShipTransformAtStart;
    cTkMatrix34 mWarpInDestinationTM;
    cTkMatrix34 mPlayerRelativeToFreighter;
    float mfTunnelAlpha;
    float mfSlowdownTimer;
    cTkSmartResHandle maWarpTunnelRes[13];
    cTkSmartResHandle mPipelineRes;
    int miParticlePipelineStage;
    TkHandle mWarpTunnelNode;
    TkHandle mWarpTunnelLight;
    cTkVector<cTkSmartResHandle> maWarpTunnelMaterials;
    cTkSmartResHandle mWarpExitMaterial;
    float mfWarpShake;
    float mfWarpFov;
    float mfWarpEffectTimeMultiplier;
    float mfDebugRenderOffset;
    float mfDebugRenderAlpha;
    bool mbWarpTunnelHidden;
    bool mbWarpSoundFXActive;
    bool mbPrepared;
    cGcSpaceshipWarp::eWarpEffectType meCurrentWarpEffect;
    cGcTeleportEndpoint mTargetTeleportEndpoint;
    bool mbHasTargetTeleportEndpoint;
    bool mbWarpingWithinSystem;
    bool mbUsedPortal;
    bool mbRequestExitPulse;
    TkHandle mFreighterNode;
    cGcSpaceshipWarp::NexusWarpData mNexusWarpData;
};

SKYSCRAPER_END