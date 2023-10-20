#pragma once
#include <metadata/metadata_common.h>
enum eDifficultySettingType
{
    EDifficultySettingType_Toggle = 0,
    EDifficultySettingType_OptionList = 1,
}

class cGcDifficultySettingType
{
    static unsigned long long muNameHash = 0xFD8A2B15F29A9D3C;
    static unsigned long long muTemplateHash = 0x9B70ED031EA53160;

    eDifficultySettingType DifficultySettingType;
}
