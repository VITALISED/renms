#pragma once
#include <metadata/metadata_common.h>
enum eBroadcastLevel
{
    EBroadcastLevel_Scene = 0,
    EBroadcastLevel_LocalModel = 1,
    EBroadcastLevel_Local = 2,
}

class cGcBroadcastLevel
{
    static unsigned long long muNameHash = 0x788C67D6B87C29E3;
    static unsigned long long muTemplateHash = 0x3BCCD8E73F2DF785;

    eBroadcastLevel BroadcastLevel;
}
