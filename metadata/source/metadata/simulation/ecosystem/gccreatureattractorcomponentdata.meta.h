#pragma once
#include <metadata/metadata_common.h>
enum eAttractorType
{
    EAttractorType_Food = 0,
    EAttractorType_Harvester = 1,
}

class cGcCreatureAttractorComponentData
{
    static unsigned long long muNameHash = 0x2F505B818F28B755;
    static unsigned long long muTemplateHash = 0x5920DDCD5658E969;

    bool mbUniversal;
    bool mbStatic;
    float mfArriveDist;
    eAttractorType AttractorType;
}
