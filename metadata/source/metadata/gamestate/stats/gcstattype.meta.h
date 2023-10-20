#pragma once
#include <metadata/metadata_common.h>
enum eStatType
{
    EStatType_Int = 0,
    EStatType_Float = 1,
    EStatType_AvgRate = 2,
}

class cGcStatType
{
    static unsigned long long muNameHash = 0xC9590B318F3C4D2;
    static unsigned long long muTemplateHash = 0xC6D7101DE9D4929B;

    eStatType StatType;
}
