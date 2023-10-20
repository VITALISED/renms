#pragma once
#include <metadata/metadata_common.h>
#include <metadata/audio/gcaudiowwiseevents.meta.h>
#include <metadata/reality/stats/gcstatstypes.meta.h>

class cGcCombatEffectData
{
    static unsigned long long muNameHash = 0x6D475929020A9A4D;
    static unsigned long long muTemplateHash = 0x167EFA6C04E11F70;

    TkID<128> mDamageId;
    TkID<128> mParticlesId;
    cGcAudioWwiseEvents StartAudio;
    cGcAudioWwiseEvents EndAudio;
    cGcStatsTypes Stat;
    bool mbOverrideDamageNumberData;
    float mfDamageMergeTime;
    float mfDamageTimeBetweenNumbers;
    float mfDamageMinDistance;
}
