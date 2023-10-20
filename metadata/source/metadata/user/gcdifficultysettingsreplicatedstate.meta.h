#pragma once
#include <metadata/metadata_common.h>
#include <metadata/user/gcdifficultypresettype.meta.h>

class cGcDifficultySettingsReplicatedState
{
    static unsigned long long muNameHash = 0xAE3AC9A3967B8330;
    static unsigned long long muTemplateHash = 0x782FBE9D9BD9D467;

    bool mbIsPermadeath;
    cGcDifficultyPresetType Preset;
    cGcDifficultyPresetType RoundedDownPreset;
    cGcDifficultyPresetType EasiestUsedPreset;
    cGcDifficultyPresetType HardestUsedPreset;
    bool mbIsLocked;
}
