#pragma once
#include <metadata/metadata_common.h>
enum eSyncBufferType
{
    ESyncBufferType_Refiner = 0,
    ESyncBufferType_Example1 = 1,
    ESyncBufferType_Example2 = 2,
    ESyncBufferType_Example3 = 3,
}

class cGcSynchronisedBufferType
{
    static unsigned long long muNameHash = 0x8796DE5FDA34BEB;
    static unsigned long long muTemplateHash = 0x1BC9D9FA9864C6EE;

    eSyncBufferType SyncBufferType;
}
