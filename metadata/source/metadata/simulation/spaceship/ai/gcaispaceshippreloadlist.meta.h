#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcrealitycommonfactions.meta.h>
#include <metadata/simulation/spaceship/ai/gcaispaceshippreloadcachedata.meta.h>

class cGcAISpaceshipPreloadList
{
    static unsigned long long muNameHash = 0xC546551B048ACC33;
    static unsigned long long muTemplateHash = 0x4531553B105E462;

    cGcRealityCommonFactions Faction;
    cTkDynamicArray<cGcAISpaceshipPreloadCacheData> maCache;
}
