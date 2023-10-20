#pragma once
#include <metadata/metadata_common.h>
enum eConditionTest
{
    EConditionTest_AnyFalse = 0,
    EConditionTest_AllFalse = 1,
    EConditionTest_AnyTrue = 2,
    EConditionTest_AllTrue = 3,
}

class cGcMissionConditionTest
{
    static unsigned long long muNameHash = 0xC1BECA54193DD3FB;
    static unsigned long long muTemplateHash = 0x30816B6D0D302F6E;

    eConditionTest ConditionTest;
}
