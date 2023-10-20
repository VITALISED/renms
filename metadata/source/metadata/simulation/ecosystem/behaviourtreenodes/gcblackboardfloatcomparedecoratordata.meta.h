#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/tkblackboarddefaultvaluefloat.meta.h>
#include <metadata/simulation/tkblackboardcomparisontypeenum.meta.h>

class cGcBlackboardFloatCompareDecoratorData
{
    static unsigned long long muNameHash = 0xC8C9C8064A5C8F6E;
    static unsigned long long muTemplateHash = 0x8A949772CCF6EBE3;

    TkID<128> mKey;
    cTkBlackboardDefaultValueFloat CompareTo;
    cTkBlackboardComparisonTypeEnum CompareBlackboardValueType;
    cTkClassPointer mOnTrue;
    cTkClassPointer mOnFalse;
}
