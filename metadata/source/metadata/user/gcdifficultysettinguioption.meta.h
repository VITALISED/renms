#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcDifficultySettingUIOption
{
    static unsigned long long muNameHash = 0x44DB3EF040C4347F;
    static unsigned long long muTemplateHash = 0xD72C2D74B018BA23;

    cGcDifficultySettingEnum MainOption;
    cTkDynamicArray<cGcDifficultySettingEnum> maAlsoChangeOptions;
}
