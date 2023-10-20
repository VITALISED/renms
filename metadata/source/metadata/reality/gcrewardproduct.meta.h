#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcRewardProduct
{
    static unsigned long long muNameHash = 0x893933F89479A7D8;
    static unsigned long long muTemplateHash = 0x45FAC0221192A379;

    cGcRealitySubstanceCategory ItemCategory;
    cGcRarity ItemRarity;
    int miItemLevel;
    cTkFixedArray<bool> maAllowedProductTypes;
    int miAmountMin;
    int miAmountMax;
}
