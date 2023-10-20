#pragma once
#include <metadata/metadata_common.h>
enum eRequiredSentinelLevel
{
    ERequiredSentinelLevel_None = 0,
    ERequiredSentinelLevel_Low = 1,
    ERequiredSentinelLevel_Default = 2,
    ERequiredSentinelLevel_Aggressive = 3,
}

class cGcMissionConditionSentinelLevel
{
    static unsigned long long muNameHash = 0xB45DF78C123D703E;
    static unsigned long long muTemplateHash = 0xAF04E8DDD3E651FB;

    eRequiredSentinelLevel RequiredSentinelLevel;
}
