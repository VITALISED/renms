/**
 * @file GcWonderData.h
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

#include <gamestate/GcDiscoveryCommon.h>
#include <gamestate/GcDiscoverySearch.h>
#include <graphics/2d/GcProceduralTexture.h>

#include <simulation/ecosystem/gccreatureroledatatable.meta.h>
#include <simulation/ecosystem/gccreaturespawndata.meta.h>
#include <simulation/solarsystem/planet/gcbiomesubtype.meta.h>
#include <simulation/solarsystem/planet/gcbiometype.meta.h>
#include <simulation/solarsystem/planet/gcplanethazarddata.meta.h>
#include <simulation/solarsystem/planet/gcplanetsize.meta.h>
#include <simulation/solarsystem/planet/gcplanetweatherdata.meta.h>
#include <wiki/gcwonderrecord.meta.h>
#include <wiki/gcwonderrecordcustomdata.meta.h>
#include <wiki/gcwondertype.meta.h>

SKYSCRAPER_BEGIN

enum eModelViews : __int32
{
    EModelViews_Suit,
    EModelViews_Weapon,
    EModelViews_Ship,
    EModelViews_Vehicle,
    EModelViews_DiscoveryMain,
    EModelViews_DiscoveryThumbnail,
    EModelViews_WonderThumbnail,
    EModelViews_WonderThumbnailCreatureSmall,
    EModelViews_WonderThumbnailCreatureMed,
    EModelViews_WonderThumbnailCreatureLarge,
    EModelViews_WonderThumbnailFloraSmall,
    EModelViews_WonderThumbnailFloraLarge,
    EModelViews_WonderThumbnailMineralSmall,
    EModelViews_WonderThumbnailMineralLarge,
    EModelViews_ToolboxMain,
    EModelViews_ToolboxThumbnail,
    EModelViews_TradeSuit,
    EModelViews_TradeShip,
    EModelViews_TradeCompareShips,
    EModelViews_TradeCompareWeapons,
    EModelViews_HUDThumbnail,
    EModelViews_Interaction,
    EModelViews_Freighter,
    EModelViews_TradeFreighter,
    EModelViews_TradeChest,
    EModelViews_TradeCapsule,
    EModelViews_TradeFrigate,
    EModelViews_TerrainBall,
    EModelViews_FreighterChest,
    EModelViews_Submarine,
    EModelViews_TradeCooker,
    EModelViews_SuitRefiner,
    EModelViews_FreighterRepair,
    EModelViews_DiscoveryPlanetaryMapping,
    EModelViews_Mech,
    EModelViews_PetThumbnail,
    EModelViews_PetThumbnailUI,
    EModelViews_PetLarge,
    EModelViews_SquadronPilotLarge,
    EModelViews_SquadronPilotThumbnail,
    EModelViews_SquadronSpaceshipThumbnail,
    EModelViews_NumTypes,
};

class cGcPlanetGenerationWonderQuery
{
  public:
    float mfPlanetRadius;
    ePlanetSize mePlanetSize;
    float mfDeepestOcean;
    float mfHighestPeak;
    cGcPlanetWeatherData mWeather;
    cGcPlanetHazardData mHazard;
    bool mbHasSentinels;
    bool mbHasExtremeSentinels;
    eBiome meBiome;
    eBiomeSubType meBiomeSubType;
    bool mbHasWater;
    bool mbHasRings;
    bool mbHasCaves;
    bool mbIsPrime;
    cTkColour mMainColour;
    cTkColour mWaterColour;
    float mfCloudIntensity;
    cTkFixedString<128, char> macWeather;
    cGcCreatureRoleDataTable mCreatureRoles;
    cTkDynamicArray<cGcCreatureSpawnData> maCreatureSpawnData;
};

class cGcWonderData
{
  public:
    enum eLoadState
    {
        InvalidRecord,
        SearchingForDiscoveryData,
        GeneratingResourceData,
        LoadingResource,
        CachingResourceRenderParams,
        Complete,
        Failed,
    };

    struct sDiscoveryData
    {
        cGcDiscoverySearch *mpSearchTask;
        cGcDiscoveryData mData;
        uint64_t mUniverseAddress;
        uint64_t muSeed;
        uint64_t muFilenameHash;
        cTkFixedString<127, char> macName;
        cTkFixedString<64, char> macDiscovererName;
        cTkFixedString<3, char> mDiscovererPlatform;
        int miTimeDiscovered;
    };

    struct sPlanetData
    {
        cTkFixedString<127, char> macName;
        cGcPlanetGenerationWonderQuery mQueryResult;
    };

    struct sModelResData
    {
        cTkSmartResHandle mModelResource;
        cGcProceduralTextureManager::TaskContext *mpTC;
        bool mbFurAllowed;
        TkID<256> mResDescriptorHint;
        TkID<256> mResDescriptorFilter;
        float mfScale;
        cTkVector3 mvModelOffset;
        float mfFurScaler;
        eModelViews meModelView;
    };

    struct sCreatureData
    {
        cGcCreatureInfo mCreatureInfo;
    };

    eWonderType meWonderType;
    int miWonderCategory;
    cGcWonderRecord mRecord;
    cGcWonderData::eLoadState meLoadState;
    cGcWonderRecordCustomData mCustomData;
    cGcWonderData::sDiscoveryData mDiscoveryData;
    cGcWonderData::sPlanetData mPlanetData;
    cGcWonderData::sModelResData mModelResData;
    cGcWonderData::sCreatureData mCreatureData;
};

SKYSCRAPER_END