#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/robots/gcsentineltypes.meta.h>

class cGcSentinelRobotComponentData
{
    static unsigned long long muNameHash = 0xC3E852EF937E74B5;
    static unsigned long long muTemplateHash = 0x55375AD08ED4684E;

    TkID<128> mId;
    cGcSentinelTypes Type;
}
