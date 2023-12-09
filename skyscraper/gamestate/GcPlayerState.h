/**
 * @file GcPlayerState.h
 * @author VITALISED & Contributors
 * @since 2023-12-09
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

#include <gamestate/GcInventoryStore.h>
#include <gamestate/GcPlayerBanner.h>
#include <gamestate/GcPlayerLogBook.h>
#include <gamestate/GcPlayerNPCWorkers.h>
#include <gamestate/GcSeasonState.h>
#include <gamestate/GcStatsManager.h>
#include <resources/GcResourceManager.h>
#include <toolkit/core/types/TkID.h>
#include <toolkit/maths/geometry/TkPhysRelVec3.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/utilities/containers/TkLinearHashTable.h>
#include <toolkit/utilities/containers/TkUnorderedMap.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <gamestate/gccustomisationcolourpalettes.meta.h>
#include <gamestate/gccustomisationdescriptorgroups.meta.h>
#include <gamestate/gccustomisationpresets.meta.h>
#include <gamestate/gccustomisationtextureoptions.meta.h>
#include <gamestate/gcplayerstatedata.meta.h>
#include <gamestate/gcrepairtechdata.meta.h>
#include <gamestate/gcsavedentitlement.meta.h>
#include <gamestate/gcuniverseaddressdata.meta.h>
#include <gamestate/gcwordgroupknowledge.meta.h>
#include <gamestate/interactions/gcsavedinteractionracedata.meta.h>
#include <gamestate/playerdata/gcplayertitle.meta.h>
#include <metadata/regcexactresource.meta.h>
#include <reality/gcrewarddeath.meta.h>
#include <simulation/customisation/gccustomisationbannergroup.meta.h>
#include <simulation/customisation/gccustomisationshipbobbleheads.meta.h>
#include <simulation/customisation/gccustomisationthrustereffects.meta.h>
#include <simulation/vehicles/gcvehicletype.meta.h>
#include <utilities/data/gcresourceelement.meta.h>

SKYSCRAPER_BEGIN

enum ePlayerFinalisePurchaseState
{
    EPlayerFinalisePurchaseState_None,
    EPlayerFinalisePurchaseState_SpawnNewShip,
};

struct sPlayerTitleStatWatcher : IStatWatcher
{
    cTkUnorderedMap<TkID<128>, cGcPlayerTitle const *, TkIDUnorderedMap::Hash128> mStatIdMap;
};

class cGcVehicleLocation
{
  public:
    uint64_t mLocation;
    cTkVector4 mPosition;
    cTkVector4 mDirection;
};

class cGcPlayerState
{
  public:
    struct ItemEvent
    {
        TkID<128> mId;
        float mfTime;
    };

    cTkFixedString<256, char> mNameWithTitle;
    sPlayerTitleStatWatcher mTitleStatWatcher;
    uint64_t mu64ChangeRevision;
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
    std::array<float, 6> mafRestoreHazardTimers;
    int miRestoreShield;
    int miRestoreHealth;
    int miRestoreShipShield;
    int miRestoreShipHealth;
    int miRestoreEnergy;
    cGcExactResource mWeaponResource;
    cTkFixedArray<cGcInventoryStore, 28> mInventories;
    cTkVector<cGcInventoryStore> mShelvedInventories;
    cTkFixedArray<cGcInventoryStore, 7> mVehicleInventories;
    cTkFixedArray<cGcInventoryStore, 7> mVehicleTechInventories;
    cTkFixedArray<cGcVehicleLocation, 7> mVehicleLocations;
    eVehicleType mePrimaryVehicle;
    cTkFixedArray<cGcInventoryStore, 12> mShipInventories;
    cTkVector<cGcInventoryStore> mShelvedShipInventories;
    cTkFixedArray<cGcInventoryStore, 12> mShipInventoriesCargo;
    cTkFixedArray<cGcInventoryStore, 12> mShipInventoriesTechOnly;
    cTkFixedArray<cGcResourceElement, 12> mShipResources;
    int miPrimaryShip;
    cTkVector<cGcRepairTechData> mRepairTechBuffer;
    cTkVector<cTkVector3> maSurveyedEventPositions;
    cGcPlayerLogBook mPlayerLog;
    robin_hood::detail::Table<true, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128>>>
        mSeenBaseBuildingObjects;
    cTkVector<TkID<128>> mKnownTechnologies;
    cTkVector<TkID<128>> mKnownProducts;
    cTkVector<TkID<256>> mKnownRefinerRecipes;
    cTkVector<cGcWordGroupKnowledge> mKnownWordGroups;
    uint64_t mu64TotalPlayTime;
    uint64_t mu64TimeAlive;
    float mfTimeAccumulator;
    uint64_t mu64HazardTimeAlive;
    float mfHazardTimeAccumulator;
    float mfLastInventoryStoreTime;
    float mfLastInventoryFailTime;
    int miProcTechIndex;
    cTkFixedArray<cGcSavedInteractionRaceData, 131> maSavedInteractionIndicies;
    cTkVector<TkID<256>> maInteractionLookupTable;
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
    cTkLinearHashTable<uint64_t, TkID<256>, cTkLinearHashTableHash<uint64_t>> maInteractionDialogMap;
    bool mbFirstAtlasStationDiscovered;
    bool mbUsesThirdPersonCharacterCam;
    cTkVector4 mInitialSpawnPosition;
    cTkVector4 mInitialShipPosition;
    int miProgressionLevel;
    uint64_t mActiveBattleUA;
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
    uint64_t mu64LastSpaceBattleTime;
    int miLastSpaceBattleWarps;
    uint64_t mu64LastMiniStationTime;
    int miLastMiniStationWarps;
    uint64_t mMiniStationLocation;
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
    cTkFixedString<32, char> mCustomWeaponName;
    cTkFixedString<32, char> maCustomShipNames[12];
    cTkFixedString<32, char> maCustomVehicleNames[7];
    cTkVector<cGcPortalSaveData> maLastPortal;
    cGcPortalSaveData mLastPortal;
    int miKnownPortalRunes;
    bool mbOnOtherSideOfPortal;
    cGcTeleportEndpoint mOtherSideOfPortalReturnBase;
    cTkPhysRelVec3 mPortalMarkerPosition;
    uint64_t mu64LastUABeforePortalWarp;
    uint64_t mu64ActiveStoryPortalSeed;
    std::pair<TkID<128>, cTkSeed> mPreviousMission;
    std::pair<TkID<128>, cTkSeed> mCurrentMission;
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
    std::array<cGcResourceCustomisation, 23> mCustomisationData;
    std::array<cGcResourceCustomisation, 3> mOutfits;
    cTkFixedArray<cGcStoryPageSeenDataArray, 8> maSeenStoriesData;
    TkID<128> mJetpackEffect;
    cGcPlayerBanner mPlayerBanner;
    cGcSeasonState mSeasonState;
    robin_hood::detail::Table<true, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128>>>
        mRedeemedSpecials;
    robin_hood::detail::Table<true, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128>>>
        mRedeemedSeasonRewards;
    robin_hood::detail::Table<true, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128>>>
        mRedeemedTwitchRewards;
    robin_hood::detail::Table<true, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128>>>
        mRedeemedPlatformRewards;
    TkID<128> mPendingRewardId;
    bool mbHasPendingRewardFromSeason;
    bool mbHasPendingRewardFromTwitch;
    bool mbHasPendingRewardFromPlatform;
    ePlayerFinalisePurchaseState meFinalisePurchaseState;
    cGcSettlementState maSettlementStates[100];
    int miSettlementStateRingBufferIndex;
    cTkFixedString<128, char> macSaveName;
    cTkFixedString<128, char> macSaveSummary;
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