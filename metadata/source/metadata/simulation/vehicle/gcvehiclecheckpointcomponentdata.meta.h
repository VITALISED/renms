#pragma once
#include <metadata/metadata_common.h>
enum eCheckpointType
{
    ECheckpointType_Checkpoint = 0,
    ECheckpointType_Start = 1,
}

class cGcVehicleCheckpointComponentData
{
    static unsigned long long muNameHash = 0xF8F75E88F695BE94;
    static unsigned long long muTemplateHash = 0x998ECAC2D8278FE3;

    eCheckpointType CheckpointType;
    eRaceType RaceType;
    float mfRadius;
}
