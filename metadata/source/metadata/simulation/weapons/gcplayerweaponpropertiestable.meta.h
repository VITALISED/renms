#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/weapons/gccamouflagedata.meta.h>
#include <metadata/simulation/weapons/gcplayerweaponpropertiesdata.meta.h>

class cGcPlayerWeaponPropertiesTable
{
    static unsigned long long muNameHash = 0xD90787619164B12C;
    static unsigned long long muTemplateHash = 0xAB7A82C834E35D0C;

    cGcCamouflageData CamouflageData;
    cTkFixedArray<cGcPlayerWeaponPropertiesData> maPropertiesData;
}
