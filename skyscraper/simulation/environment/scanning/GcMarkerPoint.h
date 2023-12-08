/**
 * @file GcMarkerPoint.h
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

#include <networking/GcNetworkConstants.h>
#include <simulation/solarsystem/buildings/GcBuilding.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/core/types/TkHandle.h>
#include <toolkit/core/types/TkID.h>
#include <toolkit/maths/geometry/TkPhysRelVec3.h>
#include <toolkit/networking/TkUserIdBase.h>

#include <simulation/components/gameplay/gcinteractioncomponentdata.meta.h>
#include <simulation/components/scanning/gcscannablecomponentdata.meta.h>
#include <simulation/environment/gcbuildingclassification.meta.h>

SKYSCRAPER_BEGIN

class cGcMarkerPoint
{
  public:
    enum eType
    {
        EMarkerType_Default,
        EMarkerType_PlanetPoleNorth,
        EMarkerType_PlanetPoleSouth,
        EMarkerType_BaseBuildingMarkerBeacon,
        EMarkerType_TerrainResource,
        EMarkerType_Object,
        EMarkerType_Tagged,
        EMarkerType_Unknown,
        EMarkerType_Ship,
        EMarkerType_Freighter,
        EMarkerType_NetworkPlayerFireTeamFreighter,
        EMarkerType_FreighterBase,
        EMarkerType_PlayerFreighter,
        EMarkerType_PlayerSettlement,
        EMarkerType_DamagedFrigate,
        EMarkerType_Bounty,
        EMarkerType_PlanetRaid,
        EMarkerType_Battle,
        EMarkerType_SpaceSignal,
        EMarkerType_BlackHole,
        EMarkerType_SpaceAnomalySignal,
        EMarkerType_SpaceAtlasSignal,
        EMarkerType_GenericIcon,
        EMarkerType_NetworkPlayerFireTeam,
        EMarkerType_NetworkPlayerFireTeamShip,
        EMarkerType_NetworkPlayer,
        EMarkerType_NetworkPlayerShip,
        EMarkerType_NetworkPlayerVehicle,
        EMarkerType_Monument,
        EMarkerType_PlayerBase,
        EMarkerType_EditingBase,
        EMarkerType_MessageBeacon,
        EMarkerType_ExternalBase,
        EMarkerType_PlanetBaseTerminal,
        EMarkerType_Vehicle,
        EMarkerType_VehicleCheckpoint,
        EMarkerType_VehicleGarage,
        EMarkerType_Pet,
        EMarkerType_DeathPoint,
        EMarkerType_Signal,
        EMarkerType_Portal,
        EMarkerType_PurchasableFrigate,
        EMarkerType_Expedition,
        EMarkerType_Building,
        EMarkerType_ActiveNetworkMarker,
        EMarkerType_CustomMarker,
        EMarkerType_PlacedMarker,
        EMarkerType_Nexus,
        EMarkerType_PowerHotspot,
        EMarkerType_MineralHotspot,
        EMarkerType_GasHotspot,
        EMarkerType_NPC,
        EMarkerType_SettlementNPC,
        EMarkerType_CreatureCurious,
        EMarkerType_CreatureAction,
        EMarkerType_CreatureTame,
        EMarkerType_CreatureDanger,
        EMarkerType_CreatureFiend,
        EMarkerType_CreatureMilk,
        EMarkerType_FuelAsteroid,
        EMarkerType_PulseEncounter,
        EMarkerType_FrigateFlyby,
        EMarkerType_ShipExperienceSpawn,
        EMarkerType_FriendlyDrone,
        EMarkerType_NumTypes,
    };

    cTkPhysRelVec3 mPosition;
    cTkVector3 mCenterOffset;
    float mfTopOffset;
    cGcMarkerPoint::eType meType;
    float mfBoundingRadius;
    cTkFixedString<64, char> mCustomName;
    cTkFixedString<128, char> mCustomSubtitle;
    TkStrongType<int, TkStrongTypeIDs::TkResHandleID> maCustomIcons[3];
    TkHandle mNode;
    TkHandle mModelNode;
    TkHandle mEntranceNode;
    eBuildingClass meBuildingClass;
    cGcBuilding *mpBuilding;
    /*cGcLootComponent*/ uintptr_t *mpLootComponent;
    /*cGcScannableComponent*/ uintptr_t *mpScannableComponent;
    /*cGcMarkerComponent*/ uintptr_t *mpMarkerComponent;
    cTkUserIdBase<cTkFixedString<64, char>> mNetworkPlayerId;
    int miPlayerIndex;
    eScannableType meScannableType;
    cTkPhysRelVec3 mInteractPosition;
    cTkAttachmentPtr mpInteractPhysics;
    TkHandle mInteractLocator;
    cTkUserIdBase<cTkFixedString<64, char>> mRemotePlayerID;
    cGcMarkerPoint::eType meRemoteType;
    float mfRemoteStartTime;
    cGcNetworkConstants::OnlinePlatformType mePlatform;
    float mfStartTime;
    float mfActiveTime;
    bool mbPerpetual;
    bool mbFollowNode;
    bool mbAlwaysAdd;
    bool mbMarkedPrimary;
    bool mbPulseDriveTarget;
    bool mbNeedsToBeSurveyed;
    bool mbWaitingForNode;
    cTkColour mOverwriteColour;
    bool mbTimedEvent;
    bool mbActive;
    bool mbCanDisplay;
    std::pair<TkID<128>, cTkSeed> mMission;
    TkID<256> mSequence;
    uint8_t meDisplay[4];
    bool mbLockedOn;
    float mfScreenOffsetY;
    eOverrideInteriorExteriorMarker meInsideOrOutsideOverride;
    bool mbUseInteractPosition;
};

class cGcMarkerList
{
  public:
    cTkVector<cGcMarkerPoint> maMarkerObjects;
};

SKYSCRAPER_END