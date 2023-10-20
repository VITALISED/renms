#pragma once
#include <metadata/metadata_common.h>
enum eDifficultyOptionGroup
{
    EDifficultyOptionGroup_Survival = 0,
    EDifficultyOptionGroup_Crafting = 1,
    EDifficultyOptionGroup_Combat = 2,
    EDifficultyOptionGroup_Ease = 3,
}

class cGcDifficultyOptionGroups
{
    static unsigned long long muNameHash = 0x48BADFDDC969F879;
    static unsigned long long muTemplateHash = 0x8F65E41AFFAD2F8C;

    eDifficultyOptionGroup DifficultyOptionGroup;
}
