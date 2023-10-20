#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gameplay/gcsentinelspawnsequencestep.meta.h>

class cGcSentinelSpawnNamedSequence
{
    static unsigned long long muNameHash = 0x77C3FF3D0260D091;
    static unsigned long long muTemplateHash = 0x7311F1B4C666160C;

    TkID<128> mId;
    cTkDynamicArray<cGcSentinelSpawnSequenceStep> maWaves;
}
