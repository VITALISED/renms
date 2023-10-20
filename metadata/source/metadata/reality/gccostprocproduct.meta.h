#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcproceduralproductcategory.meta.h>
#include <metadata/reality/gcrarity.meta.h>

class cGcCostProcProduct
{
    static unsigned long long muNameHash = 0x2D9EAD5F5CF5EAF6;
    static unsigned long long muTemplateHash = 0x3C8D0F7D4CC9EBCC;

    cGcProceduralProductCategory Type;
    bool mbCareAboutRarity;
    cGcRarity Rarity;
    int miFreighterPasswordIndex;
}
