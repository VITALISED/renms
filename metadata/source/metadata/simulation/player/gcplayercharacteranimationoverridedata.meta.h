#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/player/gcplayercharacterikoverridedata.meta.h>

class cGcPlayerCharacterAnimationOverrideData
{
    static unsigned long long muNameHash = 0x78D4180CEDFDC316;
    static unsigned long long muTemplateHash = 0xE1E8F5FEA4CE3E2D;

    TkID<128> mAnimName;
    cGcPlayerCharacterIKOverrideData Data;
}
