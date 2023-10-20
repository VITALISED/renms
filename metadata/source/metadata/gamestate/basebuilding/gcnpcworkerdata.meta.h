#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcNPCWorkerData
{
    static unsigned long long muNameHash = 0xB88BA2B1282BE1C1;
    static unsigned long long muTemplateHash = 0x58BA4D7798D05872;

    cGcResourceElement ResourceElement;
    cTkSeed mInteractionSeed;
    bool mbHiredWorker;
    bool mbFreighterBase;
    unsigned long long mui64BaseUA;
    cTkVector4 mBaseOffset;
}
