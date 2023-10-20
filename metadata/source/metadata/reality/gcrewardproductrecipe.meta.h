#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcrealitysubstancecategory.meta.h>
#include <metadata/reality/gcrarity.meta.h>

class cGcRewardProductRecipe
{
    static unsigned long long muNameHash = 0x27661A8643F25227;
    static unsigned long long muTemplateHash = 0x87264FFD7270DC58;

    cGcRealitySubstanceCategory ItemCatagory;
    cGcRarity ItemRarity;
    bool mbIgnoreRarity;
    int miItemLevel;
    cTkFixedArray<bool> maAllowedProductTypes;
}
