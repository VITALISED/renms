#pragma once
#include <metadata/metadata_common.h>
enum eEqualityEnum
{
    EEqualityEnum_Equal = 0,
    EEqualityEnum_Greater = 1,
    EEqualityEnum_Less = 2,
    EEqualityEnum_GreaterEqual = 3,
    EEqualityEnum_LessEqual = 4,
}

class cTkEqualityEnum
{
    static unsigned long long muNameHash = 0xF02414A33F663A2;
    static unsigned long long muTemplateHash = 0xF39FA9E801BF0081;

    eEqualityEnum EqualityEnum;
}
