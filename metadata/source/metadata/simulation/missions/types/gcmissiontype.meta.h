#pragma once
#include <metadata/metadata_common.h>
enum eMissionType
{
    EMissionType_SpaceCombat = 0,
    EMissionType_GroundCombat = 1,
    EMissionType_Research = 2,
    EMissionType_MissingPerson = 3,
    EMissionType_Repair = 4,
    EMissionType_Cargo = 5,
    EMissionType_Piracy = 6,
    EMissionType_Photo = 7,
    EMissionType_Feeding = 8,
    EMissionType_Planting = 9,
    EMissionType_Construction = 10,
}

class cGcMissionType
{
    static unsigned long long muNameHash = 0x881C97F393A2FB50;
    static unsigned long long muTemplateHash = 0x764185355E2FCC4B;

    eMissionType MissionType;
}
