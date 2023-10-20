#pragma once
#include <metadata/metadata_common.h>

class cGcDiscoveryWorth
{
    static unsigned long long muNameHash = 0xC9D7FFE72FBDED51;
    static unsigned long long muTemplateHash = 0x98C51EF5B4DB8CD4;

    cTkFixedArray<int> maRecord;
    cTkFixedArray<int> maOnScan;
    int miMission;
}
