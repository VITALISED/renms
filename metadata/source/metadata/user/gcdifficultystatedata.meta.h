#pragma once
#include <metadata/metadata_common.h>
#include <metadata/user/gcdifficultypresettype.meta.h>
#include <metadata/user/gcdifficultysettingsdata.meta.h>

class cGcDifficultyStateData
{
    static unsigned long long muNameHash = 0x814973F0DDEB62C8;
    static unsigned long long muTemplateHash = 0x336C024001BFA1B3;

    cGcDifficultyPresetType Preset;
    cGcDifficultyPresetType EasiestUsedPreset;
    cGcDifficultyPresetType HardestUsedPreset;
    cGcDifficultySettingsData Settings;
}
