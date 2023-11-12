#pragma once

#include <skyscraper.h>

#include <graphics/2d/GcColourPalette.h>
#include <simulation/solarsystem/buildings/GcPlanetBuildingGenerator.h>
#include <toolkit/utilities/UnorderedMapHashes.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/random/TkPersonalRNG.h>

#include <simulation/ecosystem/gccreaturegenerationarchetypes.meta.h>
#include <simulation/ecosystem/gccreaturegenerationdata.meta.h>
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
#include <simulation/solarsystem/planet/gcweathercoloursettings.meta.h>
#include <toolkit/voxel/generator/tkvoxelgeneratorsettingsarray.meta.h>

SKYSCRAPER_BEGIN

class cGcPlanetGenerator
{
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
    cTkVector<unsigned __int64> mExternalObjectListFilenamesHash;
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