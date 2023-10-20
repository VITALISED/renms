#pragma once
#include <metadata/metadata_common.h>
enum eCloudiness
{
    ECloudiness_CloudyWithClearSpells = 0,
    ECloudiness_ClearWithCloudySpells = 1,
}

class cGcPlanetCloudProperties
{
    static unsigned long long muNameHash = 0x96E42AD217EA55B2;
    static unsigned long long muTemplateHash = 0x9F922C89C96A1B4F;

    cTkSeed mSeed;
    float mfCoverage1;
    float mfCoverage2;
    float mfCoverage3;
    float mfOffset1;
    float mfOffset2;
    float mfOffset3;
    cTkVector2 mCoverExtremes;
    float mfRatio;
    float mfRateOfChange;
    float mfSecondaryRateOfChange;
    eCloudiness Cloudiness;
}
