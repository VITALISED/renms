#pragma once

#include <skyscraper.h>
#include <toolkit/maths/geometry/TkPhysRelVec3.h>
#include <toolkit/utilities/TkString.h>
#include <toolkit/utilities/TkStrongType.h>
#include <toolkit/attachments/TkHandle.h>

SKYSCRAPER_BEGIN

class cGcMarkerPoint
{
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
	cGcBuilding* mpBuilding;
	cGcLootComponent* mpLootComponent;
	cGcScannableComponent* mpScannableComponent;
	cGcMarkerComponent* mpMarkerComponent;
	cTkUserIdBase<cTkFixedString<64, char> > mNetworkPlayerId;
	int miPlayerIndex;
	eScannableType meScannableType;
	cTkPhysRelVec3 mInteractPosition;
	cTkAttachmentPtr mpInteractPhysics;
	TkHandle mInteractLocator;
	cTkUserIdBase<cTkFixedString<64, char> > mRemotePlayerID;
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
	cGcMarkerPoint::eDisplay meDisplay;
	bool mbLockedOn;
	float mfScreenOffsetY;
	eOverrideInteriorExteriorMarker meInsideOrOutsideOverride;
	bool mbUseInteractPosition;
};

SKYSCRAPER_END