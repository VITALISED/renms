#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tktextureresource.meta.h>
#include <metadata/reality/gcplanetresourceiconlookup.meta.h>
#include <metadata/reality/gcrealityicon.meta.h>

class cGcRealityIconTable
{
    static unsigned long long muNameHash = 0x2A28407EECDFA4CC;
    static unsigned long long muTemplateHash = 0x697FC0BB94821DD3;

    cTkFixedArray<cTkTextureResource> maHazardIcons;
    cTkFixedArray<cTkTextureResource> maHazardIconsHUD;
    cTkFixedArray<cTkTextureResource> maSubstanceCategoryIcons;
    cTkFixedArray<cTkTextureResource> maProductCategoryIcons;
    cTkFixedArray<cTkTextureResource> maMissionFactionIcons;
    cTkFixedArray<cTkTextureResource> maBinocularDiscoveryIcons;
    cTkFixedArray<cTkTextureResource> maDiscoveryPageTradingIcons;
    cTkFixedArray<cTkTextureResource> maDiscoveryPageConflictIcons;
    cTkFixedArray<cTkTextureResource> maDiscoveryPageRaceIcons;
    cTkTextureResource DiscoveryPageTradingUnknown;
    cTkTextureResource DiscoveryPageConflictUnknown;
    cTkTextureResource DiscoveryPageRaceUnknown;
    cTkDynamicArray<cGcPlanetResourceIconLookup> maTerrainIconLookups;
    cTkDynamicArray<cGcPlanetResourceIconLookup> maPlanetResourceIconLookups;
    cTkDynamicArray<cTkTextureResource> maRepairTechIcons;
    cTkFixedArray<cTkTextureResource> maGameIcons;
    cTkDynamicArray<cGcRealityIcon> maMissionDetailIcons;
    cTkFixedArray<cTkTextureResource> maDifficultyPresetIcons;
    cTkFixedArray<cTkTextureResource> maDifficultyUIOptionIcons;
    cTkFixedArray<cTkTextureResource> maOptionsUIHeaderIcons;
    cTkFixedArray<cTkTextureResource> maInventoryFilterIcons;
}
