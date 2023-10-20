#pragma once
#include <metadata/metadata_common.h>

class cGcInventoryGenerationBaseStatDataEntry
{
    static unsigned long long muNameHash = 0xBE33B4E320477672;
    static unsigned long long muTemplateHash = 0x843EA26DF15EC0E4;

    TkID<128> mBaseStatID;
    float mfMin;
    float mfMax;
    float mfMinFixedAdd;
    float mfMaxFixedAdd;
}
