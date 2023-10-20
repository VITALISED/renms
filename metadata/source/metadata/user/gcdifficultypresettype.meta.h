#pragma once
#include <metadata/metadata_common.h>
enum eDifficultyPresetType
{
    EDifficultyPresetType_Invalid = 0,
    EDifficultyPresetType_Custom = 1,
    EDifficultyPresetType_Normal = 2,
    EDifficultyPresetType_Creative = 3,
    EDifficultyPresetType_Relaxed = 4,
    EDifficultyPresetType_Survival = 5,
    EDifficultyPresetType_Permadeath = 6,
}

class cGcDifficultyPresetType
{
    static unsigned long long muNameHash = 0x5401230062A6D869;
    static unsigned long long muTemplateHash = 0x3EFADB6935A48DD6;

    eDifficultyPresetType DifficultyPresetType;
}
