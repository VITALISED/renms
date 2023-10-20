#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tkmodelresource.meta.h>
#include <metadata/audio/gcaudiowwiseevents.meta.h>
#include <metadata/simulation/particles/gcdebrisdata.meta.h>

class cGcExplosionData
{
    static unsigned long long muNameHash = 0x8318BC4815036659;
    static unsigned long long muTemplateHash = 0xBEE64C539734FC9B;

    TkID<128> mId;
    cTkModelResource Model;
    cGcAudioWwiseEvents AudioEvent;
    cTkDynamicArray<cGcDebrisData> maDebris;
    float mfLife;
    float mfScale;
    float mfDistanceScale;
    float mfDistanceScaleMax;
    bool mbCamShake;
    bool mbCamShakeSpaceScale;
    float mfShakeStrengthModifier;
    TkID<128> mShakeId;
    bool mbAllowTriggerActionOnDebris;
    bool mbAllowShootableDebris;
    bool mbAllowDestructableDebris;
    float mfMaxSpawnDistance;
    float mfCamShakeCustomMaxDistance;
}
