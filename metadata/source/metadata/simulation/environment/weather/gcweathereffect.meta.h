#pragma once
#include <metadata/metadata_common.h>
#include <?>
enum eSpawnConditions
{
    ESpawnConditions_Anytime = 0,
    ESpawnConditions_DuringStorm = 1,
    ESpawnConditions_AtNight = 2,
    ESpawnConditions_NotInStorm = 3,
    ESpawnConditions_AtNightNotInStorm = 4,
}
enum eWeatherEffectBehaviour
{
    EWeatherEffectBehaviour_Static = 0,
    EWeatherEffectBehaviour_Wander = 1,
    EWeatherEffectBehaviour_ChasePlayer = 2,
}
enum eWeatherEffectSpawnType
{
    EWeatherEffectSpawnType_Single = 0,
    EWeatherEffectSpawnType_Cluster = 1,
    EWeatherEffectSpawnType_Patch = 2,
}
#include <?>

class cGcWeatherEffect
{
    static unsigned long long muNameHash = 0x419E50F8E497D496;
    static unsigned long long muTemplateHash = 0xFBBD7E692B03EE3;

    TkID<128> mId;
    TkID<256> mOSDMessage;
    cTkDynamicArray<cGcWeightedFilename> maEffects;
    eSpawnConditions SpawnConditions;
    int miMaxHazardsOfThisTypeActive;
    TkID<128> mForcedOnByHazard;
    TkID<128> mBlockedByCluster;
    eWeatherEffectBehaviour WeatherEffectBehaviour;
    eWeatherEffectSpawnType WeatherEffectSpawnType;
    bool mbRandomRotationAroundUp;
    float mfMinSpawnScale;
    float mfMaxSpawnScale;
    int miSpawnAttemptsPerRegion;
    float mfSpawnChancePerSecondPerAttempt;
    float mfChanceOfPlanetBeingExtreme;
    float mfSpawnChancePerSecondExtreme;
    float mfMinSpawnDistance;
    float mfMaxSpawnDistance;
    float mfMinLifetime;
    float mfMaxLifetime;
    float mfFadeoutStart;
    bool mbFadeoutVisuals;
    bool mbFadeoutAudio;
    cGcAudioWwiseEvents Audio;
    cTkFixedString<128,char> macImpactGift;
    float mfImpactGiftChance;
    float mfClusterSpawnChance;
    float mfClusterMinLifetime;
    float mfClusterMaxLifetime;
    float mfPatchMaxTimeSpawnOffset;
    float mfPatchMinRadius;
    float mfPatchMaxRadius;
    int miPatchMinSpawns;
    int miPatchMaxSpawns;
    float mfPatchScaling;
    float mfMoveSpeed;
    float mfWanderMinRadius;
    float mfWanderMaxRadius;
    float mfWanderMinArcDeg;
    float mfWanderMaxArcDeg;
    cTkClassPointer mEffectData;
}
