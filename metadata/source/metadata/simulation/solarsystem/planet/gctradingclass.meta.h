#pragma once
#include <metadata/metadata_common.h>
enum eTradingClass
{
    ETradingClass_Mining = 0,
    ETradingClass_HighTech = 1,
    ETradingClass_Trading = 2,
    ETradingClass_Manufacturing = 3,
    ETradingClass_Fusion = 4,
    ETradingClass_Scientific = 5,
    ETradingClass_PowerGeneration = 6,
}

class cGcTradingClass
{
    static unsigned long long muNameHash = 0x9E3AE80CF84700A6;
    static unsigned long long muTemplateHash = 0x9BB54B9C170BF01C;

    eTradingClass TradingClass;
}
