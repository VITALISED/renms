#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcProjectileDataTable
{
    static unsigned long long muNameHash = 0x9439AD97E8673BC0;
    static unsigned long long muTemplateHash = 0x809F465FC44C1F18;

    cTkDynamicArray<cGcProjectileData> maTable;
    cTkDynamicArray<cGcLaserBeamData> maLasers;
}
