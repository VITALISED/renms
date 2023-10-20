#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcMissionConditionNearestBuilding
{
    static unsigned long long muNameHash = 0x116C1EDD24B089D5;
    static unsigned long long muTemplateHash = 0xDD141FC9D7A9AB34;

    cGcBuildingClassification Building;
    float mfDistance;
    cTkDynamicArray<cGcBuildingClassification> maAdditionalBuildings;
}
