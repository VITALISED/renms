#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcrefinerrecipe.meta.h>

class cGcRecipeTable
{
    static unsigned long long muNameHash = 0xB05B3758665D56DE;
    static unsigned long long muTemplateHash = 0x484B8B55E2AECD4F;

    cTkDynamicArray<cGcRefinerRecipe> maTable;
}
