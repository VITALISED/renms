#pragma once

#include <skyscraper.h>

#include <reality/GcNameGenerator.h>
#include <toolkit/utilities/containers/TkUnorderedMap.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <gameplay/gccombateffectstable.meta.h>
#include <gamestate/playerdata/gcplayertitle.meta.h>
#include <gamestate/trading/gcitemcosttable.meta.h>
#include <reality/gcalienspeechtable.meta.h>
#include <reality/gcconsumableitemtable.meta.h>
#include <reality/gccosttable.meta.h>
#include <reality/gcdialogclearancetable.meta.h>
#include <reality/gcdiscoveryrewardlookuptable.meta.h>
#include <reality/gcinventorytable.meta.h>
#include <reality/gclegacyitemtable.meta.h>
#include <reality/gcmaintenancegroupstable.meta.h>
#include <reality/gcplayerdamagetable.meta.h>
#include <reality/gcplayertitledata.meta.h>
#include <reality/gcproceduralproductcategory.meta.h>
#include <reality/gcproceduralproducttable.meta.h>
#include <reality/gcproceduraltechnologytable.meta.h>
#include <reality/gcproducttable.meta.h>
#include <reality/gcpurchaseablebuildingblueprints.meta.h>
#include <reality/gcpurchaseablespecials.meta.h>
#include <reality/gcrealitymanagerdata.meta.h>
#include <reality/gcrecipetable.meta.h>
#include <reality/gcrewardtable.meta.h>
#include <reality/gcsettlementperkstable.meta.h>
#include <reality/gcsubstancetable.meta.h>
#include <reality/gctechboxtable.meta.h>
#include <reality/gctechnologytable.meta.h>
#include <reality/gctradingclasstable.meta.h>
#include <reality/gcunlockableplatformrewards.meta.h>
#include <reality/gcunlockableseasonrewards.meta.h>
#include <reality/gcunlockabletrees.meta.h>
#include <reality/gcunlockabletwitchrewards.meta.h>
#include <simulation/galaxy/gcgalaxyinfoicons.meta.h>
#include <simulation/missions/gcmissiontable.meta.h>
#include <simulation/missions/scheduling/gcmissioncommunitydata.meta.h>
#include <simulation/missions/scheduling/gcmissionschedulestable.meta.h>
#include <simulation/player/gcplayeremotelist.meta.h>
#include <simulation/weapons/gcplayerweaponpropertiestable.meta.h>
#include <wiki/gcstoriestable.meta.h>
#include <wiki/gcwiki.meta.h>

SKYSCRAPER_BEGIN

enum eMissionTable
{
    EMissionTable_Main,
    EMissionTable_NPC,
    EMissionTable_Wiki,
    EMissionTable_Core,
    EMissionTable_Tutorial,
    EMissionTable_AtlasPath,
    EMissionTable_Recurring,
    EMissionTable_Fleet,
    EMissionTable_Water,
    EMissionTable_Multiplayer,
    EMissionTable_BaseComputer,
    EMissionTable_Community,
    EMissionTable_PlanetProc,
    EMissionTable_SpecialDialog,
    EMissionTable_SpacePOI,
    EMissionTable_Seasonal,
    EMissionTable_SentinelsAndSettlements,
    EMissionTable_Pirates,
    EMissionTable_StatStories,
    EMissionTable_Mods,
    EMissionTable_NumTables,
};

struct PuzzleOptionOverride
{
    const cGcAlienPuzzleEntry *mpPuzzle;
    int miOptionIndex;
    cGcAlienPuzzleOption mOverride;
};

class cGcRealityManager
{
  public:
    struct MissionLookup
    {
        cGcGenericMissionSequence *mpMission;
        eMissionTable meTable;
    };

