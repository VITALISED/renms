#pragma once
#include <metadata/metadata_common.h>
#include <?>
enum eHitType
{
    EHitType_Shootable = 0,
    EHitType_Terrain = 1,
    EHitType_Generic = 2,
}
#include <?>
#include <?>

class cGcMessageProjectileImpact
{
    static unsigned long long muNameHash = 0x7EBC25FE326CF24B;
    static unsigned long long muTemplateHash = 0xB7A09FEF0808E840;

    TkID<128> mId;
    int miDamage;
    cGcDamageType Type;
    bool mbCritical;
    bool mbIneffective;
    bool mbLaserHeatBoost;
    TkHandle mNode;
    eHitType HitType;
    cTkVector3 mPosLocal;
    cTkVector3 mPosOffset;
    cTkDynamicArray<cGcImpactCombatEffectData> maCombatEffects;
    cTkDynamicArray<cGcCombatEffectDamageMultiplier> maDamageMultipliers;
}
