#pragma once
#include <metadata/metadata_common.h>
enum eDynamicResScalingAggressiveness
{
    EDynamicResScalingAggressiveness_Moderate = 0,
    EDynamicResScalingAggressiveness_Balanced = 1,
    EDynamicResScalingAggressiveness_Aggressive = 2,
}

class cTkDynamicResScalingSettings
{
    static unsigned long long muNameHash = 0x4ECB5D79E2F5CD94;
    static unsigned long long muTemplateHash = 0xBD988A745376C6E4;

    float mfLowestDynamicResScalingFactor;
    eDynamicResScalingAggressiveness DynamicResScalingAggressiveness;
}
