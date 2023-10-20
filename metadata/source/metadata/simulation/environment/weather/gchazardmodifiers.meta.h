#pragma once
#include <metadata/metadata_common.h>
enum eHazardModifier
{
    EHazardModifier_Temperature = 0,
    EHazardModifier_Toxicity = 1,
    EHazardModifier_Radiation = 2,
    EHazardModifier_LifeSupportDrain = 3,
    EHazardModifier_Gravity = 4,
}

class cGcHazardModifiers
{
    static unsigned long long muNameHash = 0x8D86E8499B88B845;
    static unsigned long long muTemplateHash = 0x17F28D0AC13F281E;

    eHazardModifier HazardModifier;
}
