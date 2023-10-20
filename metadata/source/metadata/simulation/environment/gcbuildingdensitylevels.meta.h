#pragma once
#include <metadata/metadata_common.h>
enum eBuildingDensity
{
    EBuildingDensity_Dead = 0,
    EBuildingDensity_Low = 1,
    EBuildingDensity_Mid = 2,
    EBuildingDensity_Full = 3,
    EBuildingDensity_Weird = 4,
    EBuildingDensity_HalfWeird = 5,
}

class cGcBuildingDensityLevels
{
    static unsigned long long muNameHash = 0x43EB5D40DE6AD28E;
    static unsigned long long muTemplateHash = 0x84AE876DD70E705A;

    eBuildingDensity BuildingDensity;
}
