#pragma once
#include <metadata/metadata_common.h>

class cGcMissionConditionWaitForTime
{
    static unsigned long long muNameHash = 0x9387E17DE22981F4;
    static unsigned long long muTemplateHash = 0xBEE1E91CA9DFF2FD;

    unsigned long long mui64WaitTimeInSeconds;
    bool mbThisConditionWillSetMissionUserDataIsThatOk;
}
