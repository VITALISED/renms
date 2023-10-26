#pragma once

#include <skyscraper.h>

#include <metadata/source/reality/gcrealitymanagerdata.meta.h>
#include <metadata/source/reality/gcsubstancetable.meta.h>
#include <metadata/source/reality/gctechnologytable.meta.h>
#include <metadata/source/reality/gcproducttable.meta.h>
#include <metadata/source/reality/gcproceduralproducttable.meta.h>
#include <metadata/source/reality/gcproceduraltechnologytable.meta.h>
#include <metadata/source/reality/gclegacyitemtable.meta.h>
#include <metadata/source/reality/gcconsumableitemtable.meta.h>
#include <metadata/source/reality/gcrecipetable.meta.h>
#include <metadata/source/wiki/gcstoriestable.meta.h>
#include <metadata/source/reality/gcrewardtable.meta.h>
#include <metadata/source/reality/gcdiscoveryrewardlookuptable.meta.h>
#include <metadata/source/simulation/missions/gcmissiontable.meta.h>
#include <metadata/source/simulation/missions/scheduling/gcmissionschedulestable.meta.h>
#include <metadata/source/simulation/missions/scheduling/gcmissioncommunitydata.meta.h>
#include <metadata/source/reality/gcinventorytable.meta.h>
#include <metadata/source/reality/gcmaintenancegroupstable.meta.h>
#include <metadata/source/reality/gcunlockabletrees.meta.h>
#include <metadata/source/simulation/player/gcplayeremotelist.meta.h>
#include <metadata/source/reality/gcplayerdamagetable.meta.h>
#include <metadata/source/reality/gcpurchaseablebuildingblueprints.meta.h>
#include <metadata/source/reality/gcpurchaseablespecials.meta.h>
#include <metadata/source/reality/gcunlockableseasonrewards.meta.h>
#include <metadata/source/reality/gcunlockabletwitchrewards.meta.h>
#include <metadata/source/reality/gcunlockableplatformrewards.meta.h>
#include <metadata/source/reality/gcsettlementperkstable.meta.h>
#include <metadata/source/wiki/gcwiki.meta.h>
#include <metadata/source/gamestate/trading/gcitemcosttable.meta.h>
#include <metadata/source/reality/gctradingclasstable.meta.h>
#include <metadata/source/reality/gccosttable.meta.h>
#include <metadata/source/simulation/weapons/gcplayerweaponpropertiestable.meta.h>
#include <metadata/source/gameplay/gccombateffectstable.meta.h>
#include <metadata/source/reality/gcplayertitledata.meta.h>
#include <metadata/source/reality/gcdialogclearancetable.meta.h>
#include <metadata/source/simulation/galaxy/gcgalaxyinfoicons.meta.h>
#include <metadata/source/reality/gcalienspeechtable.meta.h>
#include <metadata/source/reality/gcproceduralproductcategory.meta.h>
#include <metadata/source/reality/gctechboxtable.meta.h>
#include <metadata/toolkit/tktextureresource.meta.h>
#include <metadata/source/simulation/missions/gcgenericmissionsequence.meta.h>
#include <metadata/source/reality/gcalienpuzzleoption.meta.h>

#include <toolkit/utilities/containers/TkUnorderedMap.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <reality/GcNameGenerator.h>

SKYSCRAPER_BEGIN

enum eMissionTable : __int32
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
    EMissionTable_SentinelsAndSettlements ,
    EMissionTable_Pirates,
    EMissionTable_StatStories,
    EMissionTable_Mods,
    EMissionTable_Debug,
    EMissionTable_NumTables = 21,
};

struct PuzzleOptionOverride
{
    const cGcAlienPuzzleEntry *mpPuzzle;
    int miOptionIndex;
    cGcAlienPuzzleOption mOverride;
};

class cGcRealityManager
{
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
    cGcMissionTable *mapMissionTables[21];
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

    cTkUnorderedMap<TkID<128>,cGcPlayerTitle *,TkIDUnorderedMap::Hash128 > mTitleIDMap;
    cTkVector<cGcTechnology *> mPendingNewTechnologies;
    cTkUnorderedMap<TkID<128>, cGcRealitySubstanceData *,TkIDUnorderedMap::Hash128 > mSubstanceIDMap;
    cTkUnorderedMap<TkID<128>, cGcTechnology *,TkIDUnorderedMap::Hash128 > mTechnologyIDMap;
    cTkUnorderedMap<TkID<128>, cGcProceduralTechnologyData *,TkIDUnorderedMap::Hash128 > mProcTechnologyIDMap;
    cTkUnorderedMap<TkID<128>, cGcProductData *,TkIDUnorderedMap::Hash128 > mProductIDMap;
    cTkUnorderedMap<TkID<128>, eProceduralProductCategory,TkIDUnorderedMap::Hash128 > mProcProductIDMap;

    robin_hood::detail::Table<true, 80, unsigned int, TkID<128>, robin_hood::hash<unsigned int,void>,std::equal_to<unsigned int> > mHashedTechIDMap;

