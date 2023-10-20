#pragma once
#include <metadata/metadata_common.h>

class cGcItemCostData
{
    static unsigned long long muNameHash = 0xA3976E1971095FC4;
    static unsigned long long muTemplateHash = 0xD34B7AB023B43319;

    TkID<128> mID;
    float mfCost;
    float mfMinCost;
    float mfMaxCost;
    float mfChangePerSale;
}
