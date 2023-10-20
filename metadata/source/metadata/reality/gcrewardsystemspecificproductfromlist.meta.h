#pragma once
#include <metadata/metadata_common.h>

class cGcRewardSystemSpecificProductFromList
{
    static unsigned long long muNameHash = 0xA84D807B09AAC1E3;
    static unsigned long long muTemplateHash = 0xE23F1012DD607C65;

    cTkDynamicArray<TkID<128>> maProductList;
    int miAmountMin;
    int miAmountMax;
    bool mbForceSpecialMessage;
}
