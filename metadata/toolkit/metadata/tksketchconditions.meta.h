#pragma once
#include <metadata/metadata_common.h>
enum eCondition
{
    ECondition_Equal = 0,
    ECondition_NotEqual = 1,
    ECondition_Greater = 2,
    ECondition_Less = 3,
    ECondition_GreaterEqual = 4,
    ECondition_LessEqual = 5,
}

class cTkSketchConditions
{
    static unsigned long long muNameHash = 0x42F1604851DA7F02;
    static unsigned long long muTemplateHash = 0x1B9710CC397E213C;

    eCondition Condition;
}
