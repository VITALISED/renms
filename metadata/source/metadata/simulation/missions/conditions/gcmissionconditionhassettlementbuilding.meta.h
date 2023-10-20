#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/environment/gcbuildingclassification.meta.h>

class cGcMissionConditionHasSettlementBuilding
{
    static unsigned long long muNameHash = 0xE47353C2B9EE4F60;
    static unsigned long long muTemplateHash = 0xC59E1A4E7BC0F022;

    cGcBuildingClassification BuildingClass;
    bool mbRequireComplete;
}
