#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/environment/gcbuildingclusterlayoutentry.meta.h>

class cGcBuildingClusterLayout
{
    static unsigned long long muNameHash = 0x8A9F48B72B9E5588;
    static unsigned long long muTemplateHash = 0x1633F75A5B07F722;

    TkID<128> mID;
    float mfRelativeProbability;
    cTkDynamicArray<cGcBuildingClusterLayoutEntry> maClusterBuildings;
    int miAlignmentSteps;
    float mfAlignmentJitter;
}
