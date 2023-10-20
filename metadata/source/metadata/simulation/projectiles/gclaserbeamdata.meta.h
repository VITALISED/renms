#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcLaserBeamData
{
    static unsigned long long muNameHash = 0x1AA966F8BA4E3153;
    static unsigned long long muTemplateHash = 0xF076564F20014911;

    TkID<128> mId;
    cTkFixedString<128,char> macBeamFile;
    cTkFixedString<128,char> macBeamCoreFile;
    float mfWidth;
    float mfHitWidth;
    float mfPulseFrequency;
    float mfPulseAmplitude;
    float mfStartTime;
    float mfEndTime;
    cGcAudioWwiseEvents AudioStart;
    cGcAudioWwiseEvents AudioStop;
    cGcAudioWwiseEvents AudioOverheat;
    int miDefaultDamage;
    float mfExtraPlayerDamage;
    cGcDamageType DamageType;
    float mfCriticalHitModifier;
    TkID<128> mPlayerDamage;
    TkID<128> mImpactEffect;
    cTkDynamicArray<cGcProjectileImpactData> maImpacts;
    float mfHitRate;
    bool mbSingleHit;
    float mfRagdollPush;
    float mfPhysicsPush;
    float mfMiningHitRate;
    bool mbHasLight;
    bool mbCanMine;
    bool mbApplyCombatLevelMultipliers;
    float mfDroneImpulse;
    float mfPiercingDamagePercentage;
    float mfLightIntensity;
    cTkColour mLightColour;
    cTkColour mColour;
    cTkVector3 mImpactOffset;
    cTkDynamicArray<cGcImpactCombatEffectData> maCombatEffectsOnImpact;
    cTkDynamicArray<cGcCombatEffectDamageMultiplier> maCombatEffectDamageMultipliers;
}
