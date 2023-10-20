#pragma once
#include <metadata/metadata_common.h>
enum eMoveSpeed
{
    EMoveSpeed_Always = 0,
    EMoveSpeed_Walk = 1,
    EMoveSpeed_Run = 2,
}

class cGcCreatureFootParticleSingleData
{
    static unsigned long long muNameHash = 0x8CD0B53079BD773C;
    static unsigned long long muTemplateHash = 0x90B7FF87196B15B6;

    TkID<128> mEffectName;
    float mfScale;
    float mfMinCreatureSize;
    float mfMaxCreatureSize;
    eMoveSpeed MoveSpeed;
}