    cTkUnorderedMap<TkID<128>,cGcLegacyItem *,TkIDUnorderedMap::Hash128> mLegacyItemIDMap;
    cTkUnorderedMap<TkID<128>,cGcConsumableItem *,TkIDUnorderedMap::Hash128> mConsumableItemIDMap;
    cTkUnorderedMap<TkID<256>,cGcRefinerRecipe *,TkIDUnorderedMap::Hash256> mRecipeIDMap;
    cTkUnorderedMap<TkID<128>,cGcDamageMultiplierLookup *,TkIDUnorderedMap::Hash128> mDamageMultiplierIDMap;
    cTkUnorderedMap<TkID<128>,cGcRewardTableEntry *,TkIDUnorderedMap::Hash128> mRewardIDMap;
    cTkUnorderedMap<TkID<128>,cGcRewardTableItemList *,TkIDUnorderedMap::Hash128> mGenericRewardIDMap;
    cTkUnorderedMap<TkID<128>,cGcRewardTableEntitlementItem *,TkIDUnorderedMap::Hash128> mEntitlementRewardIDMap;
    cTkUnorderedMap<TkID<128>,cGcDiscoveryRewardLookup *,TkIDUnorderedMap::Hash128> mDiscoveryRewardIDMap;
    cTkUnorderedMap<TkID<128>,cGcRewardTableItemList *,TkIDUnorderedMap::Hash128> mMixerRewardIDMap;
    cTkUnorderedMap<TkID<128>,cGcPurchaseableSpecial *,TkIDUnorderedMap::Hash128> mPurchaseableSpecialsIDMap;
    cTkUnorderedMap<TkID<128>,cGcUnlockableSeasonReward *,TkIDUnorderedMap::Hash128> mUnlockableSeasonRewardsIDMap;
    cTkUnorderedMap<TkID<128>,cGcUnlockableTwitchReward *,TkIDUnorderedMap::Hash128> mUnlockableTwitchRewardsIDMap;
    cTkUnorderedMap<TkID<128>,cGcUnlockablePlatformReward *,TkIDUnorderedMap::Hash128> mUnlockablePlatformRewardsIDMap;
    cTkUnorderedMap<TkID<128>,cGcSettlementPerkData *,TkIDUnorderedMap::Hash128> mSettlementPerksIDMap;
    cTkUnorderedMap<TkID<128>,cGcPlayerDamageData *,TkIDUnorderedMap::Hash128> mDamageIDMap;
    cTkUnorderedMap<TkID<128>,cGcInventoryTableEntry *,TkIDUnorderedMap::Hash128> mInventoryRewardIDMap;
    cTkUnorderedMap<TkID<128>,cGcCostTableEntry *,TkIDUnorderedMap::Hash128> mCostIDMap;
    cTkUnorderedMap<TkID<128>,cGcInventoryBaseStat *,TkIDUnorderedMap::Hash128> mBaseStatIDMap;
    cTkUnorderedMap<TkID<128>,cGcItemCostData *,TkIDUnorderedMap::Hash128> mItemCostIDMap;
    cTkUnorderedMap<TkID<128>,cGcRealityManager::MissionLookup,TkIDUnorderedMap::Hash128> mMissionIDMap;
    cTkUnorderedMap<TkID<128>,cGcPlayerEmote *,TkIDUnorderedMap::Hash128> mEmoteIDMap;
    cTkUnorderedMap<TkID<128>,cGcGenericMissionSequence *,TkIDUnorderedMap::Hash128> mCostToMissionMap;
    cTkUnorderedMap<TkID<128>,cGcGenericMissionSequence *,TkIDUnorderedMap::Hash128> mRewardToMissionMap;
    cTkUnorderedMap<TkID<256>,cGcGenericMissionSequence *,TkIDUnorderedMap::Hash256> mDialogToMissionMap;
    cTkUnorderedMap<TkID<256>,cGcGenericMissionSequence *,TkIDUnorderedMap::Hash256> mScanEventToMissionMap;
    cTkUnorderedMap<TkID<128>,cTkVector<TkID<128> >,TkIDUnorderedMap::Hash128> mRealityItemGroupsIDMap;
    cTkUnorderedMap<TkID<256>,cTkTextureResource *,TkIDUnorderedMap::Hash256> mRealityIconResourceMap;
    cTkVector<PuzzleOptionOverride> maPuzzleOptionOverrides;
    robin_hood::detail::Table<true, 80, TkID<256>,void,robin_hood::hash<TkID<256>,void>,std::equal_to<TkID<256> > > mWikiTopics;
    cGcGalaxyInfoIcons *mpGalacticMapIcons;
    cGcAlienSpeechTable *mpAlienWords;
    cGcNameGenerator mNameGenerator;
    cTkVector<cGcTechnology *> mapRepairTechs;
    cTkVector<std::pair<cGcAlienPuzzleTable const *,int> > mapAlienPuzzleTables;
    cGcDialogClearanceTable *mpDialogClearanceTable;
    std::array<cTkTextureResource,6> maDynamicHazardProtectionIcons;
};

SKYSCRAPER_END
