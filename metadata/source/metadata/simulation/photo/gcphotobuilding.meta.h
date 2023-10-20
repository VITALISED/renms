#pragma once
#include <metadata/metadata_common.h>
enum ePhotoBuildingType
{
    EPhotoBuildingType_Shelter = 0,
    EPhotoBuildingType_Abandoned = 1,
    EPhotoBuildingType_Shop = 2,
    EPhotoBuildingType_Outpost = 3,
    EPhotoBuildingType_RadioTower = 4,
    EPhotoBuildingType_Observatory = 5,
    EPhotoBuildingType_Depot = 6,
    EPhotoBuildingType_Monolith = 7,
    EPhotoBuildingType_Factory = 8,
    EPhotoBuildingType_Portal = 9,
    EPhotoBuildingType_Ruin = 10,
    EPhotoBuildingType_MissionTower = 11,
    EPhotoBuildingType_LargeBuilding = 12,
}

class cGcPhotoBuilding
{
    static unsigned long long muNameHash = 0x2535C1B3F76633D;
    static unsigned long long muTemplateHash = 0x27529A5C3BAF0D45;

    ePhotoBuildingType PhotoBuildingType;
}
