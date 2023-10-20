#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcBiomeData
{
    static unsigned long long muNameHash = 0x2FD5560612237D4D;
    static unsigned long long muTemplateHash = 0xA369C87DCDDF335B;

    cTkFixedString<128,char> macTextureFile;
    cTkFixedString<128,char> macOverlayFile;
    cTkFixedString<128,char> macTileTypesFile;
    cTkFixedString<128,char> macColourPaletteFile;
    cTkFixedString<128,char> macLegacyColourPaletteFile;
    cGcMiningSubstanceData MiningSubstance1;
    cGcMiningSubstanceData MiningSubstance2;
    cGcMiningSubstanceData MiningSubstance3;
    float mfFuelMultiplier;
    cGcPlanetWaterData Water;
    cTkDynamicArray<cGcExternalObjectListOptions> maExternalObjectLists;
    cTkFixedArray<cGcWeatherWeightings> maWeatherOptions;
    cTkVector2 mWeatherChangeTime;
    cGcBiomeCloudSettings CloudSettings;
    cGcTerrainControls Terrain;
    cTkDynamicArray<cGcScreenFilterOption> maFilterOptions;
    TkID<256> mFloraLifeLocID;
}
