#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcWeatherHazardLightningData
{
    static unsigned long long muNameHash = 0xD85F7F00F1F64BD1;
    static unsigned long long muTemplateHash = 0xC42BA76B22AFE894;

    cTkModelResource IndicatorDecal;
    cTkModelResource StaticDecal;
    float mfMinRadius;
    float mfMaxRadius;
    float mfDecalFullGrowthProgress;
    float mfNumFlashes;
    float mfFlashStartProgress;
    float mfEarliestImpact;
    float mfEarliestImpactFirstInstance;
    float mfStormDuration;
    int miMinStrikes;
    int miMaxStrikes;
    TkID<128> mShakeID;
    TkID<128> mImpactParticle;
    TkID<128> mDamageID;
    float mfFullDamageRadius;
    float mfDamageRadius;
}
