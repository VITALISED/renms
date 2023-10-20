#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/gcuniverseaddressdata.meta.h>
#include <metadata/user/gcdifficultystatedata.meta.h>
#include <metadata/gamestate/gcinventorycontainer.meta.h>
#include <metadata/gamestate/gcmultitooldata.meta.h>
#include <metadata/audio/gcbytebeatlibrarydata.meta.h>
#include <metadata/gamestate/gcpetdata.meta.h>
#include <metadata/gamestate/gcpetcustomisationdata.meta.h>
#include <metadata/gamestate/gcinventorylayout.meta.h>
#include <metadata/utilities/data/gcresourceelement.meta.h>
#include <metadata/resource/gcexactresource.meta.h>
#include <metadata/gamestate/gcwordknowledge.meta.h>
#include <metadata/gamestate/gcwordgroupknowledge.meta.h>
#include <metadata/gamestate/gcplayermissionprogress.meta.h>
#include <metadata/simulation/missions/scheduling/gcmissionidepochpair.meta.h>
#include <metadata/gamestate/interactions/gcinteractiondata.meta.h>
#include <metadata/simulation/gcscaneventsave.meta.h>
#include <metadata/gamestate/stats/gcplayerstatsgroup.meta.h>
#include <metadata/gamestate/telemetry/gctelemetrystat.meta.h>
#include <metadata/gamestate/interactions/gcinteractionbuffer.meta.h>
#include <metadata/gamestate/gcmaintenancecontainer.meta.h>
#include <metadata/gamestate/interactions/gcsavedinteractionracedata.meta.h>
#include <metadata/gamestate/interactions/gcsavedinteractiondialogdata.meta.h>
#include <metadata/gamestate/gcsavedentitlement.meta.h>
#include <metadata/gamestate/gcsquadronpilotdata.meta.h>
#include <metadata/gamestate/basebuilding/gcpersistentbbobjectdata.meta.h>
#include <metadata/gamestate/interactions/gcterraineditsbuffer.meta.h>
#include <metadata/gamestate/basebuilding/gcnpcworkerdata.meta.h>
#include <metadata/gamestate/basebuilding/gcpersistentbase.meta.h>
#include <metadata/gamestate/gcteleportendpoint.meta.h>
#include <metadata/gamestate/gcplayerownershipdata.meta.h>
#include <metadata/gamestate/gctradingsupplydata.meta.h>
#include <metadata/gamestate/gcportalsavedata.meta.h>
#include <metadata/simulation/weapons/gcplayerweapons.meta.h>
#include <metadata/gamestate/customisation/gccharactercustomisationsavedata.meta.h>
#include <metadata/gamestate/customisation/gccharactercustomisationdata.meta.h>
#include <metadata/gamestate/gcfleetfrigatesavedata.meta.h>
#include <metadata/gamestate/gcfleetexpeditionsavedata.meta.h>
#include <metadata/gamestate/gcplayerspawnstatedata.meta.h>
#include <metadata/gamestate/gcrepairtechdata.meta.h>
#include <metadata/ui/hud/quickmenu/gchotactionssavedata.meta.h>
#include <metadata/user/gcphotomodesettings.meta.h>
#include <metadata/gamestate/gcseasonalgamemodedata.meta.h>
#include <metadata/gamestate/gcseasonstatedata.meta.h>
#include <metadata/gamestate/gcsettlementstate.meta.h>
#include <metadata/wiki/gcstorypageseendataarray.meta.h>
#include <metadata/wiki/gcwonderrecord.meta.h>
#include <metadata/wiki/gcwonderrecordcustomdata.meta.h>
#include <metadata/gamestate/gcsyncbuffersavedataarray.meta.h>
#include <metadata/gamestate/gcmaintenancesavekey.meta.h>

class cGcPlayerStateData
{
    static unsigned long long muNameHash = 0x6C4510BB243EFA64;
    static unsigned long long muTemplateHash = 0x8FEEE8175F5670DD;

