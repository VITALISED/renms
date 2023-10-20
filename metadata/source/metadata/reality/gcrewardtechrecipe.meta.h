#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gctechnologycategory.meta.h>

class cGcRewardTechRecipe
{
    static unsigned long long muNameHash = 0xAD73013CE22251D2;
    static unsigned long long muTemplateHash = 0x40BF19624B3A505A;

    cGcTechnologyCategory Category;
    TkID<128> mRewardGroup;
}
