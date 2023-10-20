#pragma once
#include <metadata/metadata_common.h>

class cTkLODSettingsData
{
    static unsigned long long muNameHash = 0xA0C253D5A5EF8A51;
    static unsigned long long muTemplateHash = 0x4C8D2C5D711DF5C7;

    cTkFixedArray<float> maLODAdjust;
    cTkFixedArray<int> maImposterOverrideRange;
    cTkFixedArray<int> maMaxObjectDistanceOverride;
    cTkFixedArray<int> maRegionLODHiddenRanges;
    cTkFixedArray<int> maRegionLODRadius;
    bool mbEnableOctahedralImposters;
    bool mbViewImpostersFromSpace;
    int miNumberOfImposterViews;
    int miImposterResolutionMultiplier;
    int miAsteroidCountMultiplier;
    int miAsteroidDividerMultiplier;
    float mfAsteroidFadeRangeMultiplier;
    int miMaxAsteroidGenerationPerFrame;
    int miMaxAsteroidGenerationPerFramePulseJump;
}