    cGcUniverseAddressData UniverseAddress;
    cGcUniverseAddressData PreviousUniverseAddress;
    int miHomeRealityIteration;
    cTkFixedString<128,char> macSaveName;
    cTkFixedString<128,char> macSaveSummary;
    cGcDifficultyStateData DifficultyState;
    cGcInventoryContainer Inventory;
    cGcInventoryContainer Inventory_TechOnly;
    cGcInventoryContainer Inventory_Cargo;
    cGcInventoryContainer ShipInventory;
    cGcInventoryContainer WeaponInventory;
    cTkFixedArray<cGcMultitoolData> maMultitools;
    int miActiveMultioolIndex;
    cGcByteBeatLibraryData ByteBeatLibrary;
    cTkFixedArray<cGcPetData> maPets;
    cTkFixedArray<cGcPetData> maEggs;
    cTkFixedArray<cGcPetCustomisationData> maPetAccessoryCustomisation;
    cTkFixedArray<bool> maUnlockedPetSlots;
    cGcInventoryContainer GraveInventory;
    bool mbSpawnGrave;
    bool mbSpaceGrave;
    cGcUniverseAddressData GraveUniverseAddress;
    cTkVector4 mGravePosition;
    cTkVector4 mGraveMatrixLookAt;
    cTkVector4 mGraveMatrixUp;
    cGcInventoryLayout ShipLayout;
    cGcInventoryLayout WeaponLayout;
    cGcResourceElement CurrentShip;
    cGcExactResource CurrentWeapon;
    cTkDynamicArray<TkID<128>> maKnownTech;
    cTkDynamicArray<TkID<128>> maKnownProducts;
    cTkDynamicArray<TkID<128>> maKnownSpecials;
    cTkDynamicArray<TkID<256>> maKnownRefinerRecipes;
    cTkDynamicArray<cGcWordKnowledge> maKnownWords;
    cTkDynamicArray<cGcWordGroupKnowledge> maKnownWordGroups;
    cTkDynamicArray<cGcPlayerMissionProgress> maMissionProgress;
    int miPostMissionIndex;
    TkID<128> mCurrentMissionID;
    unsigned long long mui64CurrentMissionSeed;
    TkID<128> mPreviousMissionID;
    unsigned long long mui64PreviousMissionSeed;
    int miMissionVersion;
    cTkDynamicArray<cGcMissionIDEpochPair> maMissionRecurrences;
    cGcInteractionData HoloExplorerInteraction;
    cGcInteractionData HoloScepticInteraction;
    cGcInteractionData HoloNooneInteraction;
    int miHealth;
    int miShipHealth;
    int miShield;
    int miShipShield;
    int miEnergy;
    int miUnits;
    int miNanites;
    int miSpecials;
    bool mbThirdPersonShip;
    unsigned long long mui64TimeAlive;
    unsigned long long mui64TotalPlayTime;
    cTkDynamicArray<cGcScanEventSave> maMarkerStack;
    cTkDynamicArray<cGcScanEventSave> maNewMPMarkerStack;
    cTkDynamicArray<cTkVector3> maSurveyedEventPositions;
    int miNextSurveyedEventPositionIndex;
    cTkDynamicArray<cGcPlayerStatsGroup> maStats;
    cTkDynamicArray<cGcTelemetryStat> maTelemetryStats;
    cTkFixedArray<cGcInteractionBuffer> maStoredInteractions;
    cTkDynamicArray<cGcMaintenanceContainer> maMaintenanceInteractions;
    cTkDynamicArray<cGcMaintenanceContainer> maPersonalMaintenanceInteractions;
    cTkDynamicArray<unsigned long long> maVisitedSystems;
    cTkFixedArray<float> maHazard;
    int miBoltAmmo;
    int miScatterAmmo;
    int miPulseAmmo;
    int miLaserAmmo;
    cTkVector4 mFirstSpawnPosition;
    cTkFixedArray<cGcSavedInteractionRaceData> maSavedInteractionIndicies;
    cTkDynamicArray<cGcSavedInteractionDialogData> maSavedInteractionDialogTable;
    cTkDynamicArray<TkID<256>> maInteractionProgressTable;
    cTkFixedArray<cGcUniverseAddressData> maAtlasStationAdressData;
    cTkFixedArray<cGcUniverseAddressData> maNewAtlasStationAdressData;
    cTkDynamicArray<cGcUniverseAddressData> maVisitedAtlasStationsData;
    bool mbFirstAtlasStationDiscovered;
    bool mbUsesThirdPersonCharacterCam;
    int miProgressionLevel;
    int miProcTechIndex;
    bool mbIsNew;
    bool mbUseSmallerBlackholeJumps;
    cTkDynamicArray<cGcSavedEntitlement> maUsedEntitlements;
    cTkFixedArray<cTkVector3> maPlanetPositions;
    cTkFixedArray<cTkSeed> maPlanetSeeds;
    int miPrimaryPlanet;
    unsigned long long mui64TimeLastSpaceBattle;
    int miWarpsLastSpaceBattle;
    unsigned long long mui64ActiveSpaceBattleUA;
    unsigned long long mui64TimeLastMiniStation;
    int miWarpsLastMiniStation;
    unsigned long long mui64MiniStationUA;
    cTkVector4 mAnomalyPositionOverride;
    cGcUniverseAddressData GameStartAddress1;
    cGcUniverseAddressData GameStartAddress2;
    cTkFixedArray<bool> maGalacticMapRequests;
    cTkVector4 mFirstShipPosition;
    unsigned long long mui64HazardTimeAlive;
    bool mbRevealBlackHoles;
    cTkSeed mCurrentFreighterHomeSystemSeed;
    cGcResourceElement CurrentFreighter;
    cGcInventoryLayout FreighterLayout;
    cGcInventoryLayout FreighterCargoLayout;
    cGcInventoryContainer FreighterInventory;
    cGcInventoryContainer FreighterInventory_TechOnly;
    cGcInventoryContainer FreighterInventory_Cargo;
    unsigned long long mui64FreighterLastSpawnTime;
    cGcUniverseAddressData FreighterUniverseAddress;
    bool mbFreighterDismissed;
    cTkVector3 mFreighterMatrixAt;
    cTkVector3 mFreighterMatrixUp;
    cTkVector3 mFreighterMatrixPos;
    cTkFixedArray<bool> maSquadronUnlockedPilotSlots;
    cTkFixedArray<cGcSquadronPilotData> maSquadronPilots;
    cTkDynamicArray<TkID<128>> maSeenBaseBuildingObjects;
    cTkDynamicArray<cGcPersistentBBObjectData> maBaseBuildingObjects;
    cGcTerrainEditsBuffer TerrainEditData;
    cTkFixedArray<cGcNPCWorkerData> maNPCWorkers;
    cTkDynamicArray<cGcPersistentBase> maPersistentPlayerBases;
    cTkDynamicArray<cGcTeleportEndpoint> maTeleportEndpoints;
    cGcInventoryLayout Chest1Layout;
    cGcInventoryContainer Chest1Inventory;
    cGcInventoryLayout Chest2Layout;
    cGcInventoryContainer Chest2Inventory;
    cGcInventoryLayout Chest3Layout;
    cGcInventoryContainer Chest3Inventory;
    cGcInventoryLayout Chest4Layout;
    cGcInventoryContainer Chest4Inventory;
    cGcInventoryLayout Chest5Layout;
    cGcInventoryContainer Chest5Inventory;
    cGcInventoryLayout Chest6Layout;
    cGcInventoryContainer Chest6Inventory;
    cGcInventoryLayout Chest7Layout;
    cGcInventoryContainer Chest7Inventory;
    cGcInventoryLayout Chest8Layout;
    cGcInventoryContainer Chest8Inventory;
    cGcInventoryLayout Chest9Layout;
    cGcInventoryContainer Chest9Inventory;
    cGcInventoryLayout Chest10Layout;
    cGcInventoryContainer Chest10Inventory;
    cGcInventoryLayout ChestMagicLayout;
    cGcInventoryContainer ChestMagicInventory;
    cGcInventoryLayout ChestMagic2Layout;
    cGcInventoryContainer ChestMagic2Inventory;
    cGcInventoryLayout CookingIngredientsLayout;
    cGcInventoryContainer CookingIngredientsInventory;
    cGcInventoryLayout RocketLockerLayout;
    cGcInventoryContainer RocketLockerInventory;
    cGcResourceElement CurrentFreighterNPC;
    cTkFixedArray<cGcPlayerOwnershipData> maVehicleOwnership;
    int miPrimaryVehicle;
    cTkFixedArray<cGcPlayerOwnershipData> maShipOwnership;
    int miPrimaryShip;
    bool mbMultiShipEnabled;
    bool mbVehicleAIControlEnabled;
    cTkFixedString<32,char> macPlayerFreighterName;
    cTkVector4 mStartGameShipPosition;
    bool mbShipNeedsTerrainPositioning;
    int miTradingSupplyDataIndex;
    cTkDynamicArray<cGcTradingSupplyData> maTradingSupplyData;
    cTkDynamicArray<cGcPortalSaveData> maLastPortal;
    cGcPortalSaveData VisitedPortal;
    int miKnownPortalRunes;
    bool mbOnOtherSideOfPortal;
    cGcTeleportEndpoint OtherSideOfPortalReturnBase;
    cTkVector4 mPortalMarkerPosition_Local;
    cTkVector4 mPortalMarkerPosition_Offset;
    cGcPlayerWeapons StartingPrimaryWeapon;
    cGcPlayerWeapons StartingSecondaryWeapon;
    cTkFixedArray<cGcCharacterCustomisationSaveData> maCharacterCustomisationData;
    cTkFixedArray<bool> maShipUsesLegacyColours;
    cTkFixedArray<cGcCharacterCustomisationData> maOutfits;
    TkID<128> mJetpackEffect;
    TkID<128> mFreighterEngineEffect;
    cTkSeed mFleetSeed;
    cTkDynamicArray<cGcFleetFrigateSaveData> maFleetFrigates;
    cTkDynamicArray<cGcFleetExpeditionSaveData> maFleetExpeditions;
    cTkDynamicArray<unsigned long long> maExpeditionSeedsSelectedToday;
    unsigned long long mui64LastKnownDay;
    unsigned long long mui64SunTimer;
    unsigned long long mui64MultiplayerLobbyID;
    cGcUniverseAddressData MultiplayerUA;
    cGcPlayerSpawnStateData MultiplayerSpawn;
    cTkDynamicArray<cGcRepairTechData> maRepairTechBuffer;
    unsigned long long mui64MultiplayerPrivileges;
    cTkFixedArray<cGcHotActionsSaveData> maHotActions;
    unsigned long long mui64LastUABeforePortalWarp;
    unsigned long long mui64StoryPortalSeed;
    unsigned short muiShopNumber;
    unsigned short muiShopTier;
    bool mbHasAccessToNexus;
    cGcUniverseAddressData NexusUniverseAddress;
    cTkVector3 mNexusMatrixAt;
    cTkVector3 mNexusMatrixUp;
    cTkVector3 mNexusMatrixPos;
    cGcPhotoModeSettings PhotoModeSettings;
    int miBannerIcon;
    int miBannerMainColour;
    int miBannerBackgroundColour;
    TkID<128> mBannerTitleId;
    int miTelemetryUploadVersion;
    bool mbUsesThirdPersonVehicleCam;
    float mfVRCameraOffset;
    cGcSeasonalGameModeData SeasonData;
    cGcSeasonStateData SeasonState;
    bool mbRestartAllInactiveSeasonalMissions;
    cTkDynamicArray<TkID<128>> maRedeemedSeasonRewards;
    cTkDynamicArray<TkID<128>> maRedeemedTwitchRewards;
    cTkDynamicArray<TkID<128>> maRedeemedPlatformRewards;
    cTkFixedArray<cGcSettlementState> maSettlementStatesV2;
    int miSettlementStateRingBufferIndexV2;
    bool mbNextLoadSpawnsWithFreshStart;
    cTkFixedArray<cGcStoryPageSeenDataArray> maSeenStories;
    cTkFixedArray<cGcWonderRecord> maWonderPlanetRecords;
    cTkFixedArray<cGcWonderRecord> maWonderCreatureRecords;
    cTkFixedArray<cGcWonderRecord> maWonderFloraRecords;
    cTkFixedArray<cGcWonderRecord> maWonderMineralRecords;
    cTkFixedArray<cGcWonderRecord> maWonderTreasureRecords;
    cTkFixedArray<cGcWonderRecord> maWonderWeirdBasePartRecords;
    cTkFixedArray<cGcWonderRecord> maWonderCustomRecords;
    cTkFixedArray<cGcWonderRecordCustomData> maWonderCustomRecordsExtraData;
    cTkFixedArray<cGcSyncBufferSaveDataArray> maSyncBuffersData;
    cTkDynamicArray<cGcMaintenanceSaveKey> maRefinerBufferKeys;
    cTkDynamicArray<cGcMaintenanceContainer> maRefinerBufferData;
}
