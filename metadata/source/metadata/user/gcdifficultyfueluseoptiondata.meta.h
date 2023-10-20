#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcDifficultyFuelUseOptionData
{
    static unsigned long long muNameHash = 0x15072D4E11178622;
    static unsigned long long muTemplateHash = 0xDDB5F6B408399220;

    float mfMultiplier;
    cTkDynamicArray<cGcDifficultyFuelUseTechOverride> maTechOverrides;
}
