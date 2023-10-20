#pragma once
#include <metadata/metadata_common.h>
enum eBuildingSystemType
{
    EBuildingSystemType_Normal = 0,
    EBuildingSystemType_AbandonedSystem = 1,
}

class cGcBuildingSystemTypeEnum
{
    static unsigned long long muNameHash = 0xB4AC262382F5910E;
    static unsigned long long muTemplateHash = 0xD529A470EDDCF735;

    eBuildingSystemType BuildingSystemType;
}
