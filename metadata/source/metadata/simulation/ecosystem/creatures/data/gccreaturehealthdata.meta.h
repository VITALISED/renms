#pragma once
#include <metadata/metadata_common.h>

class cGcCreatureHealthData
{
    static unsigned long long muNameHash = 0x8554BC1ADD990AB6;
    static unsigned long long muTemplateHash = 0xD3C5FD5ACDF2D4F6;

    TkID<128> mHurtAnim;
    TkID<128> mDeathAnim;
    TkID<128> mDeathEffect;
    TkID<128> mHurtAudio;
    TkID<128> mDeathAudio;
    bool mbDespawnOnDeath;
    cTkDynamicArray<TkID<256>> maDespawnOnDeathDescriptors;
}
