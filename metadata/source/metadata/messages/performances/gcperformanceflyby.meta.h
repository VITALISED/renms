#pragma once
#include <metadata/metadata_common.h>

class cGcPerformanceFlyby
{
    static unsigned long long muNameHash = 0x5384022399CAF09;
    static unsigned long long muTemplateHash = 0x5AD90024C7365E53;

    float mfLength;
    float mfOffset;
    bool mbLocked;
    float mfLockOffset;
    float mfLockTime;
    float mfLockSpeed;
}
