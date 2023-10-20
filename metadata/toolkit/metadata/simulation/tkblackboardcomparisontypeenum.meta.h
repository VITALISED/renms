#pragma once
#include <metadata/metadata_common.h>
enum eComparisonType
{
    EComparisonType_Equal = 0,
    EComparisonType_NotEqual = 1,
    EComparisonType_GreaterThan = 2,
    EComparisonType_GreaterThanEqual = 3,
    EComparisonType_LessThan = 4,
    EComparisonType_LessThanEqual = 5,
}

class cTkBlackboardComparisonTypeEnum
{
    static unsigned long long muNameHash = 0x2412AB95A81851E8;
    static unsigned long long muTemplateHash = 0x42A415F679C0191E;

    eComparisonType ComparisonType;
}
