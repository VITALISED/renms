#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcrealitycommonfactions.meta.h>
#include <metadata/simulation/spaceship/ai/gcaispaceshiproles.meta.h>

class cGcButtonSpawnOffset
{
    static unsigned long long muNameHash = 0x42A6687A1AF1F42A;
    static unsigned long long muTemplateHash = 0x31748E19E8D4B7B8;

    float mfAngleMin;
    float mfAngleMax;
    float mfOffset;
    float mfSpacing;
    float mfFacing;
    int miCount;
    cGcRealityCommonFactions Faction;
    cGcAISpaceshipRoles ShipRole;
}
