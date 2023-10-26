#pragma once

#include <skyscraper.h>
#include <gamestate/GcInventoryStore.h>
#include <gamestate/StatWatcher.h>
#include <gamestate/GcPlayerNPCWorkers.h>
#include <gamestate/GcSeasonState.h>
#include <simulation/vehicle/GcVehicleLocation.h>
#include <simulation/player/GcPlayerBanner.h>
#include <simulation/player/GcPlayerLogBook.h>
#include <simulation/customisation/GcResourceCustomisation.h>
#include <toolkit/data/TkMetaData.h>
#include <toolkit/utilities/TkString.h>
#include <toolkit/utilities/containers/TkUnorderedMap.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/containers/TkLinearHashTable.h>
#include <metadata/source/gamestate/playerdata/gcplayertitle.meta.h>
#include <metadata/source/gamestate/gcuniverseaddressdata.meta.h>
#include <metadata/source/resource/gcexactresource.meta.h>
#include <metadata/source/simulation/vehicles/gcvehicletype.meta.h>
#include <metadata/source/utilities/data/gcresourceelement.meta.h>
#include <metadata/source/gamestate/gcrepairtechdata.meta.h>
#include <metadata/source/gamestate/interactions/gcsavedinteractionracedata.meta.h>
#include <metadata/source/gamestate/gcwordgroupknowledge.meta.h>
#include <metadata/source/gamestate/gcsavedentitlement.meta.h>
#include <metadata/source/user/gcphotomodesettings.meta.h>
#include <metadata/source/gamestate/gcteleportendpoint.meta.h>
#include <metadata/source/gamestate/interactions/gcinteractiondata.meta.h>
#include <metadata/source/gamestate/gcportalsavedata.meta.h>
#include <metadata/source/simulation/weapons/gcplayerweapons.meta.h>
#include <metadata/source/wiki/gcstorypageseendataarray.meta.h>
#include <metadata/source/gamestate/gcsettlementstate.meta.h>
#include <metadata/source/reality/gcrewarddeath.meta.h>
#include <metadata/source/gamestate/gccustomisationdescriptorgroups.meta.h>
#include <metadata/source/gamestate/gccustomisationtextureoptions.meta.h>
#include <metadata/source/gamestate/gccustomisationpresets.meta.h>
#include <metadata/source/gamestate/gccustomisationcolourpalettes.meta.h>
#include <metadata/source/simulation/customisation/gccustomisationbannergroup.meta.h>
#include <metadata/source/simulation/customisation/gccustomisationthrustereffects.meta.h>
#include <metadata/source/simulation/customisation/gccustomisationshipbobbleheads.meta.h>

SKYSCRAPER_BEGIN

enum ePlayerFinalisePurchaseState
{
    EPlayerFinalisePurchaseState_None,
    EPlayerFinalisePurchaseState_SpawnNewShip,
};

struct sPlayerTitleStatWatcher : public IStatWatcher
{
    cTkUnorderedMap<TkID<128>, cGcPlayerTitle const *,TkIDUnorderedMap::Hash128 > mStatIdMap;
};

class cGcPlayerState
{
    struct ItemEvent
    {
        TkID<128> mId;
        float mfTime;
    };

