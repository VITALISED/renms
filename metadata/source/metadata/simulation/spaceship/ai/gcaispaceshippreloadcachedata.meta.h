#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcrealitycommonfactions.meta.h>
#include <metadata/simulation/spaceship/ai/gcaispaceshiproles.meta.h>
#include <metadata/simulation/gcspaceshipclasses.meta.h>
#include <metadata/reality/gcfrigateclass.meta.h>

class cGcAISpaceshipPreloadCacheData
{
    static unsigned long long muNameHash = 0x74723646531009E2;
    static unsigned long long muTemplateHash = 0x4339BE7A302ECC05;

    cGcRealityCommonFactions Faction;
    cGcAISpaceshipRoles ShipRole;
    cGcSpaceshipClasses ShipClass;
    cGcFrigateClass FrigateClass;
    cTkSeed mSeed;
}
