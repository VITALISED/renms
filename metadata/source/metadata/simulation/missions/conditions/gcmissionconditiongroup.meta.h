#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcMissionConditionGroup
{
    static unsigned long long muNameHash = 0x3820751A1F86DB6;
    static unsigned long long muTemplateHash = 0x66D761828B0FCBBD;

    cGcMissionConditionTest ConditionTest;
    cTkDynamicArray<cTkClassPointer> maConditions;
}
