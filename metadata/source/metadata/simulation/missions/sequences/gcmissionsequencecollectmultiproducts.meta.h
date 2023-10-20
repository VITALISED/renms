#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcMissionSequenceCollectMultiProducts
{
    static unsigned long long muNameHash = 0x114C4232C254BE54;
    static unsigned long long muTemplateHash = 0x87A7D49A988122DE;

    cTkFixedString<128,char> macMessage;
    cTkDynamicArray<cGcProductToCollect> maProducts;
    bool mbWaitForSelected;
    bool mbSearchCookingIngredients;
    cTkFixedString<128,char> macDebugText;
}