    cGcRealityManagerData *mpData;
    cGcSubstanceTable *mpSubstanceTable;
    cGcTechnologyTable *mpTechnologyTable;
    cGcProductTable *mpProductTable;
    cGcProceduralProductTable *mpProceduralProductTable;
    cGcProceduralTechnologyTable *mpProceduralTechTable;
    cGcLegacyItemTable *mpLegacyItemsTable;
    cGcTechBoxTable *mpTechBoxProductTable;
    cGcConsumableItemTable *mpConsumableItemTable;
    cGcRecipeTable *mpRecipeTable;
    cGcStoriesTable *mpStoriesTable;
    cGcRewardTable *mpRewardTable;
    cGcDiscoveryRewardLookupTable *mpDiscoveryRewardTable;
    cGcMissionTable *mapMissionTables[20];
    cGcMissionSchedulesTable *mpMissionSchedulesTable;
    cGcMissionCommunityData *mpMissionCommunityData;
    cGcInventoryTable *mpInventoryTable;
    cGcMaintenanceGroupsTable *mpMaintenanceGroupsTable;
    float mMaintenanceGroupTotalWeightings[7];
    cGcUnlockableTrees *mpUnlockableTrees;
    cGcPlayerEmoteList *mpEmotesList;
    cGcPlayerDamageTable *mpPlayerDamageTable;
    cGcPurchaseableBuildingBlueprints *mpPurchaseableBuildingsTable;
    cGcPurchaseableSpecials *mpPurchaseableSpecialsTables;
    cGcUnlockableSeasonRewards *mpUnlockableSeasonRewardsTable;
    cGcUnlockableTwitchRewards *mpUnlockableTwitchRewardsTable;
    cGcUnlockablePlatformRewards *mpUnlockablePlatformRewardsTable;
    cGcSettlementPerksTable *mpSettlementPerksTable;
    cGcWiki *mpWiki;
    cGcWiki *mpCatalogue;
    cGcWiki *mapCatalogues[5];
    cGcItemCostTable *mpItemCostTable;
    cGcTradingClassTable *mpTradingClassTable;
    cGcCostTable *mpCostTable;
    cGcPlayerWeaponPropertiesTable *mpPlayerWeaponPropertiesTable;
    cGcCombatEffectsTable *mpCombatEffectsTable;
    cGcPlayerTitleData *mpPlayerTitleData;
    cTkUnorderedMap<TkID<128>, cGcPlayerTitle *, TkIDUnorderedMap::Hash128> mTitleIDMap;
    cTkVector<cGcTechnology *> mPendingNewTechnologies;
    cTkUnorderedMap<TkID<128>, cGcRealitySubstanceData *, TkIDUnorderedMap::Hash128> mSubstanceIDMap;
    cTkUnorderedMap<TkID<128>, cGcTechnology *, TkIDUnorderedMap::Hash128> mTechnologyIDMap;
    cTkUnorderedMap<TkID<128>, cGcProceduralTechnologyData *, TkIDUnorderedMap::Hash128> mProcTechnologyIDMap;
    cTkUnorderedMap<TkID<128>, cGcProductData *, TkIDUnorderedMap::Hash128> mProductIDMap;
    cTkUnorderedMap<TkID<128>, eProceduralProductCategory, TkIDUnorderedMap::Hash128> mProcProductIDMap;
    robin_hood::detail::Table<
        true, 80, unsigned int, TkID<128>, robin_hood::hash<unsigned int, void>, std::equal_to<unsigned int>>
        mHashedTechIDMap;
    cTkUnorderedMap<TkID<128>, cGcLegacyItem *, TkIDUnorderedMap::Hash128> mLegacyItemIDMap;
    cTkUnorderedMap<TkID<128>, cGcConsumableItem *, TkIDUnorderedMap::Hash128> mConsumableItemIDMap;
    cTkUnorderedMap<TkID<256>, cGcRefinerRecipe *, TkIDUnorderedMap::Hash256> mRecipeIDMap;
    cTkUnorderedMap<TkID<128>, cGcDamageMultiplierLookup *, TkIDUnorderedMap::Hash128> mDamageMultiplierIDMap;
    cTkUnorderedMap<TkID<128>, cGcRewardTableEntry *, TkIDUnorderedMap::Hash128> mRewardIDMap;
    cTkUnorderedMap<TkID<128>, cGcRewardTableItemList *, TkIDUnorderedMap::Hash128> mGenericRewardIDMap;
    cTkUnorderedMap<TkID<128>, cGcRewardTableEntitlementItem *, TkIDUnorderedMap::Hash128> mEntitlementRewardIDMap;
    cTkUnorderedMap<TkID<128>, cGcDiscoveryRewardLookup *, TkIDUnorderedMap::Hash128> mDiscoveryRewardIDMap;
    cTkUnorderedMap<TkID<128>, cGcRewardTableItemList *, TkIDUnorderedMap::Hash128> mMixerRewardIDMap;
    cTkUnorderedMap<TkID<128>, cGcPurchaseableSpecial *, TkIDUnorderedMap::Hash128> mPurchaseableSpecialsIDMap;
    cTkUnorderedMap<TkID<128>, cGcUnlockableSeasonReward *, TkIDUnorderedMap::Hash128> mUnlockableSeasonRewardsIDMap;
    cTkUnorderedMap<TkID<128>, cGcUnlockableTwitchReward *, TkIDUnorderedMap::Hash128> mUnlockableTwitchRewardsIDMap;
    cTkUnorderedMap<TkID<128>, cGcUnlockablePlatformReward *, TkIDUnorderedMap::Hash128>
        mUnlockablePlatformRewardsIDMap;
    cTkUnorderedMap<TkID<128>, cGcSettlementPerkData *, TkIDUnorderedMap::Hash128> mSettlementPerksIDMap;
    cTkUnorderedMap<TkID<128>, cGcPlayerDamageData *, TkIDUnorderedMap::Hash128> mDamageIDMap;
    cTkUnorderedMap<TkID<128>, cGcInventoryTableEntry *, TkIDUnorderedMap::Hash128> mInventoryRewardIDMap;
    cTkUnorderedMap<TkID<128>, cGcCostTableEntry *, TkIDUnorderedMap::Hash128> mCostIDMap;
    cTkUnorderedMap<TkID<128>, cGcInventoryBaseStat *, TkIDUnorderedMap::Hash128> mBaseStatIDMap;
    cTkUnorderedMap<TkID<128>, cGcItemCostData *, TkIDUnorderedMap::Hash128> mItemCostIDMap;
    cTkUnorderedMap<TkID<128>, cGcRealityManager::MissionLookup, TkIDUnorderedMap::Hash128> mMissionIDMap;
    cTkUnorderedMap<TkID<128>, cGcPlayerEmote *, TkIDUnorderedMap::Hash128> mEmoteIDMap;
    cTkUnorderedMap<TkID<128>, cGcGenericMissionSequence *, TkIDUnorderedMap::Hash128> mCostToMissionMap;
    cTkUnorderedMap<TkID<128>, cGcGenericMissionSequence *, TkIDUnorderedMap::Hash128> mRewardToMissionMap;
    cTkUnorderedMap<TkID<256>, cGcGenericMissionSequence *, TkIDUnorderedMap::Hash256> mDialogToMissionMap;
    cTkUnorderedMap<TkID<256>, cGcGenericMissionSequence *, TkIDUnorderedMap::Hash256> mScanEventToMissionMap;
    cTkUnorderedMap<TkID<128>, cTkVector<TkID<128>>, TkIDUnorderedMap::Hash128> mRealityItemGroupsIDMap;
    cTkUnorderedMap<TkID<256>, cTkTextureResource *, TkIDUnorderedMap::Hash256> mRealityIconResourceMap;
    cTkVector<PuzzleOptionOverride> maPuzzleOptionOverrides;
    robin_hood::detail::Table<true, 80, TkID<256>, void, robin_hood::hash<TkID<256>, void>, std::equal_to<TkID<256>>>
        mWikiTopics;
    cGcGalaxyInfoIcons *mpGalacticMapIcons;
    cGcAlienSpeechTable *mpAlienWords;
    cGcNameGenerator mNameGenerator;
    cTkVector<cGcTechnology *> mapRepairTechs;
    cTkVector<std::pair<cGcAlienPuzzleTable const *, int>> mapAlienPuzzleTables;
    cGcDialogClearanceTable *mpDialogClearanceTable;
    std::array<cTkTextureResource, 6> maDynamicHazardProtectionIcons;
};

SKYSCRAPER_END