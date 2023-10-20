#pragma once
#include <metadata/metadata_common.h>
#include <?>
enum exPersistentBaseDifficultyFlags
{
    FPersistentBaseDifficultyFlags_ = 0,
    FPersistentBaseDifficultyFlags_Locked = 1,
}

class cGcPersistentBaseDifficultyData
{
    static unsigned long long muNameHash = 0x6E51E89E7E62BE51;
    static unsigned long long muTemplateHash = 0x287BA08F43914FB5;

    cGcDifficultyPresetType DifficultyPreset;
    exPersistentBaseDifficultyFlags PersistentBaseDifficultyFlags;
}
