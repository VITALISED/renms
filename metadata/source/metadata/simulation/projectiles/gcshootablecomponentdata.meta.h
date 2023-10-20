#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcShootableComponentData
{
    static unsigned long long muNameHash = 0x387AC5FC8E642A15;
    static unsigned long long muTemplateHash = 0x879D011DADF3E614;

    int miHealth;
    bool mbAutoAimTarget;
    bool mbPlayerOnly;
    bool mbIgnorePlayer;
    bool mbImpactShake;
    TkID<128> mImpactShakeEffect;
    cGcProjectileImpactType ForceImpactType;
    int miIncreaseWanted;
    float mfIncreaseWantedThresholdTime;
    cGcFiendCrime FiendCrimeType;
    float mfFiendCrimeModifier;
    float mfRepairTime;
    int miMinDamage;
    bool mbStaticUntilShot;
    bool mbIgnoreHitPush;
    bool mbHitEffectEnabled;
    bool mbHitEffectEntireModel;
    bool mbIsArmoured;
    bool mbCouldCountAsArmourForParent;
    bool mbIgnoreTerrainEditKills;
    cTkFixedString<32,char> macNameOverride;
    TkID<128> mRequiredTech;
    TkID<128> mDamageMultiplier;
    bool mbIsPiercable;
    bool mbIsAffectedByPiercing;
}
