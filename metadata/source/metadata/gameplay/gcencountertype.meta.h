#pragma once
#include <metadata/metadata_common.h>
enum eEncounterType
{
    EEncounterType_FactoryGuards = 0,
    EEncounterType_HarvesterGuards = 1,
    EEncounterType_ScrapHeap = 2,
    EEncounterType_Reward = 3,
    EEncounterType_CorruptedDroneInteract = 4,
    EEncounterType_GroundWorms = 5,
    EEncounterType_DroneHiveGuards = 6,
}

class cGcEncounterType
{
    static unsigned long long muNameHash = 0xFF746C1098C0C4DE;
    static unsigned long long muTemplateHash = 0x8E5A2CCD93F4130A;

    eEncounterType EncounterType;
}
