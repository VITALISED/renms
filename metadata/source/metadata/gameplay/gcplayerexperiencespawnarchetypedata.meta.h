#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcPlayerExperienceSpawnArchetypeData
{
    static unsigned long long muNameHash = 0x3D6AF30F10DB0EAA;
    static unsigned long long muTemplateHash = 0x4905A18AC39B865;

    TkID<128> mId;
    TkID<128> mGenerateResource;
    cGcCreatureTypes Type;
    float mfScale;
    float mfScaleVariation;
    TkID<128> mAppearAnim;
    float mfSpeedMultiplier;
    int miHealthOverride;
    TkID<128> mDamageOverride;
    TkID<128> mDamageReceivedMultiplier;
    float mfSpawnDistOverride;
    float mfDespawnDistOverride;
    TkID<128> mBehaviourTreeOverride;
    cTkDynamicArray<cTkClassPointer> maBehaviourOverrides;
    cTkDynamicArray<cTkClassPointer> maBlackboardValues;
}
