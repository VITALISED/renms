#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/solarsystem/planet/gcminingsubstancedata.meta.h>
#include <metadata/simulation/solarsystem/planet/gcplanetwaterdata.meta.h>
#include <metadata/simulation/environment/gcexternalobjectlistoptions.meta.h>
#include <metadata/simulation/solarsystem/planet/gcweatherweightings.meta.h>
#include <metadata/simulation/solarsystem/planet/gcbiomecloudsettings.meta.h>
#include <metadata/simulation/solarsystem/planet/gcterraincontrols.meta.h>
#include <metadata/simulation/solarsystem/planet/gcscreenfilteroption.meta.h>

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
