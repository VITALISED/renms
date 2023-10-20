#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcGalaxyInfoIcons
{
    static unsigned long long muNameHash = 0x1DE42844C3529A0B;
    static unsigned long long muTemplateHash = 0x7D3DB4E4A1077EA3;

    cTkFixedArray<cTkTextureResource> maRaceIcons;
    cTkFixedArray<cTkTextureResource> maEconomyIcons;
    cTkTextureResource EconomyTechNotInstalledIcon;
    cTkFixedArray<cTkTextureResource> maWealthIcons;
    cTkFixedArray<cTkTextureResource> maConflictIcons;
    cTkTextureResource ConflictTechNotInstalledIcon;
    cTkTextureResource WarpIcon;
    cTkTextureResource WarpErrorIcon;
    cTkTextureResource WarpTechNotInstalledIcon;
}
