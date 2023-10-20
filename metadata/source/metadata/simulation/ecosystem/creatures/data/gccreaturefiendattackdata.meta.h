#pragma once
#include <metadata/metadata_common.h>

class cGcCreatureFiendAttackData
{
    static unsigned long long muNameHash = 0x41B161469E53B05E;
    static unsigned long long muTemplateHash = 0xD4A53608778A385B;

    float mfNearDist;
    float mfFarDist;
    float mfModifyDistanceForHeight;
    TkID<128> mSpitAnim;
    int miSpitAnimFrame;
    cTkFixedString<64,char> macSpitJoint;
    TkID<128> mSpitProjectile;
    bool mbAllowSpit;
    float mfDelayBetweenSpitAttacks;
    bool mbAllowPounce;
    float mfDelayBetweenPounceAttacks;
    cTkFixedString<64,char> macAttackLight;
    float mfIdleLightIntensity;
    float mfAttackLightIntensity;
    int miMinFlurryHits;
    int miMaxFlurryHits;
    float mfRoarChanceOnHit;
    float mfRoarChanceOnMiss;
    float mfStartDamageTime;
    float mfTurnToFaceTime;
}
