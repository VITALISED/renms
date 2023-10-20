#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/environment/gcbuildingclassification.meta.h>

class cGcBuildingClusterLayoutEntry
{
    static unsigned long long muNameHash = 0x3C79A95C7D8D0B89;
    static unsigned long long muTemplateHash = 0x98AEE6A8EB8E27D5;

    cGcBuildingClassification Building;
    float mfProbability;
    int miMin;
    int miMax;
    bool mbFacesCentre;
}
