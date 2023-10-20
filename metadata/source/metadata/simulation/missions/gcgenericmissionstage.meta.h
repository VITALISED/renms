#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcGenericMissionStage
{
    static unsigned long long muNameHash = 0xE8F2F4C4A2F01AD1;
    static unsigned long long muTemplateHash = 0x20B4998D273351AF;

    cTkDynamicArray<cGcGenericMissionVersionProgress> maVersions;
    cTkClassPointer mStage;
}
