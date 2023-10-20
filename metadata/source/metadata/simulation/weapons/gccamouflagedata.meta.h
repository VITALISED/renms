#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tkmaterialresource.meta.h>

class cGcCamouflageData
{
    static unsigned long long muNameHash = 0x4548C9A8732E084E;
    static unsigned long long muTemplateHash = 0x89FA7100747D117F;

    cTkMaterialResource CamouflageMaterial;
    float mfDissolveTime;
    float mfDissolveTimeVR;
    float mfFadeOutTime;
    float mfFadeInTime;
    float mfLowQualityFresnelModifier;
    float mfLowQualityBrightnessMultiplier;
}
