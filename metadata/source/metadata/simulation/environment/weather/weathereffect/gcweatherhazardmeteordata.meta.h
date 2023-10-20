#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tkmodelresource.meta.h>

class cGcWeatherHazardMeteorData
{
    static unsigned long long muNameHash = 0x89A5F03E5191DE14;
    static unsigned long long muTemplateHash = 0x2D274E737EA18C13;

    cTkModelResource IndicatorDecal;
    cTkModelResource StaticDecal;
    cTkModelResource Meteor;
    cTkModelResource ImpactEffect;
    cTkModelResource ImpactExplode;
    float mfMinRadius;
    float mfMaxRadius;
    float mfDecalFullGrowthProgress;
    float mfNumFlashes;
    float mfFlashStartProgress;
    float mfEarliestImpact;
    float mfEarliestImpactFirstInstance;
    float mfStormDuration;
    float mfSpeed;
    int miMinMeteors;
    int miMaxMeteors;
    TkID<128> mShakeID;
    TkID<128> mImpactParticle;
    TkID<128> mDamageID;
    float mfFullDamageRadius;
    float mfDamageRadius;
}
