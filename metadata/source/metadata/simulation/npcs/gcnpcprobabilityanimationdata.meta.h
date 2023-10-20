#pragma once
#include <metadata/metadata_common.h>
enum eAnimationIntensity
{
    EAnimationIntensity_Low = 0,
    EAnimationIntensity_Medium = 1,
    EAnimationIntensity_High = 2,
    EAnimationIntensity_None = 3,
}
#include <?>

class cGcNPCProbabilityAnimationData
{
    static unsigned long long muNameHash = 0x6ECD1E12A5E7A194;
    static unsigned long long muTemplateHash = 0xF23879D569337348;

    TkID<128> mName;
    float mfProbability;
    eAnimationIntensity AnimationIntensity;
    cTkDynamicArray<cGcAlienRace> maExcludeRace;
    cTkDynamicArray<TkID<128>> maTags;
}
