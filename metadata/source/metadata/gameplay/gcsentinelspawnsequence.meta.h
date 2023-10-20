#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gameplay/gcsentinelspawnsequencestep.meta.h>

class cGcSentinelSpawnSequence
{
    static unsigned long long muNameHash = 0xA8EFE022A74D3291;
    static unsigned long long muTemplateHash = 0x75437857CB76C97E;

    cTkDynamicArray<cGcSentinelSpawnSequenceStep> maWaves;
}
