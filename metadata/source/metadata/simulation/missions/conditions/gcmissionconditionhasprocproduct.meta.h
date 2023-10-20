#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcproceduralproductcategory.meta.h>

class cGcMissionConditionHasProcProduct
{
    static unsigned long long muNameHash = 0x754263974A1E2442;
    static unsigned long long muTemplateHash = 0x748CFB4E68C05944;

    cGcProceduralProductCategory ProcProduct;
    bool mbForceSearchFreighterAndChests;
    bool mbSearchEveryShip;
}
