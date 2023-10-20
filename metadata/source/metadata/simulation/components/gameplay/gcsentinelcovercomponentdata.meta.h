#pragma once
#include <metadata/metadata_common.h>

class cGcSentinelCoverComponentData
{
    static unsigned long long muNameHash = 0xE1F35851383555E2;
    static unsigned long long muTemplateHash = 0x4EAD1F33EAED6BC9;

    float mfHealthPercLostPerSecMin;
    float mfHealthPercLostPerSecMax;
    TkID<128> mSpawnEffectId;
    TkID<128> mDestroyEffectId;
    cTkFixedString<32,char> macEffectLocator;
    cTkFixedArray<TkID<128>> maCoverStateAnims;
}
