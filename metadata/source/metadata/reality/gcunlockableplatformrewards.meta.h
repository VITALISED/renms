#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcunlockableplatformreward.meta.h>

class cGcUnlockablePlatformRewards
{
    static unsigned long long muNameHash = 0x973B907FEECDAE57;
    static unsigned long long muTemplateHash = 0x407D00A5607E9DC;

    cTkDynamicArray<cGcUnlockablePlatformReward> maTable;
}
