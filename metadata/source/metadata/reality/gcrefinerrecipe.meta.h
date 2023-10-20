#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcrefinerrecipeelement.meta.h>

class cGcRefinerRecipe
{
    static unsigned long long muNameHash = 0x309D52938C546138;
    static unsigned long long muTemplateHash = 0xE6B0B3233CA22BC9;

    TkID<256> mId;
    TkID<256> mRecipeType;
    TkID<256> mRecipeName;
    float mfTimeToMake;
    bool mbCooking;
    cGcRefinerRecipeElement Result;
    cTkDynamicArray<cGcRefinerRecipeElement> maIngredients;
}
