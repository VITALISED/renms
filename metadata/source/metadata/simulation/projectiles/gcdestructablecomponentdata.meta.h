#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcDestructableComponentData
{
    static unsigned long long muNameHash = 0xE24B3D78ED0634BD;
    static unsigned long long muTemplateHash = 0x1A7644BF35CD170;

    TkID<128> mExplosion;
    float mfExplosionScale;
    bool mbExplosionScaleToBounds;
    bool mbOnlyExplodeSelf;
    TkID<128> mVehicleDestroyEffect;
    TkID<128> mTriggerAction;
    int miIncreaseWanted;
    bool mbIncreaseFiendWanted;
    float mfIncreaseFiendWantedChance;
    bool mbNotifyEncounter;
    TkID<128> mLootReward;
    int miLootRewardAmountMin;
    int miLootRewardAmountMax;
    bool mbCanDestroyFromStoredInteraction;
    cTkDynamicArray<cGcSubstanceAmount> maGivesSubstances;
    cGcStatsEnum StatToTrack;
    TkID<128> mGivesReward;
    TkID<128> mPirateSystemAltReward;
    bool mbRewardIfDestroyedByOther;
    bool mbHideReward;
    TkID<256> mOverrideRewardLoc;
    cTkDynamicArray<cGcRewardMissionOverride> maRewardOverrideTable;
    bool mbActivateLocatorsFromRarity;
    cTkFixedArray<TkID<128>> maRarityLocators;
    bool mbUseSystemColorsForTexture;
    bool mbRemoveModel;
    bool mbHideModel;
    cTkModelResource DestroyedModel;
    bool mbDestroyedModelUsesScale;
    bool mbDestroyedModelCollidesWithEverything;
    float mfDestroyForce;
    float mfDestroyForceRadius;
    TkID<128> mDestroyEffect;
    bool mbDestroyEffectOnSurface;
    TkID<128> mDestroyEffectPoint;
    float mfDestroyEffectTime;
    bool mbDestroyEffectMatrices;
    TkID<128> mAreaDamage;
    bool mbShowInteract;
    bool mbHideInteractWhenAllArmourDestroyed;
    float mfShowInteractRange;
    bool mbGrenadeSingleHit;
    cTkDynamicArray<cGcLootProbability> maLootItems;
}
