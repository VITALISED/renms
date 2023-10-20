#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcrealitysubstancecategory.meta.h>
#include <metadata/reality/gcrarity.meta.h>

class cGcSubstanceAmount
{
    static unsigned long long muNameHash = 0x87586DC48C5F162B;
    static unsigned long long muTemplateHash = 0x7D55DCD74C988166;

    int miAmountMin;
    int miAmountMax;
    TkID<128> mSpecific;
    TkID<128> mSpecificSecondary;
    cGcRealitySubstanceCategory Category;
    cGcRarity Rarity;
}
