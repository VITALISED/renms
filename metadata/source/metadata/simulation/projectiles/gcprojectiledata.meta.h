#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>
enum exBehaviourFlags
{
    FBehaviourFlags_ = 0,
    FBehaviourFlags_DestroyTerrain = 1,
    FBehaviourFlags_DestroyAsteroids = 2,
    FBehaviourFlags_GatherResources = 4,
    FBehaviourFlags_Homing = 8,
    FBehaviourFlags_HomingLaser = 16,
    FBehaviourFlags_ScareCreatures = 32,
    FBehaviourFlags_ExplosionForce = 64,
}
enum eClass
{
    EClass_Player = 0,
    EClass_PlayerShip = 1,
    EClass_Ship = 2,
    EClass_Robot = 3,
}
#include <?>
#include <?>

class cGcProjectileData
{
    static unsigned long long muNameHash = 0x98B648B5C054B7F7;
    static unsigned long long muTemplateHash = 0x37F1B214BC74234A;

    TkID<128> mId;
    cGcResourceElement Model;
    cGcAudioWwiseEvents FireAudioEvent;
    cGcAudioWwiseEvents ChargedFireAudioEvent;
    cGcAudioWwiseEvents OverheatAudioEvent;
    float mfScale;
    bool mbIsAutonomous;
    bool mbApplyCombatLevelMultipliers;
    float mfRadius;
    float mfCapsuleHeight;
    float mfDefaultSpeed;
    float mfGravity;
    float mfLife;
    float mfOffset;
    float mfRagdollPush;
    float mfPhysicsPush;
    float mfDroneImpulse;
    int miDefaultDamage;
    float mfExtraPlayerDamage;
    cGcDamageType DamageType;
    int miDefaultBounces;
    float mfBounceMaxSpeed;
    float mfBounceDamping;
    float mfBounceFinalStopTime;
    bool mbHitOnBounce;
    TkID<128> mPlayerDamage;
    float mfCriticalHitModifier;
    float mfPiercingDamagePercentage;
    bool mbUseCustomBulletData;
    cGcProjectileLineData CustomBulletData;
    bool mbUseDamageNumberData;
    float mfDamageImpactMergeTime;
    float mfDamageImpactTimeBetweenNumbers;
    float mfDamageImpactMinDistance;
    cTkColour mColour;
    bool mbOverrideLightColour;
    cTkColour mLightColour;
    exBehaviourFlags BehaviourFlags;
    eClass Class;
    TkID<128> mDefaultImpact;
    TkID<128> mCriticalImpact;
    cTkDynamicArray<cGcProjectileImpactData> maImpacts;
    cTkVector3 mImpactOffset;
    cTkDynamicArray<cGcImpactCombatEffectData> maCombatEffectsOnImpact;
}
