#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/tkblackboarddefaultvalueinteger.meta.h>
#include <metadata/simulation/tkblackboardcomparisontypeenum.meta.h>

class cGcBlackboardIntCompareDecoratorData
{
    static unsigned long long muNameHash = 0xE8C35E70B4AA8A05;
    static unsigned long long muTemplateHash = 0xB21B60117023F6EC;

    TkID<128> mKey;
    cTkBlackboardDefaultValueInteger CompareTo;
    cTkBlackboardComparisonTypeEnum Comparison;
    cTkClassPointer mOnTrue;
    cTkClassPointer mOnFalse;
}
