/**
 * @file GcPlanetGenerator.h
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

#include <graphics/2d/GcColourPalette.h>
#include <simulation/solarsystem/buildings/GcPlanetBuildingGenerator.h>
#include <simulation/solarsystem/planet/GcPlanetCommon.h>
#include <toolkit/utilities/UnorderedMapHashes.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/random/TkPersonalRNG.h>

#include <graphics/2d/gcpalettelist.meta.h>
#include <simulation/ecosystem/gccreaturegenerationarchetypes.meta.h>
#include <simulation/ecosystem/gccreaturegenerationdata.meta.h>
#include <simulation/environment/gcobjectspawndata.meta.h>
#include <simulation/environment/gcterraintexturesettings.meta.h>
#include <simulation/environment/spawn/gcselectableobjecttable.meta.h>
#include <simulation/environment/weather/gcweathereffecttable.meta.h>
#include <simulation/environment/weather/gcweatherproperties.meta.h>
#include <simulation/environment/weather/gcweathertable.meta.h>
#include <simulation/solarsystem/gcbiomelistperstartype.meta.h>
#include <simulation/solarsystem/planet/gcbiomedata.meta.h>
#include <simulation/solarsystem/planet/gcbiomefilelist.meta.h>
#include <simulation/solarsystem/planet/gcexternalobjectlist.meta.h>
#include <simulation/solarsystem/planet/gcoverlaytexture.meta.h>
#include <simulation/solarsystem/planet/gcspawndensitylist.meta.h>
#include <simulation/solarsystem/planet/gcterraintexture.meta.h>
#include <simulation/solarsystem/planet/gctiletypesets.meta.h>
#include <simulation/solarsystem/planet/gcwatercoloursettinglist.meta.h>
#include <simulation/solarsystem/planet/gcweathercoloursettinglist.meta.h>
#include <simulation/solarsystem/planet/gcweathercoloursettings.meta.h>
#include <toolkit/voxel/generator/tkvoxelgeneratorsettingsarray.meta.h>

SKYSCRAPER_BEGIN

class cGcPlanetGenerator
{
  public:
    cGcPlanetBuildingGenerator mBuildingGenerator;
    cGcCreatureGenerationData *mpCreatureGenerationData;
    cGcCreatureGenerationArchetypes *mpCreatureGenerationArchetypes;
    cGcSpawnDensityList *mpSpawnDensityList;
    cGcSelectableObjectTable *mpSelectableObjectTable;
    cGcBiomeFileList *mpBiomeFiles;
    cGcBiomeListPerStarType *mpBiomeListPerStarType;
    cTkFixedArray<cTkVector<cGcBiomeData *>, 16> mapBiomes;
    cTkFixedArray<cTkVector<cGcTileTypeSets *>, 16> mapTileTypeSets;
    cTkFixedArray<cTkVector<cGcTerrainTexture *>, 16> mapTerrainTextures;
    cTkFixedArray<cTkVector<cGcOverlayTexture *>, 16> mapOverlayTextures;
    cTkVector<cTkFixedString<256, char>> mExternalObjectListFilenames;
    cTkVector<uint64_t> mExternalObjectListFilenamesHash;
    cTkVector<cGcExternalObjectList *> mExternalObjectLists;
    cGcWeatherTable *mpWeatherList;
    cTkVector<cGcWeatherProperties *> mWeatherData;
    cTkVoxelGeneratorSettingsArray *mpaTerrainData;
    cGcWeatherColourSettings *mpDayWeatherColours;
    cGcWeatherColourSettings *mpDuskWeatherColours;
    cGcWeatherColourSettings *mpNightWeatherColours;
    cGcWaterColourSettingList *mpWaterColours;
    cGcWeatherEffectTable *mpWeatherEffects;
    cGcWeatherEffectTable *mpWeatherHazards;
    cGcColourPalette mPalette;
    cGcLegacyColourPalette mLegacyPalette;
    bool mbFirstGenerate;
    cTkPersonalRNG mRNG;
    robin_hood::detail::Table<
        false, 80, cTkFixedString<128, char>, int, UnorderedMapHashes::Hash<cTkFixedString<128, char>>,
        std::equal_to<cTkFixedString<128, char>>>
        mStringCountHash;
    cTkVector<cTkSmartResHandle> mHeavyAirResources;
};

SKYSCRAPER_END