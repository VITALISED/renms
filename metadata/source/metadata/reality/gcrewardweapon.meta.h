#pragma once
#include <metadata/metadata_common.h>

class cGcRewardWeapon
{
    static unsigned long long muNameHash = 0xDF91F2B5F746FB61;
    static unsigned long long muTemplateHash = 0x851F4BA80F69B14B;

    int miItemLevel;
    bool mbMarkInteractionComplete;
    bool mbUsePlanetSeed;
    bool mbForceFixed;
    bool mbRequeueInteraction;
    bool mbReinteractOnDecline;
    bool mbOnlyUseNextInteractionOnSuccess;
    float mfSecretPoolChance;
}
