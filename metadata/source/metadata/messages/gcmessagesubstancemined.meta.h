#pragma once
#include <metadata/metadata_common.h>

class cGcMessageSubstanceMined
{
    static unsigned long long muNameHash = 0x2BC6A341CEA135BF;
    static unsigned long long muTemplateHash = 0xE41F59D24256A6FE;

    int miAmount;
    TkID<128> mSubstance;
}
