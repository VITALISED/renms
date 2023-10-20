#pragma once
#include <metadata/metadata_common.h>

class cGcDoShipFlybyClose
{
    static unsigned long long muNameHash = 0x9C74A74AB0211EF6;
    static unsigned long long muTemplateHash = 0xF3BB8C227063A312;

    float mfLockOffset;
    float mfLockTime;
    float mfLockSpread;
    bool mbStayCloseAtLowSpeed;
    bool mbHailingBehaviour;
}
