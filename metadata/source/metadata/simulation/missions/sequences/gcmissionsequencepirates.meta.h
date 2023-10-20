#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequencePirates
{
    static unsigned long long muNameHash = 0x9166CF1D0ED63522;
    static unsigned long long muTemplateHash = 0xCC277D2F01D5CC7A;

    bool mbScanCargo;
    int miNumSquads;
    TkID<128> mAttackDefinition;
    TkID<256> mRewardMessageOverride;
    bool mbSilent;
    float mfDistanceOverride;
    bool mbForceSpawn;
    cTkFixedString<128,char> macDebugText;
}
