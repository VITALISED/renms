#pragma once
#include <metadata/metadata_common.h>
enum ePoleCondition
{
    EPoleCondition_North = 0,
    EPoleCondition_South = 1,
}

class cGcMissionConditionNearPole
{
    static unsigned long long muNameHash = 0x5D8EF27FCF8A3E08;
    static unsigned long long muTemplateHash = 0x694723CFD80EC95E;

    ePoleCondition PoleCondition;
    float mfDistance;
}
