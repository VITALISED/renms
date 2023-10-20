#pragma once
#include <metadata/metadata_common.h>

class cGcSentinelResource
{
    static unsigned long long muNameHash = 0x68945B9C7D77B53;
    static unsigned long long muTemplateHash = 0xDC5A48941FFF8450;

    cTkFixedString<128,char> macResource;
    int miBaseHealth;
    int miHealthIncreasePerLevel;
    float mfRepairTime;
    float mfRepairThreshold;
}
