#pragma once
#include <metadata/metadata_common.h>

class cGcMissileComponentData
{
    static unsigned long long muNameHash = 0x342DA8D8BE5A9CE3;
    static unsigned long long muTemplateHash = 0x804C8875458D6D60;

    TkID<128> mExplosion;
    float mfNoTargetLife;
    TkID<128> mTrail;
}
