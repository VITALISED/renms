#pragma once
#include <metadata/metadata_common.h>

class cGcBaseBuildingEntryCosts
{
    static unsigned long long muNameHash = 0x2229006A022A6430;
    static unsigned long long muTemplateHash = 0xEE84845AB3262787;

    TkID<128> mID;
    float mfActive0AverageFrameTimeCost;
    float mfActive1AverageFrameTimeCost;
    int miActiveTotalNodes;
    int miActivePhysicsComponents;
    float mfInactive0AverageFrameTimeCost;
    float mfInactive1AverageFrameTimeCost;
    int miInactiveTotalNodes;
    int miInactivePhysicsComponents;
}
