#pragma once
#include <metadata/metadata_common.h>

class cGcRewardExchangeProduct
{
    static unsigned long long muNameHash = 0x2F9B8F940B001C76;
    static unsigned long long muTemplateHash = 0x786394FFE4D8E05;

    TkID<128> mIDToGive;
    TkID<128> mIDToTake;
    int miAmountToGiveMin;
    int miAmountToGiveMax;
    int miAmountToTakeMax;
    bool mbHideNewProduct;
    bool mbForceSpecialMessage;
}
