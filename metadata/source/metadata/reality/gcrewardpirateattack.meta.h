#pragma once
#include <metadata/metadata_common.h>

class cGcRewardPirateAttack
{
    static unsigned long long muNameHash = 0x76E8D6F5EA35F60C;
    static unsigned long long muTemplateHash = 0x4F15B9CE19005CC8;

    bool mbInstant;
    int miNumSquads;
    TkID<128> mAttackDefinition;
}