    cTkFixedString<256,char> mNameWithTitle;
    sPlayerTitleStatWatcher mTitleStatWatcher;
    unsigned __int64 mu64ChangeRevision;
    cGcUniverseAddressData mGameStartLocation1;
    cGcUniverseAddressData mGameStartLocation2;
    cGcUniverseAddressData mLocation;
    cGcUniverseAddressData mPrevLocation;
    int miShield;
    int miHealth;
    int miShipHealth;
    unsigned int muUnits;
    unsigned int muNanites;
    unsigned int muSpecials;
    std::array<float,6> mafRestoreHazardTimers;
    int miRestoreShield;
    int miRestoreHealth;
    int miRestoreShipShield;
    int miRestoreShipHealth;
    int miRestoreEnergy;
    cGcExactResource mWeaponResource;
    cTkFixedArray<cGcInventoryStore,28> mInventories;
    cTkVector<cGcInventoryStore> mShelvedInventories;
    cTkFixedArray<cGcInventoryStore,7> mVehicleInventories;
    cTkFixedArray<cGcInventoryStore,7> mVehicleTechInventories;
    cTkFixedArray<cGcVehicleLocation,7> mVehicleLocations;
    eVehicleType mePrimaryVehicle;
    cTkFixedArray<cGcInventoryStore,12> mShipInventories;
    cTkVector<cGcInventoryStore> mShelvedShipInventories;
    cTkFixedArray<cGcInventoryStore,12> mShipInventoriesCargo;
    cTkFixedArray<cGcInventoryStore,12> mShipInventoriesTechOnly;
    cTkFixedArray<cGcResourceElement,12> mShipResources;
    int miPrimaryShip;
    cTkVector<cGcRepairTechData> mRepairTechBuffer;
    cTkVector<cTkVector3> maSurveyedEventPositions;
    cGcPlayerLogBook mPlayerLog;
    robin_hood::detail::Table<true, 80, TkID<128>, void,robin_hood::hash<TkID<128>,void>,std::equal_to<TkID<128> > > mSeenBaseBuildingObjects;
    cTkVector<TkID<128> > mKnownTechnologies;
    cTkVector<TkID<128> > mKnownProducts;
    cTkVector<TkID<256> > mKnownRefinerRecipes;
    cTkVector<cGcWordGroupKnowledge> mKnownWordGroups;
    unsigned __int64 mu64TotalPlayTime;
    unsigned __int64 mu64TimeAlive;
    float mfTimeAccumulator;
    unsigned __int64 mu64HazardTimeAlive;
    float mfHazardTimeAccumulator;
    float mfLastInventoryStoreTime;
    float mfLastInventoryFailTime;
    int miProcTechIndex;
    cTkFixedArray<cGcSavedInteractionRaceData,131> maSavedInteractionIndicies;
    cTkVector<TkID<256> > maInteractionLookupTable;
    cTkVector<cGcInventoryElement> mDefaultSuitLoadout;
    cTkVector<cGcInventoryElement> mDefaultWeaponLoadout;
    cTkVector<cGcInventoryElement> mDefaultShipLoadout;
    cTkVector<cGcInventoryElement> mGraveInventory;
    cGcUniverseAddressData mGraveLocation;
    cTkMatrix34 mGraveMatrix;
    bool mbSpawnGrave;
    bool mbSpaceGrave;
    bool mbPendingBootSpawnGrave;
    cTkVector<cGcUniverseAddressData> mAtlasStationLocations;
    cTkLinearHashTable<unsigned __int64,TkID<256>, cTkLinearHashTableHash<unsigned __int64> > maInteractionDialogMap;
    bool mbFirstAtlasStationDiscovered;
    bool mbUsesThirdPersonCharacterCam;
    cTkVector4 mInitialSpawnPosition;
    cTkVector4 mInitialShipPosition;
    int miProgressionLevel;
    unsigned __int64 mActiveBattleUA;
    cGcPlayerState::ItemEvent mLastBuiltProduct;
    cGcPlayerState::ItemEvent mLastBuiltTech;
    cGcPlayerState::ItemEvent mLastRepairedTech;
    int miSlots;
    int miLevel;
    int miMaxTechValue;
    int miMaxTechs;
    bool mbFillAllSlots;
    bool mbWarpFromBlackHole;
    bool mbRevealBlackHoles;
    bool mbWarpFromRelicGate;
    bool mbWarpFromFreighterMegaWarp;
    bool mbUseSmallerBlackholeJumps;
    bool mbIsDataNew;
    cTkVector<cGcSavedEntitlement> maUsedEntitlements;
    unsigned __int64 mu64LastSpaceBattleTime;
    int miLastSpaceBattleWarps;
    unsigned __int64 mu64LastMiniStationTime;
    int miLastMiniStationWarps;
    unsigned __int64 mMiniStationLocation;
    cTkVector3 mAnomalyPositionOverride;
    cGcPhotoModeSettings mPhotoModeSettings;
    cTkVector<cGcTeleportEndpoint> maTeleportEndpoints;
    cGcPlayerNPCWorkers mPlayerNPCWorkers;
    cGcInteractionData mHoloExplorerInteraction;
    cGcInteractionData mHoloScepticInteraction;
    cGcInteractionData mHoloNooneInteraction;
    cGcInteractionData mNetworkPlayerInteraction;
    cTkVector4 mStartGameShipPosition;
    bool mbShipNeedsTerrainPositioning;
    cTkFixedString<32,char> mCustomWeaponName;
    cTkFixedString<32,char> maCustomShipNames[12];
    cTkFixedString<32,char> maCustomVehicleNames[7];
    cTkVector<cGcPortalSaveData> maLastPortal;
    cGcPortalSaveData mLastPortal;
    int miKnownPortalRunes;
    bool mbOnOtherSideOfPortal;
    cGcTeleportEndpoint mOtherSideOfPortalReturnBase;
    cTkPhysRelVec3 mPortalMarkerPosition;
    unsigned __int64 mu64LastUABeforePortalWarp;
    unsigned __int64 mu64ActiveStoryPortalSeed;
    std::pair<TkID<128>,cTkSeed> mPreviousMission;
    std::pair<TkID<128>,cTkSeed> mCurrentMission;
    eWeaponMode meStartingPrimaryWeapon;
    eWeaponMode meStartingSecondaryWeapon;
    float mfVRCameraOffset;
    bool mbThirdPersonShipCam;
    bool mbThirdPersonVehicleCam;
    bool mbNextLoadSpawnsWithFreshStart;
    bool mbInitialised;
    bool mbVehicleAIControlEnabled;
    bool mbHasAccessToNexus;
    cGcUniverseAddressData mNexusUniverseLocation;
    cTkMatrix34 mNexusSavedMatrix;
    std::array<cGcResourceCustomisation,23> mCustomisationData;
    std::array<cGcResourceCustomisation,3> mOutfits;
    cTkFixedArray<cGcStoryPageSeenDataArray,8> maSeenStoriesData;
    TkID<128> mJetpackEffect;
    cGcPlayerBanner mPlayerBanner;
    cGcSeasonState mSeasonState;
    robin_hood::detail::Table<true,80,TkID<128>,void,robin_hood::hash<TkID<128>,void>,std::equal_to<TkID<128> > > mRedeemedSpecials;
    robin_hood::detail::Table<true,80,TkID<128>,void,robin_hood::hash<TkID<128>,void>,std::equal_to<TkID<128> > > mRedeemedSeasonRewards;
    robin_hood::detail::Table<true,80,TkID<128>,void,robin_hood::hash<TkID<128>,void>,std::equal_to<TkID<128> > > mRedeemedTwitchRewards;
    robin_hood::detail::Table<true,80,TkID<128>,void,robin_hood::hash<TkID<128>,void>,std::equal_to<TkID<128> > > mRedeemedPlatformRewards;
    TkID<128> mPendingRewardId;
    bool mbHasPendingRewardFromSeason;
    bool mbHasPendingRewardFromTwitch;
    bool mbHasPendingRewardFromPlatform;
    ePlayerFinalisePurchaseState meFinalisePurchaseState;
    cGcSettlementState maSettlementStates[100];
    int miSettlementStateRingBufferIndex;
    cTkFixedString<128,char> macSaveName;
    cTkFixedString<128,char> macSaveSummary;
    const cGcRewardDeath *mpDeathReward;
    cGcCustomisationDescriptorGroups *mpCharacterCustomisationDescriptorGroups;
    cGcCustomisationTextureOptions *mpCharacterCustomisationTextureOptions;
    cGcCustomisationPresets *mpCharacterCustomisationPresets;
    cGcCustomisationColourPalettes *mpCustomisationColourPalettes;
    cGcCustomisationBannerGroup *mpCustomisationBannerData;
    cGcCustomisationThrusterEffects *mpCustomisationThrusterData;
    cGcCustomisationShipBobbleHeads *mpCustomisationShipBobbleHeads;
};

SKYSCRAPER_END