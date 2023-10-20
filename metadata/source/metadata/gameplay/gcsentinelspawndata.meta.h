#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/robots/gcsentineltypes.meta.h>

class cGcSentinelSpawnData
{
    static unsigned long long muNameHash = 0xB8C015B2B3985468;
    static unsigned long long muTemplateHash = 0xAE9C4532C268B69A;

    cGcSentinelTypes Type;
    int miMinAmount;
    int miMaxAmount;
}
