#pragma once
#include <metadata/metadata_common.h>
enum eDifficultySettingEditability
{
    EDifficultySettingEditability_FullyEditable = 0,
    EDifficultySettingEditability_IncreaseOnly = 1,
    EDifficultySettingEditability_DecreaseOnly = 2,
    EDifficultySettingEditability_LockedVisible = 3,
    EDifficultySettingEditability_LockedHidden = 4,
}

class cGcDifficultySettingEditability
{
    static unsigned long long muNameHash = 0x215639935EEC2DFE;
    static unsigned long long muTemplateHash = 0xCEE62246904BB76D;

    eDifficultySettingEditability DifficultySettingEditability;
}
