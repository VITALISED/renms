#pragma once
#include <metadata/metadata_common.h>

class cTkRotationComponentData
{
    static unsigned long long muNameHash = 0xB808E542DB69E5FE;
    static unsigned long long muTemplateHash = 0x409E58991CD749D8;

    float mfSpeed;
    cTkVector3 mAxis;
    bool mbAlwaysUpdate;
    int miSyncGroup;
}
